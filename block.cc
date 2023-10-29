#include "block.hpp"
#include "colors.hpp"
#include <raylib.h>
#include <utility>

Block::Block() {
  colors = GetCellColors();
  cellSize = 30;
  cellRotation = 0;
  rowOffset = 0;
  colOffset = 0;
}

void Block::Draw(int col, int row) {
  for(auto cell: getCellPositions()) {
    DrawRectangle(cell.first*cellSize+col, cell.second*cellSize+row, cellSize-1, cellSize-1, colors[GetId()]);
  }
}

std::vector<std::pair<int, int>> Block::getCellPositions() {
  auto tiles = GetCells(cellRotation);
  for(auto &tile : tiles) {
    tile.first = tile.first + colOffset;
    tile.second = tile.second + rowOffset;
  }
  return tiles;
}

int Block::GetId() {
  return this->id;
}

std::vector<std::pair<int, int>> Block::GetCells(int i) {
  return this-> cells[i];
}

void Block::SetId(int i) {
  this->id = i;
}

void Block::SetCells(int i, std::vector<std::pair<int, int>> cell) {
  this->cells[i] = cell;
}

void Block::MoveBlock(int col, int row) {
  colOffset += col;
  rowOffset += row;
}

std::pair<int, int> Block::GetOffset() {
  return {colOffset, rowOffset};
}

void Block::RotateBlock() {
  cellRotation++;
  if(cellRotation == (int)cells.size())
    cellRotation = 0;
}

void Block::UndoRotation() {
  cellRotation--;
  if(cellRotation == -1)
    cellRotation = (int)cells.size()-1;
}
