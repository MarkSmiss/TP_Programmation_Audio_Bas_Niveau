#include <string>
#include <algorithm>
#pragma once

inline std::string GetAudioExtension(const char* _fileName)
{
	std::string path = _fileName ? _fileName : "";

	size_t pos = path.find_last_of('.');

	if (pos == std::string::npos)
	{
		return "";
	}

	std::string extension = path.substr(pos);

	std::transform(extension.begin(), extension.end(), extension.begin(),
		[](unsigned char _c)
		{
			return static_cast<char>(std::tolower(_c));
		});

	return extension;
}

	int Play(const char * fileName);
	int Pause(const char* fileName);
	int Resume(const char* fileName);
	int Stop(const char* fileName);
	int ToggleLoop(const char* _fileName, bool _loopEnabled);
	int SetVolume(const char* _fileName, float _percentVolume);
	int init();



