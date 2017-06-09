#ifndef __BOX__H
#define __BOX__H

class Box {
public:
  Box(float x, float y, float w, float h)
    : m_x(x), m_y(y + h), m_w(w), m_h(h)
  {}
  bool does_collide_with_piont(float x, float y);

  float m_x;
  float m_y;
  float m_w;
  float m_h;
};

bool inline Box::does_collide_with_piont(float x, float y){
  return (x >= m_x && x < m_x + m_w && y >= m_y && y < m_y + m_h);
}


#endif
