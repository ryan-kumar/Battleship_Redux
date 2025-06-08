#ifndef NODE_HPP
#define NODE_HPP

struct Node {
  unsigned int x_;
  unsigned int y_;
  Node* next_ = nullptr;
  Node* prev_ = nullptr;
  Node() = default;
  Node(unsigned int x, unsigned int y): x_(x), y_(y){};
};

#endif