#pragma once

#include <stdint.h>

class Game
{
private:
  uint8_t points_1;
  uint8_t points_2;

  uint8_t max_points;

  bool in_play = false;
  bool predicted = false;

  uint16_t MAX_TIME = 500;
  uint8_t timeLastPoint;

public:
  Game(uint8_t maxP);
  void begin();
  void start();
  void end();
  bool inProgress();
  bool isPredicted();
  bool predictedVictory();
  bool predictedVictoryForOne();
  bool predictedVictoryForTwo();
  uint8_t getPlayerOnePoints();
  uint8_t getPlayerTwoPoints();
  void pointForPlayerOne();
  void pointForPlayerTwo();
};