#ifndef _SDL_AUDIO_H_
#define _SDL_AUDIO_H_

#include "system.h"
#include "audio.h"

#include <map>

#include <SDL.h>
#include <SDL_mixer.h>

struct SdlAudio : protected AudioInterface {
	SdlAudio();
	~SdlAudio();

	void BGM_Play(std::string const&, int, int);
	void BGM_Pause();
	void BGM_Resume();
	void BGM_Stop();
	void BGM_Fade(int);
	void BGS_Play(std::string const&, int, int);
	void BGS_Stop();
	void BGS_Fade(int);
	void ME_Play(std::string const&, int, int);
	void ME_Stop();
	void ME_Fade(int /* fade */);
	void SE_Play(std::string const&, int, int);
	void SE_Stop();
	void Update();

 private:
	EASYRPG_SHARED_PTR<Mix_Music> bgm;
	int bgm_volume;
	EASYRPG_SHARED_PTR<Mix_Chunk> bgs;
	int bgs_channel;
	EASYRPG_SHARED_PTR<Mix_Chunk> me;
	int me_channel;
	bool me_stopped_bgm;

	typedef std::map<int, EASYRPG_SHARED_PTR<Mix_Chunk> > sounds_type;
	sounds_type sounds;
}; // class SdlAudio

#endif // _SDL_AUDIO_H_
