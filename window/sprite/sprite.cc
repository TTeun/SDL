#include "sprite.h"
#include <iostream>

using namespace std;

Sprite::Sprite(){}

Sprite::Sprite(char const * path)
{
  cout << "Sprite constructor\n";
  m_surface = SDL_LoadBMP( path );
  if( m_surface == NULL ){
    cout << "Unable to load image %s! SDL Error: " <<  SDL_GetError() << '\n';
    m_success = false;
  }

}

Sprite::~Sprite(){
  SDL_FreeSurface( m_surface );
}

void Sprite::blit( SDL_Surface *dest, SDL_Rect *dest_rec )
{
  SDL_BlitSurface( m_surface, NULL, dest, dest_rec );
}
