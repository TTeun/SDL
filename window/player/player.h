#ifndef __PLAYER__H
#define __PLAYER__H

#include "../sprite/sprite.h"

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

  float x = 50, y = 50, vx = 0, vy = 0;
  enum class STATE {
    GROUNDED,
    FALLING
  };
  STATE m_state = STATE::FALLING;

private:

  void set_dir();
  DIRECTION m_dir = DIRECTION::STAT;

  SDL_Rect *src_rect;
  SDL_Rect *des_rect;
  Sprite *m_sprite;
};

inline void Player::set_dir(){
  m_dir = vx > 0  ? DIRECTION::RIGHT :
          vx == 0 ? DIRECTION::STAT  :
                    DIRECTION::LEFT  ;
}

#endif
