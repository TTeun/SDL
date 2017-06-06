#ifndef __SPRITE__H
#define __SPRITE__H

#include <SDL2/SDL.h>

class Sprite {
public:
  Sprite();
  Sprite(char const * path, SDL_Renderer *screen_surface);
  ~Sprite();
  void blit( SDL_Rect *dest_rec, SDL_Rect *src_rect = NULL );
  void blit( int x, int y, SDL_Rect *src_rect = NULL );
  void blit( int x, int y, int w, int h );
  bool is_success();

private:
  bool m_success = true;

  SDL_Rect dest_rec;
  SDL_Texture* m_texture = nullptr;
  SDL_Renderer* m_screen_renderer = nullptr;
};

bool inline Sprite::is_success(){
  return m_success;
}

#endif
