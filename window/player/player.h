#ifndef __PLAYER__H
#define __PLAYER__H

#include "../sprite/sprite.h"
#include "../../essential/essential.h"

class Player {
public:
  Player(SDL_Renderer* screen_renderer);
  void render_player();
  void update();


  enum class DIRECTION {
    STAT,
    LEFT,
    RIGHT
  };
  void set_dir(DIRECTION _dir){
    dir = _dir;
  }



  float x = 64, y = 500, vx = 0, vy = 0;
  enum class STATE {
    GROUNDED,
    FALLING
  };
  STATE m_state = STATE::FALLING;
  DIRECTION dir = DIRECTION::STAT;

private:


  SDL_Rect *src_rect;
  SDL_Rect *des_rect;
  Sprite *m_sprite;
};

#endif
