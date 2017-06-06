#ifndef __SPRITE__H
#define __SPRITE__H

#include <SDL2/SDL.h>

class Sprite {
public:
  Sprite();
  Sprite(char const * path, SDL_Surface *screen_surface);
  ~Sprite();
  void blit( SDL_Rect *dest_rec );
  void blit( int x, int y, int w, int h );
  bool is_success();

private:
  bool m_success = true;

  SDL_Surface* m_surface = nullptr;
  SDL_Surface* m_screen_surface = nullptr;
};

bool inline Sprite::is_success(){
  return m_success;
}

#endif
