#ifndef __DROP_INFO__H
#define __DROP_INFO__H

#include <iostream>
// Holds position and velocity of rain drop
struct drop_info {
  drop_info(){
    x = rand() % (Essential::level_width() + Essential::level_height());
    y = rand() % Essential::level_height();
    vy = -( rand() % 40 + 700 );
    vx = rand() % 4 - 400;
    std::cout << Essential::level_height();
  }
  void reset(){
    x = rand() % (Essential::screen_width() + Essential::level_height());
    y = Essential::level_height() - 40;
    vy = -( rand() % 40 + 700 );
    vx = rand() % 4 - 400;
  }
  int x;
  int y;
  int vy;
  int vx;
};

#endif
