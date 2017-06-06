#ifndef __RAIN__H
#define __RAIN__H

#include "../../sprite/sprite.h"
#include <vector>
#include <time.h>
#include "../../../essential/essential.h"
#include "drop_info.h"

class Rain {
public:
  Rain(SDL_Renderer* screen_renderer);
  void render_rain();

private:
  size_t num_drops = 120;
  Sprite *m_rain_drop = nullptr;
  SDL_Renderer *m_screen_renderer = nullptr;
  std::vector<drop_info> m_drops;
  Uint32 prev_tick;
  int m_width;
  int m_height;
  bool needs_timer = true;

  friend Uint32 fall(Uint32 interval, void *param);
};

#endif
