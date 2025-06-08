#ifndef BOARD_HPP
#define BOARD_HPP

#include <map>
#include <vector>

#include "ship.hpp"

class Board {
public:
  Board(unsigned int width, unsigned int height);
  void PlaceShip(const Direction& dir,
                 unsigned int start_x,
                 unsigned int start_y,
                 unsigned int size);

private:
  unsigned int width_ = 0;
  unsigned int height_ = 0;
  std::vector<std::vector<bool>> board_;
  std::map<std::pair<int, int>, Ship> ships_;
};

#endif