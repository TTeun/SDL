#include "sprite.h"
#include <iostream>

using namespace std;

Sprite::Sprite(){}

Sprite::Sprite(char const * path, SDL_Surface *screen_surface)
  : m_screen_surface(screen_surface)
{
  if (not m_screen_surface){
    cout << "Invalid window\n";
    m_success = false;
  }
  SDL_Surface *temp_surface;
  temp_surface = SDL_LoadBMP( path );
  if( temp_surface == NULL ){
    cout << "Unable to load image %s! SDL Error: " <<  SDL_GetError() << '\n';
    m_success  = false;
  }

  m_surface = SDL_ConvertSurface( temp_surface, m_screen_surface->format, NULL );
  if( m_surface == NULL )
  {
    cout <<  "Unable to optimize image :" << SDL_GetError() << '\n';
  }

  SDL_FreeSurface( temp_surface );
}

Sprite::~Sprite(){
  SDL_FreeSurface( m_surface );
}

void Sprite::blit( SDL_Rect *dest_rec )
{
  SDL_BlitScaled( m_surface, NULL, m_screen_surface, dest_rec );
}


void Sprite::blit( int _x, int _y, int _w, int _h )
{
  SDL_Rect dest_rec;
  dest_rec.x = _x;
  dest_rec.y = _y;
  dest_rec.w = _w;
  dest_rec.h = _h;
  SDL_BlitScaled( m_surface, NULL, m_screen_surface, &dest_rec );
}
