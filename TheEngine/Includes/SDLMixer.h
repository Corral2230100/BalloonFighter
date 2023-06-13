#pragma once
#include "IAudio.h"
#include "SDL_mixer.h"
#include <string>
#include <map>
namespace Engine
{
	class SDLMixer : public IAudio
	{
		
	public:
		
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
		virtual void SetVolume(int volume) override;
		virtual void SetVolume(size_t soundId, int volume) override;
	private:
		std::map<size_t, Mix_Chunk*> *m_SoundList = new std::map<size_t, Mix_Chunk*>();
		std::map<size_t, Mix_Music*> *m_MusicList = new std::map<size_t, Mix_Music*>();
	};





}