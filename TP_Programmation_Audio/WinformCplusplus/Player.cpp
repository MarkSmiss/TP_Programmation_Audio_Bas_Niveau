#include "Player.h"
#include <string>
#include <limits>
#include"Framework.h"
#include <map>
#include <vector>

#include <al.h>
#include <alc.h>
#include <vorbis/vorbisfile.h>
#include <Windows.h>

std::map<std::string, std::pair<ALuint, ALuint>> sound_sources;

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
		return false;
	}

	vorbis_info* info = ov_info(&oggFile, -1);

	if (info == nullptr ||
		(info->channels != 1 && info->channels != 2) ||
		info->rate <= 0 ||
		info->rate > (std::numeric_limits<ALsizei>::max)())
	{
		ov_clear(&oggFile);
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
			return false;
		}

		pcm.insert(pcm.end(), chunk, chunk + bytesRead);
	}

	ov_clear(&oggFile);

	if (bytesRead < 0 || pcm.empty())
	{
		// Erreur de codage
		return false;
	}

	alBufferData(_buffer,
		format,
		pcm.data(),
		static_cast<ALsizei>(pcm.size()),
		sampleRate);

	return alGetError() == AL_NO_ERROR;
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
	alSourcei(uiSource, AL_LOOPING, AL_TRUE);

	//sound_sources[fileName] = &uiSource;
	// Play Source
	sound_sources[fileName] = std::pair<ALuint, ALuint>(uiSource, uiBuffer);
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
	ALuint* source = &sound_sources[fileName].first;
	if (source)
	{
		alSourcePause(*source);
		return 0;
	}
	return -1;
}

int Resume(const char* fileName)
{
	ALuint* source = &sound_sources[fileName].first;
	if (source)
	{
		alSourcePlay(*source);
		return 0;
	}
	return -1;
}

int Stop(const char* fileName)
{
	ALuint* source = &sound_sources[fileName].first;
	ALuint* buffer = &sound_sources[fileName].second;
	if (source)
	{
		alSourceStop(*source);

		alDeleteSources(1, source);
		alDeleteBuffers(1, buffer);

		sound_sources.erase(fileName);
		return 0;
	}
	return -1;
}