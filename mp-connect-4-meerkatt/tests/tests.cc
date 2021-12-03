// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Meer S. Gujral                  Environment : ubuntu:bionic               //
//  Date ......: 2021/06/08                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

#include "catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "board.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////
constexpr int kBoardWidth = 7;
constexpr int kBoardHeight = 6;

bool AreEqual(DiskType solution[][kBoardWidth],
              DiskType student[][kBoardWidth]) {
  for (int i = 0; i < kBoardHeight; ++i) {
    for (int j = 0; j < kBoardWidth; ++j) {
      if (solution[i][j] != student[i][j]) return false;
    }
  }
  return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("Board initialization", "[board_init]") {
  // SECTION("Can use sections") {}
  // clang-format off
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  REQUIRE(AreEqual(solution, student.board));
}

TEST_CASE("Dropping Disk to Board", "[drop_disk]") {
  // clang-format off
   SECTION("Testing Empty Columns") {
      DiskType solution[kBoardHeight][kBoardWidth] = { 
        {DiskType::kPlayer1, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
    };
    // clang-format on
    Board student;  // NOLINT
    InitBoard(student);
    DropDiskToBoard(student, DiskType::kPlayer1, 0);
    REQUIRE(AreEqual(solution, student.board));
  }

  // clang-format off
   SECTION("Testing Nonempty Columns") {
      DiskType solution[kBoardHeight][kBoardWidth] = { 
        {DiskType::kPlayer1, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
    };
    // clang-format on
    Board student;  // NOLINT
    InitBoard(student);
    DropDiskToBoard(student, DiskType::kPlayer1, 0);
    DropDiskToBoard(student, DiskType::kPlayer2, 0);
    REQUIRE(AreEqual(solution, student.board));
  }

  // clang-format off
   SECTION("Testing Bounds Error") {
    // clang-format on
    Board student;  // NOLINT
    InitBoard(student);
    REQUIRE_THROWS_AS(DropDiskToBoard(student, DiskType::kPlayer1, 8),
                      std::runtime_error);
    ;
    REQUIRE_THROWS_AS(DropDiskToBoard(student, DiskType::kPlayer1, -1),
                      std::runtime_error);
  }

  // clang-format off
   SECTION("Testing Full Columns") {
      DiskType solution[kBoardHeight][kBoardWidth] = { 
        {DiskType::kPlayer1, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kPlayer1, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kPlayer1, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
        {DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
    };
    
    Board student;  // NOLINT
    InitBoard(student);
    DropDiskToBoard(student, DiskType::kPlayer1, 0);
    DropDiskToBoard(student, DiskType::kPlayer2, 0);
    DropDiskToBoard(student, DiskType::kPlayer1, 0);
    DropDiskToBoard(student, DiskType::kPlayer2, 0);
    DropDiskToBoard(student, DiskType::kPlayer1, 0);
    DropDiskToBoard(student, DiskType::kPlayer2, 0);
    REQUIRE(AreEqual(solution, student.board));
    REQUIRE_THROWS_AS(DropDiskToBoard(student, DiskType::kPlayer1, 0), std::runtime_error);

    // clang-format on
  }
}

TEST_CASE("Testing Bound Function", "[board_bounds]") {
  SECTION("Testing Out of Bounds") {
    Board student;
    InitBoard(student);

    REQUIRE(!BoardLocationInBounds(0, -1));
    REQUIRE(!BoardLocationInBounds(-1, 0));
    REQUIRE(!BoardLocationInBounds(0, student.kBoardWidth));
    REQUIRE(!BoardLocationInBounds(student.kBoardHeight, 0));
  }

  SECTION("Testing In Bounds") {
    Board student;
    InitBoard(student);
    for (int row = 0; row < student.kBoardHeight; ++row) {
      for (int col = 0; col < student.kBoardWidth; ++col) {
        REQUIRE(BoardLocationInBounds(row, col));
      }
    }
  }
}

TEST_CASE("Seach for Winner Function", "[search_winner]") {
  SECTION("Testing Horizontal Direction: Base Cases") {
    Board student;
    for (int col = 0; col < student.kBoardWidth - 4; ++col) {
      InitBoard(student);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 1);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 2);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 3);
      REQUIRE(SearchForWinner(
          student, DiskType::kPlayer1, WinningDirection::kHorizontal));
      REQUIRE(!SearchForWinner(
          student, DiskType::kPlayer2, WinningDirection::kHorizontal));
    }
  }
  SECTION("Testing Horizontal Direction: Edge Cases") {
    Board student;
    for (int col = 0; col < student.kBoardWidth - 4; ++col) {
      InitBoard(student);
      for (int row = 0; row < student.kBoardHeight; ++row) {
        DropDiskToBoard(student, DiskType::kPlayer1, col);
        DropDiskToBoard(student, DiskType::kPlayer1, col + 1);
        DropDiskToBoard(student, DiskType::kPlayer1, col + 2);
        DropDiskToBoard(student, DiskType::kPlayer1, col + 3);
        REQUIRE(SearchForWinner(
            student, DiskType::kPlayer1, WinningDirection::kHorizontal));
        REQUIRE(!SearchForWinner(
            student, DiskType::kPlayer2, WinningDirection::kHorizontal));
      }
    }
  }
  SECTION("Testing Vertical Direction: Base Cases") {
    Board student;
    for (int col = 0; col < student.kBoardWidth; ++col) {
      InitBoard(student);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      REQUIRE(SearchForWinner(
          student, DiskType::kPlayer1, WinningDirection::kVertical));
      REQUIRE(!SearchForWinner(
          student, DiskType::kPlayer2, WinningDirection::kVertical));
    }
  }
  SECTION("Testing Vertical Direction: Edge Cases 1") {
    Board student;
    for (int col = 0; col < student.kBoardWidth; ++col) {
      InitBoard(student);
      DropDiskToBoard(student, DiskType::kPlayer2, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      REQUIRE(SearchForWinner(
          student, DiskType::kPlayer1, WinningDirection::kVertical));
      REQUIRE(!SearchForWinner(
          student, DiskType::kPlayer2, WinningDirection::kVertical));
    }
  }
  SECTION("Testing Vertical Direction: Edge Cases 2") {
    Board student;
    for (int col = 0; col < student.kBoardWidth; ++col) {
      InitBoard(student);
      DropDiskToBoard(student, DiskType::kPlayer2, col);
      DropDiskToBoard(student, DiskType::kPlayer2, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      REQUIRE(SearchForWinner(
          student, DiskType::kPlayer1, WinningDirection::kVertical));
      REQUIRE(!SearchForWinner(
          student, DiskType::kPlayer2, WinningDirection::kVertical));
    }
  }
  SECTION("Testing RightDiag Direction: Base Cases") {
    Board student;
    for (int col = 0; col < student.kBoardWidth - 4; ++col) {
      InitBoard(student);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 1);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 1);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 2);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 2);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 2);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 3);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 3);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 3);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 3);
      REQUIRE(SearchForWinner(
          student, DiskType::kPlayer1, WinningDirection::kRightDiag));
      REQUIRE(!SearchForWinner(
          student, DiskType::kPlayer2, WinningDirection::kRightDiag));
    }
  }
  SECTION("Testing RightDiag Direction: Edge Cases 1") {
    Board student;
    for (int col = 0; col < student.kBoardWidth - 3; ++col) {
      InitBoard(student);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 1);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 2);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 3);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 1);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 1);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 2);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 2);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 2);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 3);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 3);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 3);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 3);
      REQUIRE(SearchForWinner(
          student, DiskType::kPlayer1, WinningDirection::kRightDiag));
      REQUIRE(!SearchForWinner(
          student, DiskType::kPlayer2, WinningDirection::kRightDiag));
    }
  }

  SECTION("Testing LeftDiag Direction: Base Cases") {
    Board student;
    for (int col = student.kBoardWidth - 1; col > 3; --col) {
      InitBoard(student);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 1);
      DropDiskToBoard(student, DiskType::kPlayer1, col - 1);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 2);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 2);
      DropDiskToBoard(student, DiskType::kPlayer1, col - 2);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 3);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 3);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 3);
      DropDiskToBoard(student, DiskType::kPlayer1, col - 3);
      REQUIRE(SearchForWinner(
          student, DiskType::kPlayer1, WinningDirection::kLeftDiag));
      REQUIRE(!SearchForWinner(
          student, DiskType::kPlayer2, WinningDirection::kLeftDiag));
    }
  }
  SECTION("Testing LeftDiag Direction: Edge Cases 1") {
    Board student;
    for (int col = student.kBoardWidth - 1; col > 2; --col) {
      InitBoard(student);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col - 1);
      DropDiskToBoard(student, DiskType::kPlayer1, col - 2);
      DropDiskToBoard(student, DiskType::kPlayer1, col - 3);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 1);
      DropDiskToBoard(student, DiskType::kPlayer1, col - 1);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 2);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 2);
      DropDiskToBoard(student, DiskType::kPlayer1, col - 2);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 3);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 3);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 3);
      DropDiskToBoard(student, DiskType::kPlayer1, col - 3);
      REQUIRE(SearchForWinner(
          student, DiskType::kPlayer1, WinningDirection::kLeftDiag));
      REQUIRE(!SearchForWinner(
          student, DiskType::kPlayer2, WinningDirection::kLeftDiag));
    }
  }
}

