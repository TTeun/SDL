#include "rain.h"
#include <iostream>

using namespace std;

Uint32 fall(Uint32 interval, void *param){
  Rain *t_rain = static_cast<Rain *>(param);
  for (auto & info : *(t_rain->m_drops)){
    info.x += info.vx / Essential::fps();

    if (info.x < 0){
      info.reset();
      continue;
    }

    info.y += info.vy / Essential::fps();
    if (info.y > Essential::height())
      info.reset();
  }
  cout << SDL_GetTicks() - t_rain->prev_tick << '\n';
  t_rain->prev_tick = SDL_GetTicks();
  t_rain->needs_timer = true;
}

Rain::Rain(SDL_Renderer* screen_renderer)
  : m_screen_renderer(screen_renderer),
    m_rain_drop(new Sprite("assets/environment/rain_drop.png",screen_renderer)),
    m_drops(new vector<drop_info>)
{
  srand ( time(NULL) );
  m_drops->reserve(num_drops);
  for (size_t i = 0; i < num_drops; ++i)
    m_drops->push_back(drop_info());
}

void Rain::render_rain(){
  for (auto & info : *m_drops)
    m_rain_drop->blit(info.x, info.y);

  if (needs_timer){
    SDL_AddTimer(1000 / Essential::fps(), fall, this);
    needs_timer = false;
  }

}
