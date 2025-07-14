#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP
#include <vector>

#include "board.hpp"

struct Placement {
  Direction direction_;
  unsigned int x_;
  unsigned int y_;
  unsigned int size_;
};

class Gameplay {
public:
  Gameplay(bool computer, unsigned int width, unsigned int height);
  void SetBoard(const std::vector<Placement>& placements, bool p1);
  bool AttackBoard(unsigned int x, unsigned int y, bool p1);
  bool AttackBoardAi(unsigned int x, unsigned int y);
  bool GetStatus(bool p1) const;

private:
  bool computer_ = false;
  Board p1_;
  Board p2_;
};

#endif