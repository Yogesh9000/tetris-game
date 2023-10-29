#pragma once

#include <raylib.h>
#include <utility>
#include <vector>
#include "colors.hpp"

class Grid {
public:
  Grid();
  void Draw();
  void InitializeArray();
  void PrintArray();
  bool IsCellOutside(int col, int row);
  void SetCellColor(int col, int row, int id);
  bool IsCellEmpty(int col, int row);
  void ClearGridRow(int row);
  int ClearCompletedRows();
  bool IsGridRowComplete(int i);
  void MoveGridRow(int row, int count);

private:
  int numRows;
  int numCols;
  int cellSize;
  std::vector<Color> colors;
  int **grid;
};
