#include "board.hpp"

// you might need additional includes
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

/**************************************************************************/
/* your function definitions                                              */
/**************************************************************************/

void InitBoard(Board& b) {
  for (int height_idx = 0; height_idx < b.kBoardHeight; ++height_idx) {
    for (int width_idx = 0; width_idx < b.kBoardWidth; ++width_idx) {
      b.board[height_idx][width_idx] = DiskType::kEmpty;  //
    }
  }
}
void DropDiskToBoard(Board& b, DiskType disk, int col) {
  if (!BoardLocationInBounds(0, col)) {
    throw std::runtime_error("Column is Full");
  }
  for (int row_idx = 0; row_idx < b.kBoardHeight; ++row_idx) {
    if (b.board[row_idx][col] == DiskType::kEmpty) {
      b.board[row_idx][col] = disk;
      return;
    }
  }
  throw std::runtime_error("Column is Full");
  return;
}

bool CheckForWinner(Board& b, DiskType disk) {
  if (SearchForWinner(b, disk, WinningDirection::kHorizontal)) {
    return true;
  }
  if (SearchForWinner(b, disk, WinningDirection::kVertical)) {
    return true;
  }
  if (SearchForWinner(b, disk, WinningDirection::kRightDiag)) {
    return true;
  }
  if (SearchForWinner(b, disk, WinningDirection::kLeftDiag)) {
    return true;
  }
  return false;
}

bool SearchForWinner(Board& b, DiskType disk, WinningDirection to_check) {
  if (to_check == WinningDirection::kRightDiag) {
    for (int row_idx = 0; row_idx < b.kBoardHeight - 3; ++row_idx) {
      if (!BoardLocationInBounds(row_idx + 3, 0)) {
        continue;
      }  // Saftey Check
      for (int col_idx = 0; col_idx < b.kBoardWidth - 3; ++col_idx) {
        if (!BoardLocationInBounds(row_idx + 3, col_idx + 3)) {
          continue;
        }  // Safety Check
        if (disk == b.board[row_idx][col_idx] &&
            disk == b.board[row_idx + 1][col_idx + 1] &&
            disk == b.board[row_idx + 2][col_idx + 2] &&
            disk == b.board[row_idx + 3][col_idx + 3]) {
          return true;
        }
      }
    }
  }
  if (to_check == WinningDirection::kLeftDiag) {
    for (int row_idx = 0; row_idx < b.kBoardHeight - 3; ++row_idx) {
      if (!BoardLocationInBounds(row_idx + 3, 0)) {
        continue;
      }  // Saftey Check
      for (int col_idx = b.kBoardWidth - 1; col_idx > 0; --col_idx) {
        if (!BoardLocationInBounds(row_idx + 3, col_idx - 3)) {
          continue;
        }  // Safety Check
        if (disk == b.board[row_idx][col_idx] &&
            disk == b.board[row_idx + 1][col_idx - 1] &&
            disk == b.board[row_idx + 2][col_idx - 2] &&
            disk == b.board[row_idx + 3][col_idx - 3]) {
          return true;
        }
      }
    }
  }

  if (to_check == WinningDirection::kHorizontal) {
    for (int row_idx = 0; row_idx < b.kBoardHeight; ++row_idx) {
      for (int col_idx = 0; col_idx < b.kBoardWidth - 3; ++col_idx) {
        if (!BoardLocationInBounds(row_idx, col_idx + 3)) {
          continue;
        }  // Safety Check
        if (disk == b.board[row_idx][col_idx] &&
            disk == b.board[row_idx][col_idx + 1] &&
            disk == b.board[row_idx][col_idx + 2] &&
            disk == b.board[row_idx][col_idx + 3]) {
          return true;
        }
      }
    }
  }

  if (to_check == WinningDirection::kVertical) {
    for (int row_idx = 0; row_idx < b.kBoardHeight - 3; ++row_idx) {
      if (!BoardLocationInBounds(row_idx + 3, 0)) {
        continue;
      }  // Saftey Check
      for (int col_idx = 0; col_idx < b.kBoardWidth; ++col_idx) {
        if (disk == b.board[row_idx][col_idx] &&
            disk == b.board[row_idx + 1][col_idx] &&
            disk == b.board[row_idx + 2][col_idx] &&
            disk == b.board[row_idx + 3][col_idx]) {
          return true;
        }
      }
    }
  }
  return false;
}
bool BoardLocationInBounds(int row, int col) {
  if (row >= 0 && row < 6 && col >= 0 && col < 7) {
    return true;
  }
  return false;
}
/**************************************************************************/
/* provided to you                                                        */
/**************************************************************************/
std::string BoardToStr(const Board& b) {
  constexpr int kTotalWidth = Board::kBoardWidth * 11 - Board::kBoardHeight - 1;
  std::stringstream ss;
  ss << std::endl;
  for (int row = Board::kBoardHeight; row > 0; --row) {
    ss << " |";
    for (int col = 0; col < Board::kBoardWidth; ++col) {
      std::string value_here;
      value_here.push_back(static_cast<char>(b.board[row - 1][col]));
      ss << ' ' << CenterStr(value_here, Board::kBoardWidth + 1) << '|';
    }
    ss << std::endl;
    ss << " |" << std::setw(kTotalWidth) << std::setfill('-') << '|'
       << std::endl;
  }
  ss << " |";
  for (int col = 0; col < Board::kBoardWidth; ++col) {
    ss << ' ' << CenterStr(std::to_string(col), Board::kBoardWidth + 1) << '|';
  }
  return ss.str();
}

std::string CenterStr(const std::string& str, int col_width) {
  // quick and easy (but error-prone) implementation
  auto padl = (col_width - str.length()) / 2;
  auto padr = (col_width - str.length()) - padl;
  std::string strf = std::string(padl, ' ') + str + std::string(padr, ' ');
  return strf;
}

void ClearScreen() {  // Clear Screen
  system("clear");    // For Mac OS
}