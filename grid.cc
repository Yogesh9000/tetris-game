#include "grid.hpp"
#include "colors.hpp"
#include <iostream>
#include <raylib.h>

Grid::Grid() {
  numRows = 20;
  numCols = 10;
  cellSize = 30;
  colors = GetCellColors();
  grid = new int*[numRows];
  for(int i=0; i<numRows; i++) {
    grid[i] = new int[numCols];
  }
  InitializeArray();
}

void Grid::InitializeArray() {
  for(int i=0; i<numRows; i++) {
    for(int j=0; j<numCols; j++) {
      grid[i][j] = 0;
    }
  }
}

void Grid::PrintArray() {
  for(int i=0; i<numRows; i++) {
    for(int j=0; j<numCols; j++) {
      std::cout << grid[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void Grid::Draw() {
  for(int i=0; i<numRows; i++) {
    for(int j=0; j<numCols; j++) {
      DrawRectangle(j*cellSize+11, i*cellSize+11, cellSize-1, cellSize-1, colors[grid[i][j]]);
    }
  }
}

bool Grid::IsCellOutside(int col, int row) {
  if(row >= 0 && row < numRows && col >= 0 && col < numCols)
    return false;
  return true;
}

void Grid::SetCellColor(int col, int row, int id) {
  grid[row][col] = id;
}

bool Grid::IsCellEmpty(int col, int row) {
  if(grid[row][col] == 0)
    return true;
  return false;
}

bool Grid::IsGridRowComplete(int i) {
  for(int j=0; j<numCols; j++) {
    if(grid[i][j] == 0)
      return false;
  }
  return true;
}

void Grid::MoveGridRow(int row, int count) {
  for(int j=0; j<numCols; j++) {
    grid[row+count][j] = grid[row][j];
    grid[row][j] = 0;
  }
}

void Grid::ClearGridRow(int row) {
  for(int col = 0; col < numCols; col++) {
    grid[row][col] = 0;
  }
}

int Grid::ClearCompletedRows() {
  int count = 0;
  for(int i = numRows-1; i >= 0; i--) {
    if(IsGridRowComplete(i)) {
      ClearGridRow(i);
      count++;
    }
    else if(count > 0)
      MoveGridRow(i, count);
  }
  return count;
}
