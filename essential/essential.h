#ifndef __ESSENTIAL__H
#define __ESSENTIAL__H

class Essential{
  static int m_screen_width;
  static int m_screen_height;
  static int m_level_width;
  static int m_level_height;
  static int m_camera_x;
  static int m_camera_y;

  static int m_fps;

public:
  static int level_width(){
    return m_level_width;
  }
  static int set_level_width(int var){
    m_level_width = var;
  }
  static int level_height(){
    return m_level_height;
  }
  static int set_level_height(int var){
    m_screen_height = var;
  }
  static int screen_width(){
    return m_screen_width;
  }
  static int set_screen_width(int var){
    m_screen_width = var;
  }
  static int screen_height(){
    return m_screen_height;
  }
  static int set_screen_height(int var){
    m_screen_height = var;
  }
  static int camera_x(){
    return m_camera_x;
  }
  static int set_camera_x(int var){
    m_camera_x = var;
  }
  static int camera_y(){
    return m_camera_y;
  }
  static int set_camera_y(int var){
    m_camera_y = var;
  }
  static int fps(){
    return m_fps;
  }
  static int set_fps(int var){
    m_fps = var;
  }

};

#endif
