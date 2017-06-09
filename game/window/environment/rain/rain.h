#ifndef __RAIN__H
#define __RAIN__H

#include "../../sprite/sprite.h"
#include <vector>
#include <time.h>
#include "../../../essential/essential.h"
#include "drop_info.h"
#include "../../animation/animation.h"
#include <deque>


class Rain {
public:
  Rain(SDL_Renderer* screen_renderer);
  ~Rain();
  void render_rain();

private:
  size_t num_drops = 250;
  SDL_Renderer *m_screen_renderer = nullptr;
  Sprite *m_rain_drop = nullptr;
  Sprite *m_rain_hit = nullptr;

  std::vector<drop_info> m_drops;
  Uint32 prev_tick;
  int m_width;
  int m_height;
  bool needs_timer = true;

  void add_hit(Uint32 x, Uint32 y);
  std::deque<Animation*> m_animations;
  Animation *anim1, *anim2;
  friend Uint32 fall(Uint32 interval, void *param);
};

#endif
