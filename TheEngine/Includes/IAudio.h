#pragma once
#include <string>
namespace Engine2
{
	class IAudio
	{
	public:
		virtual ~IAudio() = default;
		virtual void Init() = 0;
		virtual size_t LoadMusic(const std::string& filename) = 0;
		virtual size_t LoadSound(const std::string& filename) = 0;
		virtual void PlayMusic(size_t id) = 0;
		virtual void PlayMusic(size_t id, int loop) = 0;
		virtual void PlaySFX(size_t id) = 0;
		virtual void PlaySFX(size_t id, int loop) = 0;
		virtual void PauseMusic() = 0;
		virtual void StopMusic() = 0;
		virtual void ResumeMusic() = 0;
		virtual void SetGlobalVolume(int volume) = 0;
		virtual void SetMusicVolume(int volume) = 0;
		virtual void SetVolume(size_t soundId, int volume) = 0;
		virtual void ShutDown() = 0;
	};
}


