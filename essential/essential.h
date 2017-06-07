#ifndef __ESSENTIAL__H
#define __ESSENTIAL__H

#include "../physics/collision/collision.h"

class Essential{
public:

private:
  static int m_screen_width;
  static int m_screen_height;
  static int m_level_width;
  static int m_level_height;
  static int m_camera_x;
  static int m_camera_y;

  static int m_fps;
  static Collision* m_collision;


public:
  static int level_width(){
    return m_level_width;
  }
  static void set_level_width(int var){
    m_level_width = var;
  }
  static int level_height(){
    return m_level_height;
  }
  static void set_level_height(int var){
    m_screen_height = var;
  }
  static int screen_width(){
    return m_screen_width;
  }
  static void set_screen_width(int var){
    m_screen_width = var;
  }
  static int screen_height(){
    return m_screen_height;
  }
  static void set_screen_height(int var){
    m_screen_height = var;
  }
  static int camera_x(){
    return m_camera_x;
  }
  static void set_camera_x(int var){
    m_camera_x = var;
  }
  static int camera_y(){
    return m_camera_y;
  }
  static void set_camera_y(int var){
    m_camera_y = var;
  }
  static int fps(){
    return m_fps;
  }
  static void set_fps(int var){
    m_fps = var;
  }
  static Collision *collision(){
    return m_collision;
  }
  static void set_collision(Collision *var){
    m_collision = var;
  }

};

#endif
