#pragma once

#include <stdint.h>

class Game
{
private:
  uint8_t points_1;
  uint8_t points_2;

  uint8_t max_points;

  bool in_play = false;

public:
  void begin(uint8_t maxP);
  void start();
  void end();
  bool inProgress();
  bool predictedVictory();
  bool predictedVictoryForOne();
  bool predictedVictoryForTwo();
  uint8_t getPlayerOnePoints();
  uint8_t getPlayerTwoPoints();
  void pointForPlayerOne();
  void pointForPlayerTwo();
};