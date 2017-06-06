#include "player.h"

Player::Player(SDL_Renderer* screen_renderer)
  : m_sprite(new Sprite("assets/player/player.png",screen_renderer)),
    src_rect(new SDL_Rect),
    des_rect(new SDL_Rect)
{
  des_rect->x = 0;
  des_rect->y = 0;
  des_rect->w = 128;
  des_rect->h = 128;
}

void Player::render_player(){
  if (dir == DIRECTION::STAT){
    src_rect->x = 0;
    src_rect->y = 0;
    src_rect->w = 32;
    src_rect->h = 32;
  }
  else if (dir == DIRECTION::RIGHT){
    src_rect->x = 32;
    src_rect->y = 0;
    src_rect->w = 32;
    src_rect->h = 32;
  }
  else if (dir == DIRECTION::LEFT){
    src_rect->x = 64;
    src_rect->y = 0;
    src_rect->w = 32;
    src_rect->h = 32;
  }
  m_sprite->blit(des_rect, src_rect);
}
