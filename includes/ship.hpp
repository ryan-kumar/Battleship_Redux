#ifndef SHIP_HPP
#define SHIP_HPP

#include "node.hpp"

class Ship {
public:
  Ship(unsigned int size);
  Ship(const Ship& other) = delete;
  Ship& operator=(const Ship& other) = delete;
  ~Ship();

  void DestroyNode();  // may need modification

private:
  unsigned int size_;
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

#endif