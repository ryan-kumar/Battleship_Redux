#include "ship.hpp"
Ship::Ship(const Direction& dir,
           unsigned int start_x,
           unsigned int start_y,
           unsigned int size):
    start_x_(start_x), start_y_(start_y), size_(size) {
  head_ = new Node(start_x_, start_y_);
  Node* curr = head_;
  for (unsigned int i = 1; i < size; ++i) {
    Node* now =
        new Node(start_x_ + i, start_y_ + i);  // needs to be changed prob
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