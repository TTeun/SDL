#ifndef __DROP_INFO__H
#define __DROP_INFO__H

// Holds position and velocity of rain drop
struct drop_info {
  drop_info(){
    x = rand() % (Essential::screen_width() + Essential::screen_height());
    y = rand() % Essential::screen_height() + 50;
    vy = -( rand() % 40 + 700 );
    vx = rand() % 4 - 400;
  }
  void reset(){
    x = rand() % (Essential::screen_width() + Essential::screen_height());
    y = Essential::screen_height() + 40;
    vy = -( rand() % 40 + 700 );
    vx = rand() % 4 - 400;
  }
  int x;
  int y;
  int vy;
  int vx;
};

#endif
