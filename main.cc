#include <iostream>
#include <raylib.h>
#include "game.hpp"
#include "colors.hpp"

int main() {
  InitWindow(500, 620, "Tetris");
  SetTargetFPS(60);
  
  Font font = LoadFontEx("assets/JetBrainsMonoNerdFontMono-Regular.ttf", 64, 0, 0);

  Game game = Game();

  while (!WindowShouldClose()) {
    game.Update();
    BeginDrawing();
    ClearBackground(darkBlue);
    DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
    DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
    if(game.GetGameOver())
      DrawTextEx(font, "Game Over", {320, 450}, 38, 2, WHITE);
    DrawRectangleRounded({320, 55, 170, 60}, 0.3f, 6, lightBlue);
    char scoreText[10];
    std::sprintf(scoreText, "%d", game.GetGameScore());
    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
    DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);
    DrawRectangleRounded({320, 215, 170, 180}, 0.3f, 6, lightBlue);
    game.Draw();
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
