#include "Player.h"
#include"Framework.h"
#include <map>

std::map<std::string, std::pair<ALuint, ALuint>> sound_sources;

int init() {
	// Initialize Framework
	ALFWInit();
	if (!ALFWInitOpenAL())
	{
		ALFWShutdown();
		return 0;
	}
}

int Play(const char* fileName)
{
	ALuint      uiBuffer;
	ALuint      uiSource;
	ALint       iState;

	// Generate an AL Buffer
	alGenBuffers(1, &uiBuffer);

	// Load Wave file into OpenAL Buffer
	if (!ALFWLoadWaveToBuffer((char*)fileName, uiBuffer))
	{
		ALFWprintf("Failed to load %s\n", fileName);
	}

	// Generate a Source to playback the Buffer
	alGenSources(1, &uiSource);

	// Attach Source to Buffer
	alSourcei(uiSource, AL_BUFFER, uiBuffer);
	//pour boucler un son
	alSourcei(uiSource, AL_LOOPING, 1);

	//sound_sources[fileName] = &uiSource;
	// Play Source
	alSourcePlay(uiSource);
	sound_sources[fileName] = std::pair<ALuint, ALuint>(uiSource, uiBuffer);
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

	return 0;
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