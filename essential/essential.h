#ifndef __ESSENTIAL__H
#define __ESSENTIAL__H

class Essential{
  static int m_width;
  static int m_height;
  static int m_fps;

public:
  static int width(){
    return m_width;
  }
  static int height(){
    return m_height;
  }
  static int fps(){
    return m_fps;
  }

  static int set_width(int var){
    m_width = var;
  }
  static int set_height(int var){
    m_height = var;
  }
  static int set_fps(int var){
    m_fps = var;
  }

};

#endif
