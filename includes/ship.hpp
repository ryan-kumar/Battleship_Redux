#ifndef SHIP_HPP
#define SHIP_HPP

#include "node.hpp"

enum class Direction { kLeft, kRight, kUp, kDown };

class Ship {
public:
  Ship(const Direction& dir,
       unsigned int start_x,
       unsigned int start_y,
       unsigned int size);
  Ship(const Ship& other) = delete;
  Ship& operator=(const Ship& other) = delete;
  ~Ship();

private:
  unsigned int start_x_;
  unsigned int start_y_;
  unsigned int size_;
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

#endif