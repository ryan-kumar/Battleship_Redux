#include "board.hpp"

#include <stdexcept>

Board::Board(unsigned int width, unsigned int height):
    width_(width), height_(height) {
  board_.resize(height_, std::vector<Node*>(width_, nullptr));
}

bool Board::ValidatePlacement(const Direction& dir,
                              unsigned int start_x,
                              unsigned int start_y,
                              unsigned int size) {
  if (start_x >= width_ || start_y >= height_) {
    return false;
  }
  for (unsigned int i = 0; i < size; ++i) {
    unsigned int x = (dir == Direction::kLeft)    ? start_x - i
                     : (dir == Direction::kRight) ? start_x + i
                                                  : start_x;
    unsigned int y = (dir == Direction::kUp)     ? start_y - i
                     : (dir == Direction::kDown) ? start_y + i
                                                 : start_y;
    if (x >= width_ || y >= height_ || board_[y][x]) return false;
  }
  return true;
}

void Board::PlaceShip(const Direction& dir,
                      unsigned int start_x,
                      unsigned int start_y,
                      unsigned int size) {
  if (!ValidatePlacement(dir, start_x, start_y, size)) {
    throw std::runtime_error("invalid placement");
  }
  Ship ship(size);
  std::vector<Node*> nodes = ship.GetNodes();
  for (unsigned int i = 0; i < size; ++i) {
    unsigned int x = (dir == Direction::kLeft)    ? start_x - i
                     : (dir == Direction::kRight) ? start_x + i
                                                  : start_x;
    unsigned int y = (dir == Direction::kUp)     ? start_y - i
                     : (dir == Direction::kDown) ? start_y + i
                                                 : start_y;
    board_[y][x] = nodes[i];
  }

  ships_.insert(ship);
}
