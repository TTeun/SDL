#ifndef __ANIMATION__H
#define __ANIMATION__H

#include "../sprite/sprite.h"
#include <vector>

class Animation {
public:
  Animation();
  Animation(char const * path, SDL_Renderer *screen_renderer, Uint32 num_frames, int x, int y, Sprite *sprite);

  void render_anim();
  void update();
  bool is_done();
private:
  Sprite *m_sprite = nullptr;

  Uint32 m_last_tick;
  bool m_is_done = false;
  Uint32 m_num_frames;
  Uint32 m_current_frame = 0;
  Uint32 ms_per_frame = 100;
  SDL_Rect des_rect;
  std::vector<SDL_Rect> m_src_rects;
};

#endif
