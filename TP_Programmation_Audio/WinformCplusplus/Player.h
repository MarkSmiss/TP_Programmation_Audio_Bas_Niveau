#include <string>
#include <algorithm>
#include <msclr\marshal_cppstd.h>
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

inline std::string GetAudioExtension(System::String^ _fileName)
{
	std::string path = !System::String::IsNullOrEmpty(_fileName) ?
		msclr::interop::marshal_as<std::string>(_fileName) : "";

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

inline System::String^ GetAudioName(System::String^ _fileName)
{
	System::String^ path = _fileName ? _fileName : "";

	int lastSlash = path->LastIndexOfAny(gcnew array<wchar_t>{ '/', '\\' });
	int startPos = (lastSlash == -1) ? 0 : lastSlash + 1;

	int dotPos = path->LastIndexOf('.');

	if (dotPos == -1 || dotPos < startPos)
	{
		return path->Substring(startPos);
	}

	return path->Substring(startPos, dotPos - startPos);
}

inline std::string ManagedToNativeString(System::String^ managedString)
{
	if (System::String::IsNullOrEmpty(managedString))
	{
		return "";
	}

	return msclr::interop::marshal_as<std::string>(managedString);
}

int Play(const char* fileName);
int Pause(const char* fileName);
int Resume(const char* fileName);
int Stop(const char* fileName);
int ToggleLoop(const char* _fileName, bool _loopEnabled);

bool IsAudioFinished(std::string _fileName);
void AddToPlaylist(System::String^ _fileName);
bool PlayNextFromPlaylist();
std::string GetPlayingAudioName();

int SetVolume(const char* _fileName, float _percentVolume);
int init();



