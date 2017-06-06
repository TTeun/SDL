#include <iostream>
#include "window/window.h"
#include "window/sprite/sprite.h"

using namespace std;

#include <SDL2/SDL.h>

int main( int argc, char* args[] )
{
  Window *w = new Window(1000, 800);

  Sprite *s = new Sprite("window/hello_world.bmp", w->screen_renderer());
  if (not s->is_success())
    cout << "Erorr\n";

  bool running = true;
  SDL_Event e;
  if (w->is_success())
    while (running){

      while( SDL_PollEvent( &e ) != 0 )
      {
          //User requests quit
          if( e.type == SDL_QUIT )
          {
              running = false;
          }
      }

      w->clear();
      s->blit(100, 100, 50, 50);
      w->render();
    }


	return 0;
}
