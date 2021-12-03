#include <iostream>

#include "board.hpp"

int main() {
  // NOLINT
  Board student;  // NOLINT
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, 0);
  if (student.board[0][0] == DiskType::kPlayer1) {
    std::cout << "true" << std::endl;
  }
}