#include "board.hpp"

#include <stdexcept>

Board::Board(unsigned int width, unsigned int height):
    width_(width), height_(height) {
  board_.resize(height_, std::vector<bool>(width_, false));
}

void Board::PlaceShip(const Direction& dir,
                      unsigned int start_x,
                      unsigned int start_y,
                      unsigned int size) {
  if (start_x > width_ || start_y > height_) {
    throw std::invalid_argument("Ship cannot be placed here!");
  }
  int counted_cells = 0;
  for (unsigned int i = 0; i < size; i++) {
    switch (dir) {
    case Direction::kRight: {
      unsigned int curr_x = start_x + i;
      if (curr_x < width_ && !board_[start_y][curr_x]) counted_cells++;
      break;
    }
    case Direction::kLeft: {
      unsigned int curr_x = start_x - i;
      if (curr_x < width_ && !board_[start_y][curr_x]) counted_cells++;
      break;
    }
    case Direction::kDown: {
      unsigned int curr_y = start_y + i;
      if (curr_y < height_ && !board_[start_y][curr_y]) counted_cells++;
      break;
    }
    case Direction::kUp: {
      unsigned int curr_y = start_y - i;
      if (curr_y < height_ && !board_[start_y][curr_y]) counted_cells++;
      break;
    }
    }
  }
  if (counted_cells != size)
    throw std::invalid_argument("Ship cannot be placed here");
}