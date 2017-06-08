#include "rain.h"
#include <iostream>

using namespace std;

Uint32 fall(Uint32 interval, void *param){
  Rain *t_rain = static_cast<Rain *>(param);

  for (auto & info : t_rain->m_drops)
  {

    if (info.x <= 0){
      info.reset();
      continue;
    }

    if (info.y <= 0){
      info.reset();
      continue;
    }

    if (Essential::collision()->level_collide(info.x, info.y)  || Essential::collision()->player_collide(info.x, info.y) )
    {
      // cout << "Rain collision\n";
      t_rain->add_hit( info.x, info.y + 20);
      info.reset();
      continue;
    }
    info.x += info.vx / Essential::fps();
    info.y += info.vy / Essential::fps();

  }

  // cout << SDL_GetTicks() - t_rain->prev_tick << '\n';
  t_rain->prev_tick = SDL_GetTicks();
  t_rain->needs_timer = true;
}

Rain::Rain(SDL_Renderer* screen_renderer)
  : m_screen_renderer(screen_renderer),
    m_rain_drop(new Sprite("assets/environment/rain_drop.png",screen_renderer)),
    m_rain_hit(new Sprite("assets/environment/rain_hit.png",screen_renderer))
{
  srand ( time(NULL) );
  m_drops.reserve(num_drops);
  for (size_t i = 0; i < num_drops; ++i)
    m_drops.push_back(drop_info());

  cout << "Rain started\n";
}

void Rain::render_rain(){
  if (needs_timer){
    SDL_AddTimer(1000 / Essential::fps(), fall, this);
    needs_timer = false;
  }

  while (m_animations.size() > 0 && m_animations[0]->is_done()){
    delete m_animations[0];
    m_animations.pop_front();
  }

  for (auto & anim : m_animations){
    anim->update();
    anim->render_anim();
  }
  for (auto & info : m_drops)
    m_rain_drop->blit(Essential::to_screen_x(info.x), Essential::to_screen_y(info.y));
}

void Rain::add_hit(Uint32 x, Uint32 y){
  m_animations.push_back(new Animation(3, x, y, m_rain_hit));
}
