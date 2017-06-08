#include <iostream>
#include "essential/essential.h"
#include "window/window.h"
#include "window/sprite/sprite.h"
#include "window/environment/rain/rain.h"
#include "physics/collision/collision.h"
#include "window/environment/level/level.h"
#include "window/player/player.h"
#include "window/animation/animation.h"
#include <SDL2/SDL.h>

int Essential::m_screen_width = 1000;
int Essential::m_screen_height = 800;
int Essential::m_level_width = 1000;
int Essential::m_level_height = 800;
int Essential::m_camera_x = 0;
int Essential::m_camera_y = 0;
int Essential::m_fps = 144;
Collision *Essential::m_collision;

using namespace std;

int main( int argc, char* args[] )
{
  Window *w = new Window( Essential::screen_width(), Essential::screen_height() );
  Level *level = new Level( w->screen_renderer() );
  Player *player = new Player( w->screen_renderer() );
  Collision *col = new Collision(level, player);
  Essential::set_collision(col);
  Essential::set_level_height(32 * level->level_height());
  Essential::set_level_width(32 * level->level_width());

  Rain *rain = new Rain( w->screen_renderer() );

  int ticks_per_frame = 1000 / Essential::fps();
  int last_tick;

  int width, height;
  bool running = true;
  SDL_Event e;

  if (w->is_success())
    while (running)
    {
      last_tick = SDL_GetTicks();
      while( SDL_PollEvent( &e ) != 0 )
      {
        switch( e.type ){
          /* Look for a keypress */
          case SDL_KEYDOWN:
            /* Check the SDLKey values and move change the coords */
            switch( e.key.keysym.sym ){
              case SDLK_LEFT:
                player->force_right(-5.0f);
                break;
              case SDLK_RIGHT:
                player->force_right(5.0f);
                break;
              case SDLK_UP:
                player->force_up(10);
                break;
              default:
                break;
            }
            break;
          case SDL_QUIT:
            running = false;
            break;
          }
      }


      w->clear();

      Essential::update_camera(player->x(), player->y());
      SDL_GetWindowSize(w->window(), &width, &height);

      rain->render_rain();
      level->render_level();
      player->render_player();
      player->update();
      w->render();


      Essential::set_screen_width(width);
      Essential::set_screen_height(height);
      while (last_tick + ticks_per_frame > SDL_GetTicks())
        ;
        // SDL_Delay()
    }

  delete w;
  delete rain;
	return 0;
}
