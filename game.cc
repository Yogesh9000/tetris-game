#include "game.hpp"
#include "blocks.hpp"
#include <raylib.h>
#include <vector>

Game::Game() {
  grid = Grid();
  blocks = GetAllBlock();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  lastUpdateTime = 0;
  score = 0;
  gameOver = false;
}

std::vector<Block> Game::GetAllBlock() {
  return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

Block Game::GetRandomBlock() {
  int randInt = GetRandomValue(0, (int)blocks.size() - 1);
  return blocks[randInt];
}

void Game::Draw() {
  grid.Draw();
  if (!gameOver)
    currentBlock.Draw(11, 11);
  switch (nextBlock.GetId()) {
  case 3:
    nextBlock.Draw(255, 255);
    break;
  case 4:
    nextBlock.Draw(255, 280);
    break;
  default:
    nextBlock.Draw(270, 270);
  }
}

void Game::Update() {
  HandleInput();
  if (IsEventTriggered(0.2))
    MoveBlockDown();
  int rowsCleared = grid.ClearCompletedRows();
  UpdateScore(rowsCleared, 0);
}

void Game::MoveBlockLeft() {
  if (!gameOver) {
    currentBlock.MoveBlock(-1, 0);
    if (IsBlockOutsideGrid() || !BlockFits())
      currentBlock.MoveBlock(1, 0);
  }
}
void Game::MoveBlockRight() {
  if (!gameOver) {
    currentBlock.MoveBlock(1, 0);
    if (IsBlockOutsideGrid() || !BlockFits())
      currentBlock.MoveBlock(-1, 0);
  }
}
void Game::MoveBlockDown() {
  if (!gameOver) {

    currentBlock.MoveBlock(0, 1);
    if (IsBlockOutsideGrid() || !BlockFits()) {
      currentBlock.MoveBlock(0, -1);
      LockBlock();
    }
  }
}

void Game::RotateBlock() {
  if (!gameOver) {
    currentBlock.RotateBlock();
    if (IsBlockOutsideGrid() || !BlockFits())
      currentBlock.UndoRotation();
  }
}

void Game::HandleInput() {
  int pressedKey = GetKeyPressed();
  if (gameOver && pressedKey != 0) {
    gameOver = false;
    ResetGame();
  }
  switch (pressedKey) {
  case KEY_LEFT:
    MoveBlockLeft();
    break;
  case KEY_RIGHT:
    MoveBlockRight();
    break;
  case KEY_UP:
    RotateBlock();
    break;
  case KEY_DOWN:
    MoveBlockDown();
    UpdateScore(0, 1);
    break;
  }
}

bool Game::IsEventTriggered(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

bool Game::IsBlockOutsideGrid() {
  auto cells = currentBlock.getCellPositions();
  for (auto cell : cells) {
    if (grid.IsCellOutside(cell.first, cell.second))
      return true;
  }
  return false;
}

void Game::LockBlock() {
  auto cells = currentBlock.getCellPositions();
  int id = currentBlock.GetId();

  for (auto cell : cells) {
    grid.SetCellColor(cell.first, cell.second, id);
  }

  currentBlock = nextBlock;
  if (!BlockFits())
    gameOver = true;
  nextBlock = GetRandomBlock();
}

bool Game::BlockFits() {
  auto cells = currentBlock.getCellPositions();
  for (auto cell : cells) {
    if (!grid.IsCellEmpty(cell.first, cell.second))
      return false;
  }
  return true;
}

void Game::ResetGame() {
  grid.InitializeArray();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  score = 0;
}

bool Game::GetGameOver() { return this->gameOver; }

void Game::UpdateScore(int rowsCleared, int blockDown) {
  switch (rowsCleared) {
  case 1:
    score += 100;
    break;
  case 2:
    score += 300;
    break;
  case 3:
    score += 500;
  }
  score += blockDown;
}

int Game::GetGameScore() { return this->score; }
