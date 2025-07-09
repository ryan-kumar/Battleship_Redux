#ifndef SHIP_HPP
#define SHIP_HPP

#include <vector>

#include "node.hpp"

class Ship {
public:
  Ship(unsigned int size);
  Ship(const Ship& other) = delete;
  Ship& operator=(const Ship& other) = delete;
  bool operator<(const Ship& other) const;
  ~Ship();
  std::vector<Node*> GetNodes();
  void DestroyNode(Node* marked);  // may need modification
  bool Sunk() const { return size_ == 0; }

private:
  unsigned int size_;
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

#endif