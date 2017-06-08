#ifndef __PLAYER__H
#define __PLAYER__H

#include "../sprite/sprite.h"
#include "../../physics/rigidbody.h"

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

  bool does_hit(int x, int y);
  float vx = 0, vy = 0;
  int x();
  int y();

  enum class STATE {
    GROUNDED,
    FALLING
  };
  STATE m_state = STATE::FALLING;

private:
  void set_dir();
  DIRECTION m_dir = DIRECTION::STAT;

  Sprite *m_sprite;
  SDL_Rect *src_rect;
  SDL_Rect *des_rect;
  RigidBody *m_rigidbody = nullptr;
};

inline void Player::set_dir(){
  m_dir = vx > 0  ? DIRECTION::RIGHT :
          vx == 0 ? DIRECTION::STAT  :
                    DIRECTION::LEFT  ;
}

inline int Player::x(){
  return m_rigidbody->m_x;
}

inline int Player::y(){
  return m_rigidbody->m_y;
}

#endif
