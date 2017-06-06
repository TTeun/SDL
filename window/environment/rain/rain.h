#ifndef __RAIN__H
#define __RAIN__H

#include "../../sprite/sprite.h"
#include <vector>
#include <time.h>
#include "../../../essential/essential.h"

struct drop_info {
  drop_info(){
    x = rand() % (Essential::width() + Essential::height());
    y = rand() % Essential::height() + 5;
    vy = rand() % 4 + 400;
    vx = rand() % 4 - 400;
  }
  void reset(){
    x = rand() % (Essential::width() + Essential::height());
    y = 0;
    vy = rand() % 4 + 400;
    vx = rand() % 4 - 400;
  }
  float x;
  float y;
  float vy;
  float vx;
};

class Rain {
public:
  Rain(SDL_Renderer* screen_renderer);
  void render_rain();
private:
  size_t num_drops = 20;
  Sprite *m_rain_drop = nullptr;
  SDL_Renderer *m_screen_renderer = nullptr;
  std::vector<drop_info> *m_drops;
  Uint32 prev_tick;
  int m_width;
  int m_height;
  bool needs_timer = true;

  friend Uint32 fall(Uint32 interval, void *param);
};

#endif
