#include "gameloop.h"
#include <iostream>

using namespace std;

GameLoop::GameLoop( Window *_w )
  : w(_w)
{
  cout << "GameLoop constructor\n";
  level = make_unique<Level>( w->screen_renderer() );
  player = make_unique<Player>( w->screen_renderer(), level->start_x(), level->start_y() );
  col = make_unique<Collision>(level.get(), player.get());
  rain = make_unique<Rain>( w->screen_renderer() );

  Essential::set_collision(col.get());
  Essential::set_level_height(32 * level->level_height());
  Essential::set_level_width(32 * level->level_width());
}

GameLoop::~GameLoop(){
  cout << "GameLoop destructor\n";
  rain = nullptr;
  col = nullptr;
  player = nullptr;
  level = nullptr;
}

void GameLoop::start(){
  unsigned int ticks_per_frame = 1000 / Essential::fps();
  unsigned int last_tick;

  int width, height;
  bool running = true;
  SDL_Event e;

  const Uint8 *state = SDL_GetKeyboardState(NULL);

  if (w->is_success())
    while (running)
    {
      last_tick = SDL_GetTicks();
      while( SDL_PollEvent( &e ) != 0 )
      {
        switch( e.type ){
          case SDL_QUIT:
            running = false;
            break;
          }
      }

      if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D])
        player->force_right(5);

      if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A])
        player->force_right(-5);

      if (state[SDL_SCANCODE_UP]  || state[SDL_SCANCODE_W])
        player->force_up(8);
      else
        player->jump_released();


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
    }

}
