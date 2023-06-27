#pragma once
#include "IAudio.h"
#include <string>
#include <map>
struct Mix_Chunk;
typedef struct _Mix_Music Mix_Music;
namespace TomNook
{
	class SDLMixer : public IAudio
	{

	public:

		virtual ~SDLMixer() = default;
		virtual void Init() override;
		virtual size_t LoadMusic(const std::string& filename) override;
		virtual size_t LoadSound(const std::string& filename) override;
		virtual void PlayMusic(size_t id) override;
		virtual void PlayMusic(size_t id, int loop) override;
		virtual void PlaySFX(size_t id) override;
		virtual void PlaySFX(size_t id, int loop) override;
		virtual void PauseMusic() override;
		virtual void StopMusic() override;
		virtual void ResumeMusic() override;
		virtual void SetGlobalVolume(int volume) override;
		virtual void SetMusicVolume(int volume) override;
		virtual void SetVolume(size_t soundId, int volume) override;
		virtual void ShutDown() override;
	private:
		std::map<size_t, Mix_Chunk*>m_SoundList;
		std::map<size_t, Mix_Music*>m_MusicList;



		// Inherited via IAudio


	};





}