#ifndef BOARD_HPP
#define BOARD_HPP

#include <set>
#include <vector>

#include "ship.hpp"

enum Direction { kLeft, kRight, kUp, kDown };

class Board {
public:
  Board() = default;
  Board(unsigned int width, unsigned int height);
  bool ValidatePlacement(const Direction& dir,  // author-defined helper; do not
                                                // provide in starter code
                         unsigned int start_x,
                         unsigned int start_y,
                         unsigned int size);
  void PlaceShip(const Direction& dir,
                 unsigned int start_x,
                 unsigned int start_y,
                 unsigned int size);
  bool DestroyNode(unsigned int x, unsigned int y);
  bool PlayerStatus() const { return ships_.empty(); }
  void ToPpm();  // optional: change to PNG

private:
  unsigned int width_ = 0;
  unsigned int height_ = 0;
  std::vector<Ship> ships_;
  std::vector<std::vector<Node*>> board_;
};

#endif