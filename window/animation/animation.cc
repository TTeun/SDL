#include "animation.h"
#include <iostream>

using namespace std;

Animation::Animation(){
  cout << "empty animation constructor\n";
}

Animation::Animation(char const * path, SDL_Renderer *screen_renderer, Uint32 num_frames, int _x, int _y, Sprite *sprite)
: m_sprite(sprite)
{

  m_src_rects.clear();
  m_src_rects.reserve(num_frames);
  SDL_Rect rec;
  rec.w = 16;
  rec.h = 16;
  rec.y = 0;
  for (Uint32 i = 0; i != 3; ++i){
    rec.x = 16 * i;
    m_src_rects.push_back(rec);
  }

  m_num_frames = num_frames;

  des_rect.x = _x;
  des_rect.y = _y;
  des_rect.w = 16;
  des_rect.h = 16;

  m_last_tick = SDL_GetTicks();
}

void Animation::update(){
  if (m_last_tick + ms_per_frame > SDL_GetTicks())
    return;

  if (m_current_frame + 1 >= m_num_frames){
    ++m_current_frame;
    return;
  }

  m_last_tick = SDL_GetTicks();
  ++m_current_frame;
  m_current_frame %= m_num_frames;
}

void Animation::render_anim(){
  if (m_current_frame >= m_num_frames)
    return;

  m_sprite->blit(&des_rect, &(m_src_rects[m_current_frame]));
}

bool Animation::is_done(){
  return m_current_frame >= m_num_frames;
}