TEST_CASE("Testing Check Winner Function", "[check_winner]") {
  SECTION("Testing Horizontal Direction: Base Cases") {
    Board student;
    for (int col = 0; col < student.kBoardWidth - 4; ++col) {
      InitBoard(student);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 1);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 2);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 3);
      REQUIRE(CheckForWinner(student, DiskType::kPlayer1));
      REQUIRE(!CheckForWinner(student, DiskType::kPlayer2));
    }
  }
  SECTION("Testing Vertical Direction: Base Cases") {
    Board student;
    for (int col = 0; col < student.kBoardWidth; ++col) {
      InitBoard(student);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      REQUIRE(CheckForWinner(student, DiskType::kPlayer1));
      REQUIRE(!CheckForWinner(student, DiskType::kPlayer2));
    }
  }
  SECTION("Testing RightDiag Direction: Base Cases") {
    Board student;
    for (int col = 0; col < student.kBoardWidth - 4; ++col) {
      InitBoard(student);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 1);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 1);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 2);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 2);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 2);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 3);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 3);
      DropDiskToBoard(student, DiskType::kPlayer2, col + 3);
      DropDiskToBoard(student, DiskType::kPlayer1, col + 3);
      REQUIRE(CheckForWinner(student, DiskType::kPlayer1));
      REQUIRE(!CheckForWinner(student, DiskType::kPlayer2));
    }
  }

  SECTION("Testing LeftDiag Direction: Base Cases") {
    Board student;
    for (int col = student.kBoardWidth - 1; col > 3; --col) {
      InitBoard(student);
      DropDiskToBoard(student, DiskType::kPlayer1, col);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 1);
      DropDiskToBoard(student, DiskType::kPlayer1, col - 1);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 2);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 2);
      DropDiskToBoard(student, DiskType::kPlayer1, col - 2);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 3);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 3);
      DropDiskToBoard(student, DiskType::kPlayer2, col - 3);
      DropDiskToBoard(student, DiskType::kPlayer1, col - 3);
      REQUIRE(CheckForWinner(student, DiskType::kPlayer1));
      REQUIRE(!CheckForWinner(student, DiskType::kPlayer2));
    }
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////