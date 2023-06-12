#include "SDLMixer.h"
#include "SDL.h"

void Engine::SDLMixer::Init()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

size_t Engine::SDLMixer::LoadMusic(const std::string& filename)
{
	const size_t _soundId = std::hash<std::string>()(filename);
	if (_soundId == m_MusicIdList[filename]) {
		return _soundId;
	}
	std::string _path = static_cast<std::string>(SDL_GetBasePath()) + filename.c_str();
	Mix_Music* _sound = Mix_LoadMUS(_path.c_str());

	if (_sound != nullptr) {
		m_MusicIdList.emplace(filename.c_str(), _soundId);
		m_MusicList[_soundId] = _sound;
		return _soundId;
	}
	return -1;
}

size_t Engine::SDLMixer::LoadSound(const std::string& filename)
{
	const size_t _soundId = std::hash<std::string>()(filename);
	if (_soundId == m_SoundIdList[filename]) {
		return _soundId;
	}
	std::string _path = static_cast<std::string>(SDL_GetBasePath()) + filename.c_str();
	Mix_Chunk* _sound = Mix_LoadWAV(_path.c_str());

	if (_sound != nullptr) {
		m_SoundIdList.emplace(filename.c_str(), _soundId);
		m_SoundList[_soundId] = _sound;
		return _soundId;
	}
	return -1;
}

void Engine::SDLMixer::PlayMusic(size_t id)
{
	Mix_Music* _Music = m_MusicList[id];
	Mix_PlayMusic(_Music, false);
}

void Engine::SDLMixer::PlayMusic(size_t id, int loop)
{
	Mix_Music* _Music = m_MusicList[id];
	Mix_PlayMusic(_Music, true);
}

void Engine::SDLMixer::PlaySFX(size_t id)
{
}

void Engine::SDLMixer::PlaySFX(size_t id, int loop)
{
}

void Engine::SDLMixer::PauseMusic()
{
}

void Engine::SDLMixer::StopMusic()
{

}

void Engine::SDLMixer::ResumeMusic()
{
}

void Engine::SDLMixer::SetVolume(int volume)
{
}

void Engine::SDLMixer::SetVolume(size_t soundId, int volume)
{
}
