#pragma once

#include <map>
#include <raylib.h>
#include <vector>
#include <utility>
#include "colors.hpp"

class Block {
public:
  Block();
  void Draw(int col, int row);
  std::vector<std::pair<int,int>> getCellPositions();
  void SetId(int i);
  void SetCells(int i, std::vector<std::pair<int, int>> cell);
  int GetId();
  std::vector<std::pair<int, int>> GetCells(int i);
  void MoveBlock(int row, int col);
  std::pair<int, int> GetOffset();
  void RotateBlock();
  void UndoRotation();

private:
  int id;
  int rowOffset;
  int colOffset;
  int cellRotation;
  int cellSize;
  std::map<int, std::vector<std::pair<int,int>>> cells;
  std::vector<Color> colors;
};
