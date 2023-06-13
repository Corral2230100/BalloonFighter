#include "SDLMixer.h"
#include "SDL.h"

void Engine::SDLMixer::Init()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

size_t Engine::SDLMixer::LoadMusic(const std::string& filename)
{
	const size_t _soundId = std::hash<std::string>()(filename);
	if (m_MusicList->count(_soundId) > 0 ) {
		return _soundId;
	}
	std::string _path = static_cast<std::string>(SDL_GetBasePath()) + filename.c_str();
	Mix_Music* _sound = Mix_LoadMUS(_path.c_str());

	if (_sound != nullptr) {
		(*m_MusicList)[_soundId] = _sound;
		return _soundId;
	}
	return -1;
}

size_t Engine::SDLMixer::LoadSound(const std::string& filename)
{
	const size_t _soundId = std::hash<std::string>()(filename);
	if (m_SoundList->count(_soundId) > 0) {
		return _soundId;
	}
	std::string _path = static_cast<std::string>(SDL_GetBasePath()) + filename.c_str();
	Mix_Chunk* _sound = Mix_LoadWAV(_path.c_str());

	if (_sound != nullptr) {
		(*m_SoundList)[_soundId] = _sound;
		return _soundId;
	}
	return -1;
}

void Engine::SDLMixer::PlayMusic(size_t id)
{
	Mix_Music* _Music = (*m_MusicList)[id];
	Mix_PlayMusic(_Music, false);
}

void Engine::SDLMixer::PlayMusic(size_t id, int loop)
{
	Mix_Music* _Music = (*m_MusicList)[id];
	Mix_PlayMusic(_Music, -1);
}

void Engine::SDLMixer::PlaySFX(size_t id)
{
	Mix_Chunk* _SFX = (*m_SoundList)[id];
	Mix_PlayChannel(0, _SFX, 0);
}

void Engine::SDLMixer::PlaySFX(size_t id, int loop)
{
	Mix_Chunk* _SFX = (*m_SoundList)[id];
	Mix_PlayChannel(0, _SFX, loop);
}

void Engine::SDLMixer::PauseMusic()
{
}

void Engine::SDLMixer::StopMusic()
{
	auto iter = m_MusicList->begin();
	while (iter != m_MusicList->end()) {
		Mix_FreeMusic((*iter).second);
		m_MusicList->erase(iter++);
		//iter.second = nullptr;
	}
	for (auto iter : *m_SoundList)
	{
		Mix_FreeChunk(iter.second);
		//iter.second = nullptr;
	}
	m_MusicList->clear();
	m_SoundList->clear();
	
	delete m_MusicList;
	delete m_SoundList;
	Mix_CloseAudio();
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
