#include "ship.hpp"
Ship::Ship(unsigned int size): size_(size) {
  head_ = new Node(this);
  Node* curr = head_;
  for (unsigned int i = 1; i < size_; ++i) {
    Node* now = new Node(this);
    curr->next_ = now;
    now->prev_ = curr;
    curr = now;
  }
  tail_ = curr;
}
Ship::~Ship() {
  while (head_) {
    Node* next = head_->next_;
    delete head_;
    head_ = next;
  }
  head_ = tail_ = nullptr;
}

void Ship::DestroyNode() {
  Node* to_remove = tail_;
  tail_ = tail_->prev_;
  delete to_remove;
  if (tail_ == nullptr) {
    head_ = nullptr;
  } else {
    tail_->next_ = nullptr;
  }
}
std::vector<Node*> Ship::GetNodes() {
  std::vector<Node*> nodes;
  Node* curr = head_;
  for (unsigned int i = 0; i < size_; i++) {
    nodes.push_back(curr);
    curr = curr->next_;
  }
  return nodes;
}
