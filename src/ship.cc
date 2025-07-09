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

void Ship::DestroyNode(Node* marked) {
  Node* curr = head_;
  for (unsigned int i = 0; i < size_; i++) {
    if (&curr == &marked) {
      auto* prev = curr->prev_;
      auto* next = curr->next_;
      if (!prev) {
        next = head_;
      }
      next->prev_ = nullptr;
      if (!next) {
        prev = tail_;
      }
      prev->next_ = nullptr;
      delete curr;
      size_--;
      break;
    }
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

bool Ship::operator<(const Ship& other) const { return size_ < other.size_; }
