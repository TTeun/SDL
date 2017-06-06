#include <iostream>
#include "essential/essential.h"
#include "window/window.h"
#include "window/sprite/sprite.h"
#include "window/environment/rain/rain.h"
#include <SDL2/SDL.h>

int Essential::m_width = 1000;
int Essential::m_height = 800;
int Essential::m_fps = 60;

using namespace std;


int main( int argc, char* args[] )
{
  Window *w = new Window(Essential::width(), Essential::height());
  Rain *rain = new Rain( w->screen_renderer());

  int width, height;
  bool running = true;
  SDL_Event e;
  if (w->is_success())
    while (running)
    {

      while( SDL_PollEvent( &e ) != 0 )
      {
          if( e.type == SDL_QUIT )
          {
              running = false;
          }
      }

      SDL_GetWindowSize(w->window(), &width, &height);
      Essential::set_width(width);
      Essential::set_height(height);

      w->clear();
      rain->render_rain();
      w->render();
    }

  delete w;
  delete rain;
	return 0;
}
