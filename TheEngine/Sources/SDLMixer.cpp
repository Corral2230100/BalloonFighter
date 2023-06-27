#include "SDLMixer.h"
#include "SDL_mixer.h"
#include "SDL.h"

namespace TomNook
{
	/// <summary>
	/// Boots up the SDL mixer
	/// </summary>
	void SDLMixer::Init()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	}


	/// <summary>
	/// Loads a music file and stores a hashed value,
	/// </summary>
	/// <param name="filename"></param>
	/// <returns>returns the hashed value or an existing one if the audio already existed</returns>
	size_t SDLMixer::LoadMusic(const std::string& filename)
	{
		const size_t _soundId = std::hash<std::string>()(filename);
		if (m_MusicList.count(_soundId) > 0) {
			return _soundId;
		}
		std::string _path = static_cast<std::string>(SDL_GetBasePath()) + filename.c_str();
		Mix_Music* _sound = Mix_LoadMUS(_path.c_str());

		if (_sound != nullptr) {
			m_MusicList[_soundId] = _sound;
			return _soundId;
		}
		return -1;
	}

	/// <summary>
	/// Loads a sound file and stores a hashed value,
	/// </summary>
	/// <param name="filename"></param>
	/// <returns>returns the hashed value or an existing one if the audio already existed</returns>
	size_t SDLMixer::LoadSound(const std::string& filename)
	{
		const size_t _soundId = std::hash<std::string>()(filename);
		if (m_SoundList.count(_soundId) > 0) {
			return _soundId;
		}
		std::string _path = filename;
		Mix_Chunk* _sound = Mix_LoadWAV(_path.c_str());

		if (_sound != nullptr) {
			m_SoundList[_soundId] = _sound;
			return _soundId;
		}
		return -1;
	}

	/// <summary>
	/// Plays music from it's hashed id.
	/// </summary>
	/// <param name="id"></param>
	void SDLMixer::PlayMusic(size_t id)
	{
		Mix_Music* _Music = m_MusicList[id];
		Mix_PlayMusic(_Music, false);
	}

	/// <summary>
	/// plays music from it's hashed id.
	/// </summary>
	/// <param name="id"></param>
	/// <param name="loop"></param>
	void SDLMixer::PlayMusic(size_t id, int loop)
	{
		Mix_Music* _Music = m_MusicList[id];
		Mix_PlayMusic(_Music, loop);
	}

	/// <summary>
	/// plays a sound effect from it's hashed id.
	/// </summary>
	/// <param name="id"></param>
	void SDLMixer::PlaySFX(size_t id)
	{
		Mix_Chunk* _SFX = m_SoundList[id];
		Mix_PlayChannel(0, _SFX, 0);
	}

	/// <summary>
	/// plays a sound effect from it's hashed id.
	/// </summary>
	/// <param name="id"></param>
	/// <param name="loop"></param>
	void SDLMixer::PlaySFX(size_t id, int loop)
	{
		Mix_Chunk* _SFX = m_SoundList[id];
		Mix_PlayChannel(0, _SFX, loop);
	}


	void SDLMixer::PauseMusic()
	{

	}

	void SDLMixer::StopMusic()
	{

	}

	void SDLMixer::ResumeMusic()
	{

	}

	/// <summary>
	/// Sets global volume
	/// Volume is a value between 0 and 128
	/// </summary>
	/// <param name="volume"></param>
	void SDLMixer::SetGlobalVolume(int volume)
	{
		Mix_Volume(-1,volume);
	}
	/// <summary>
	/// Sets the volume of the music layer
	/// Volume is a value between 0 and 128
	/// </summary>
	/// <param name="volume"></param>
	void SDLMixer::SetMusicVolume(int volume)
	{
		Mix_VolumeMusic(volume);
	}
	/// <summary>
	/// Sets a specific sound effect's volume.
	/// Volume is a value between 0 and 128
	/// </summary>
	/// <param name="soundId"></param>
	/// <param name="volume"></param>
	void SDLMixer::SetVolume(size_t soundId, int volume)
	{
	}

	/// <summary>
	/// Deletes all audio files and shuts the mixer down.
	/// </summary>
	void SDLMixer::ShutDown()
	{
		auto iter = m_MusicList.begin();
		for (auto iter : m_MusicList)
		{
			Mix_FreeMusic(iter.second);
		}
		for (auto iter : m_SoundList)
		{
			Mix_FreeChunk(iter.second);
		}
		m_MusicList.clear();
		m_SoundList.clear();

		Mix_CloseAudio();
	}




}