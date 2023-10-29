#include "blocks.hpp"

LBlock::LBlock() {
  SetId(1);
  SetCells(0, {{2, 0}, {0, 1}, {1, 1}, {2, 1}});
  SetCells(1, {{1, 0}, {1, 1}, {1, 2}, {2, 2}});
  SetCells(2, {{0, 1}, {1, 1}, {2, 1}, {0, 2}});
  SetCells(3, {{0, 0}, {1, 0}, {1, 1}, {1, 2}});
  MoveBlock(3, 0);
}

JBlock::JBlock() {
  SetId(2);
  SetCells(0, {{0, 0}, {0, 1}, {1, 1}, {2, 1}});
  SetCells(1, {{1, 0}, {2, 0}, {1, 1}, {1, 2}});
  SetCells(2, {{0, 1}, {1, 1}, {2, 1}, {2, 2}});
  SetCells(3, {{1, 0}, {1, 1}, {0, 2}, {1, 2}});
  MoveBlock(3, 0);
}

IBlock::IBlock() {
  SetId(3);
  SetCells(0, {{0, 1}, {1, 1}, {2, 1}, {3, 1}});
  SetCells(1, {{2, 0}, {2, 1}, {2, 2}, {2, 3}});
  SetCells(2, {{0, 2}, {1, 2}, {2, 2}, {3, 2}});
  SetCells(3, {{1, 0}, {1, 1}, {1, 2}, {1, 3}});
  MoveBlock(3, 0);
}

OBlock::OBlock() {
  SetId(4);
  SetCells(0, {{0, 0}, {1, 0}, {0, 1}, {1, 1}});
  SetCells(1, {{0, 0}, {1, 0}, {0, 1}, {1, 1}});
  SetCells(2, {{0, 0}, {1, 0}, {0, 1}, {1, 1}});
  SetCells(3, {{0, 0}, {1, 0}, {0, 1}, {1, 1}});
  MoveBlock(4, 0);
}

SBlock::SBlock() {
  SetId(5);
  SetCells(0, {{1, 0}, {2, 0}, {0, 1}, {1, 1}});
  SetCells(1, {{1, 0}, {1, 1}, {2, 1}, {2, 2}});
  SetCells(2, {{1, 0}, {2, 0}, {0, 1}, {1, 1}});
  SetCells(3, {{0, 0}, {0, 1}, {1, 1}, {1, 2}});
  MoveBlock(3, 0);
}

TBlock::TBlock() {
  SetId(6);
  SetCells(0, {{1, 0}, {0, 1}, {1, 1}, {2, 1}});
  SetCells(1, {{1, 0}, {1, 1}, {2, 1}, {1, 2}});
  SetCells(2, {{0, 1}, {1, 1}, {2, 1}, {1, 2}});
  SetCells(3, {{1, 0}, {0, 1}, {1, 1}, {1, 2}});
  MoveBlock(3, 0);
}

ZBlock::ZBlock() {
  SetId(7);
  SetCells(0, {{0, 0}, {1, 0}, {1, 1}, {2, 1}});
  SetCells(1, {{2, 0}, {1, 1}, {2, 1}, {1, 2}});
  SetCells(2, {{0, 1}, {1, 1}, {1, 2}, {2, 2}});
  SetCells(3, {{1, 0}, {0, 1}, {1, 1}, {0, 2}});
  MoveBlock(3, 0);
}
