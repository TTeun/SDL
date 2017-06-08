#include "player.h"
#include <iostream>
#include "../../essential/essential.h"

using namespace std;

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
  if (m_dir == DIRECTION::STAT){
    src_rect->x = 0;
    src_rect->y = 0;
    src_rect->w = 32;
    src_rect->h = 32;
  }
  else if (m_dir == DIRECTION::RIGHT){
    src_rect->x = 32;
    src_rect->y = 0;
    src_rect->w = 32;
    src_rect->h = 32;
  }
  else if (m_dir == DIRECTION::LEFT){
    src_rect->x = 64;
    src_rect->y = 0;
    src_rect->w = 32;
    src_rect->h = 32;
  }
  des_rect->x = Essential::to_screen_x(x);
  des_rect->y = Essential::to_screen_y(y + 64);
  m_sprite->blit(des_rect, src_rect);
}

void Player::update(){
  if (m_state == STATE::FALLING)
  {
    if (Essential::collision()->level_collide(x, y + vy / Essential::fps(), 64, 64)){
      m_state = STATE::GROUNDED;
      vy = 0;
      y /= 16;
      y *= 16;
    } else {
      y += vy / Essential::fps();
      vy -= 7.0f / Essential::fps();
    }
  }
  if (m_state == STATE::GROUNDED && (Essential::collision()->no_ground_underneath(x, y, 64, 64))){
    m_state = STATE::FALLING;
  }

  if (not Essential::collision()->level_collide(x + vx / Essential::fps(), y, 64, 64) )
    x += vx / Essential::fps();
  else
    vx = 0;

  set_dir();
}

bool Player::does_hit(int _x, int _y){
  return (_x >= x ) && (_x <= x + 64) && (_y >= y) && (_y <= y + 64);
}
