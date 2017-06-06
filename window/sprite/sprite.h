#ifndef __SPRITE__H
#define __SPRITE__H

#include <SDL2/SDL.h>

class Sprite {
public:
  Sprite();
  Sprite(char const * path, SDL_Renderer *screen_surface);
  ~Sprite();
  void blit( SDL_Rect *dest_rec );
  void blit( int x, int y, int w, int h );
  bool is_success();

private:
  bool m_success = true;

  SDL_Surface* m_surface = nullptr;
  SDL_Renderer* m_screen_renderer = nullptr;

  SDL_Texture* m_texture = nullptr;
};

bool inline Sprite::is_success(){
  return m_success;
}

#endif
