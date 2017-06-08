#include "sprite.h"
#include "../../essential/essential.h"
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

Sprite::Sprite(){}

Sprite::Sprite(char const * path, SDL_Renderer *screen_renderer)
  : m_screen_renderer(screen_renderer)
{
  if (not m_screen_renderer){
    cout << "Invalid renderer passed to sprite cnstr.\n";
    m_success = false;
  }

  SDL_Surface *temp_surface;
  temp_surface = IMG_Load( path );
  if( temp_surface == NULL ){
    cout << "Unable to load image %s! SDL Error: " <<  SDL_GetError() << '\n';
    m_success  = false;
  }

  m_texture = SDL_CreateTextureFromSurface( m_screen_renderer, temp_surface );
  if (not m_texture){
    cout << "Unable to convert to texture %s! SDL Error: " <<  SDL_GetError() << '\n';
    m_success = false;
  }

  SDL_FreeSurface( temp_surface );
  SDL_QueryTexture(m_texture, NULL, NULL, &dest_rec.w, &dest_rec.h);
}

Sprite::~Sprite(){
  SDL_DestroyTexture( m_texture );
}

void Sprite::blit( SDL_Rect *dest_rec, SDL_Rect *src_rect )
{
  // if (  dest_rec->x > 100000UL || dest_rec->y < -1024 || dest_rec->y > 100000UL)
  //   return;
  SDL_RenderCopy(m_screen_renderer, m_texture, src_rect, dest_rec);
}

void Sprite::blit( int _x, int _y, SDL_Rect *src_rect )
{
  dest_rec.x = _x;
  dest_rec.y = _y;
  blit(&dest_rec, nullptr);
}

void Sprite::blit( int _x, int _y, int _w, int _h )
{
  SDL_Rect dest_rec;
  dest_rec.x = _x;
  dest_rec.y = _y;
  dest_rec.w = _w;
  dest_rec.h = _h;
  blit(&dest_rec, nullptr);
}
