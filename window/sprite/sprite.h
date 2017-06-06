#ifndef __SPRITE__H
#define __SPRITE__H

#include <SDL2/SDL.h>

class Sprite {
public:
  Sprite();
  Sprite(char const * path);
  ~Sprite();
  void blit( SDL_Surface *dest, SDL_Rect *dest_rec );
  bool is_success();

private:
  SDL_Surface* m_surface = nullptr;
  bool m_success = true;
};

bool inline Sprite::is_success(){
  return m_success;
}

#endif
