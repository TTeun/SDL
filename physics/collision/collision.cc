#include "collision.h"
#include <iostream>

using namespace std;

Collision::Collision(Level *level, Player *player)
  : m_level(level),
    m_player(player)
{}
