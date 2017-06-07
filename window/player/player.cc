#include "player.h"

Player::Player(SDL_Renderer* screen_renderer)
  : m_sprite(new Sprite("assets/player/player.png",screen_renderer)),
    src_rect(new SDL_Rect),
    des_rect(new SDL_Rect)
{
  des_rect->x = 0;
  des_rect->y = 0;
  des_rect->w = 64;
  des_rect->h = 64;
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
  des_rect->x = x;
  des_rect->y = Essential::to_screen_y(y + 64);
  m_sprite->blit(des_rect, src_rect);
}

void Player::update(){
  if (Essential::collision()->level_collide(x, y + vy)){
    m_state = STATE::GROUNDED;
    vy = 0;
    y /= 16;
    y *= 16;
  }
  if (m_state == STATE::FALLING)
    vy -= .3f / Essential::fps();


  x += vx;
  y += vy;
}
