#include "gameplay.hpp"

Gameplay::Gameplay(bool computer, unsigned int width, unsigned int height):
    computer_(computer) {
  p1_ = Board(width, height);
  p2_ = Board(width, height);
}

void Gameplay::SetBoard(const std::vector<Placement>& placements, bool p1) {
  Board& to_set = (p1) ? p1_ : p2_;
  for (auto placement : placements) {
    to_set.PlaceShip(
        placement.direction_, placement.x_, placement.y_, placement.size_);
  }
}

bool Gameplay::AttackBoard(unsigned int x, unsigned int y, bool p1) {
  Board& to_attack = (p1) ? p2_ : p1_;
  bool hit = to_attack.DestroyNode(x, y);
  return hit;
}

bool Gameplay::AttackBoardAi(unsigned int x, unsigned int y) { return false; }

bool Gameplay::GetStatus(bool p1) const {
  const Board& to_check = (p1) ? p1_ : p2_;
  return to_check.PlayerStatus();
}
