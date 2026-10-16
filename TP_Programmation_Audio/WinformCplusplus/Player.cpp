#include "Player.h"
#include <string>
#include <limits>
#include"Framework.h"
#include <map>
#include <vector>
#include <list>

#include <al.h>
#include <alc.h>
#include <vorbis/vorbisfile.h>
#include <Windows.h>

std::map<std::string, std::pair<ALuint, ALuint>> sound_sources;
std::list<std::pair<std::string, std::string>> sound_names;

std::string playingSongName = std::string();

int init() {
	// Initialize Framework
	ALFWInit();
	if (!ALFWInitOpenAL())
	{
		ALFWShutdown();
		return 0;
	}

	return 1;
}

bool LoadOggToBuffer(const char* _fileName, ALuint _buffer)
{
	OggVorbis_File oggFile{};

	if (ov_fopen(_fileName, &oggFile) != 0)
	{
		System::Windows::Forms::MessageBox::Show("unable to open file");
		return false;
	}

	vorbis_info* info = ov_info(&oggFile, -1);

	if (info == nullptr ||
		(info->channels != 1 && info->channels != 2) ||
		info->rate <= 0 ||
		info->rate > (std::numeric_limits<ALsizei>::max)())
	{
		ov_clear(&oggFile);
		System::Windows::Forms::MessageBox::Show("nullptr");
		return false;
	}

	const ALenum format = (info->channels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;

	const ALsizei sampleRate = static_cast<ALsizei>(info->rate);

	std::vector<char> pcm;
	char chunk[4096];

	int bitstream = 0;
	long bytesRead = 0;

	while ((bytesRead = ov_read(&oggFile, chunk, sizeof(chunk), 0, 2, 1, &bitstream)) > 0)
	{
		if (bytesRead > 0 &&
			pcm.size() + static_cast<size_t>(bytesRead) >
			static_cast<size_t>((std::numeric_limits<ALsizei>::max)()))
		{
			ov_clear(&oggFile);
			System::Windows::Forms::MessageBox::Show("WHILE");
			return false;
		}

		pcm.insert(pcm.end(), chunk, chunk + bytesRead);
	}

	ov_clear(&oggFile);

	if (bytesRead < 0 || pcm.empty())
	{
		// Erreur de codage
		System::Windows::Forms::MessageBox::Show("bytesRead < 0 || pcm.empty()");
		return false;
	}

	alBufferData(_buffer,
		format,
		pcm.data(),
		static_cast<ALsizei>(pcm.size()),
		sampleRate);

	ALenum err = alGetError();
	if (err != AL_NO_ERROR)
	{
		System::Windows::Forms::MessageBox::Show("Err open al code : " + err.ToString());
		return false;
	}

	return true;
}

bool CheckFileNameError(const char* _fileName)
{
	if (_fileName == nullptr || *_fileName == '\0')
	{
		return true;
	}
	return false;
}

int Play(const char* fileName)
{
	if (CheckFileNameError(fileName))
	{
		return -1;
	}

	std::string extension = GetAudioExtension(fileName);

	auto existing = sound_sources.find(fileName);

	if (existing != sound_sources.end())
	{
		Stop(fileName);
	}

	Stop(playingSongName.c_str());

	ALuint      uiBuffer = 0;
	ALuint      uiSource = 0;

	// Generate an AL Buffer
	alGenBuffers(1, &uiBuffer);

	bool loaded = false;

	if (extension == ".wav")
	{
		// Load Wave file into OpenAL Buffer
		loaded = ALFWLoadWaveToBuffer((const char*)fileName, uiBuffer);

		if (!loaded)
		{
			ALFWprintf("Failed to load %s\n", fileName);
			return -1;
		}

	}
	else if (extension == ".ogg")
	{
		loaded = LoadOggToBuffer(fileName, uiBuffer);

		if (!loaded)
		{
			System::Windows::Forms::MessageBox::Show("Failed to load ogg sa mere");

			ALFWprintf("Failed to load %s\n", fileName);
			return -1;
		}
	}
	else
	{
		System::Windows::Forms::MessageBox::Show("Unknown format.");
	}
	if (!loaded)
	{
		alDeleteBuffers(1, &uiBuffer);
		return -1;
	}

	// Generate a Source to playback the Buffer
	alGenSources(1, &uiSource);

	// Attach Source to Buffer
	alSourcei(uiSource, AL_BUFFER, uiBuffer);

	//pour boucler un son
	//alSourcei(uiSource, AL_LOOPING, AL_TRUE);

	//sound_sources[fileName] = &uiSource;
	// Play Source
	sound_sources[fileName] = std::pair<ALuint, ALuint>(uiSource, uiBuffer);
	playingSongName = fileName;
	alSourcePlay(uiSource);

	//do
	//{
	//	Sleep(100);
	//	ALFWprintf(".");
	//	// Get Source State
	//	alGetSourcei(uiSource, AL_SOURCE_STATE, &iState);
	//} while (iState == AL_PLAYING);


	// Clean up by deleting Source(s) and Buffer(s)

	/*alSourceStop(uiSource);
	alDeleteSources(1, &uiSource);
	alDeleteBuffers(1, &uiBuffer);

	ALFWShutdownOpenAL();

	ALFWShutdown();*/

	return alGetError() == AL_NO_ERROR ? 0 : -1;
}

int Pause(const char* fileName)
{
	auto it = sound_sources.find(fileName);
	if (it != sound_sources.end())
	{
		alSourcePause(it->second.first);
		return 0;
	}
	return -1;
}

int Resume(const char* fileName)
{
	auto it = sound_sources.find(fileName);
	if (it != sound_sources.end())
	{
		alSourcePlay(it->second.first);
		return 0;
	}
	return -1;
}

int Stop(const char* fileName)
{
	if (CheckFileNameError(fileName)) return -1;

	auto it = sound_sources.find(fileName);
	if (it != sound_sources.end())
	{
		ALuint source = it->second.first;
		ALuint buffer = it->second.second;

		alSourceStop(source);
		alDeleteSources(1, &source);
		alDeleteBuffers(1, &buffer);

		sound_sources.erase(it);
		return 0;
	}
	return -1;
}

int ToggleLoop(const char* _fileName, bool _loopEnabled)
{
	auto it = sound_sources.find(_fileName);
	if (it != sound_sources.end())
	{
		alSourcei(it->second.first, AL_LOOPING, _loopEnabled ? AL_TRUE : AL_FALSE);
		return 0;
	}
	return -1;
}

int SetVolume(const char* _fileName, float _percentVolume)
{
	auto it = sound_sources.find(_fileName);

	if (it == sound_sources.end())
	{
		return -1;
	}

	ALuint source = it->second.first;

	if (_percentVolume < 0.0f)
	{
		_percentVolume = 0.0f;
	}

	if (_percentVolume > 1.0f)
	{
		_percentVolume = 1.0f;
	}

	alSourcef(source, AL_GAIN, _percentVolume);

	return alGetError() == AL_NO_ERROR ? 0 : -1;
}

bool IsAudioFinished(std::string _fileName)
{
	auto it = sound_sources.find(_fileName);
	if (it == sound_sources.end())
	{
		return true;
	}

	ALint state = 0;
	alGetSourcei(it->second.first, AL_SOURCE_STATE, &state);
	return (state == AL_STOPPED);
}

void AddToPlaylist(System::String^ _fileName)
{
	std::string fileName = ManagedToNativeString(_fileName);
	std::string audioName = ManagedToNativeString(GetAudioName(_fileName));
	std::pair<std::string, std::string> pair =
	{
		fileName,
		audioName
	};
	sound_names.push_back(pair);
}

bool PlayNextFromPlaylist()
{
	if (!sound_names.empty())
	{
		Play(sound_names.front().first.c_str());
		sound_names.pop_front();
		return true;
	}

	return false;
}

std::string GetPlayingAudioName()
{
	return playingSongName;
}
