#pragma once
#include "block.hpp"
#include "grid.hpp"
#include <vector>
#include <raylib.h>

class Game {
public:
  Game();
  void Draw();
  void Update();
  void MoveBlockLeft();
  void MoveBlockRight();
  void MoveBlockDown();
  void RotateBlock();
  void HandleInput();
  bool IsEventTriggered(double interval);
  bool IsBlockOutsideGrid();
  void LockBlock();
  bool BlockFits();
  std::vector<Block> GetAllBlock();
  Block GetRandomBlock();
  void ResetGame();
  bool GetGameOver();
  void UpdateScore(int rowsCleared, int blockDown);
  int GetGameScore();

private:
  Grid grid;
  Block currentBlock;
  Block nextBlock;
  double lastUpdateTime;
  std::vector<Block> blocks;
  int score;
  bool gameOver;
};
