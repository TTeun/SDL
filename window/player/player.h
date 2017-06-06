#ifndef __PLAYER__H
#define __PLAYER__H

#include "../sprite/sprite.h"
#include "../../essential/essential.h"

class Player {
public:
  Player(SDL_Renderer* screen_renderer);
  void render_player();

  enum class DIRECTION {
    STAT,
    LEFT,
    RIGHT
  };
  void set_dir(DIRECTION _dir){
    dir = _dir;
  }

private:

  DIRECTION dir = DIRECTION::STAT;

  SDL_Rect *src_rect;
  SDL_Rect *des_rect;
  Sprite *m_sprite;
  friend Uint32 fall(Uint32 interval, void *param);
};

#endif
