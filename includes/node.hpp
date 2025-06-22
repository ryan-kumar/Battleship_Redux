#ifndef NODE_HPP
#define NODE_HPP

class Ship;

struct Node {
  Ship* owner_ = nullptr;
  Node* next_ = nullptr;
  Node* prev_ = nullptr;
  Node() = default;
  Node(Ship* owner): owner_(owner) {}
};

#endif