#include <Arduino.h>
#include <Game.h>

Game::Game(uint8_t maxP)
{
  max_points = maxP;
}

void Game::begin()
{
  points_1 = 0;
  points_2 = 0;

  in_play = false;
  
  uint8_t timeLastPoint = 0;
}

void Game::start()
{
  bool in_play = true;
}
void Game::end()
{
  bool in_play = false;
}

bool Game::inProgress()
{
  return in_play;
}

bool Game::predictedVictory()
{
  if (predictedVictoryForOne() || predictedVictoryForTwo())
    return true;
  else
    return false;
}

bool Game::predictedVictoryForOne()
{
  if (points_1 >= max_points / 2)
    return true;
  else
    return false;
}

bool Game::predictedVictoryForTwo()
{
  if (points_1 >= max_points / 2)
    return true;
  else
    return false;
}

void Game::pointForPlayerOne()
{
  if (millis() - timeLastPoint < MAX_TIME)
    points_1 += 1;
  if (points_1 >= max_points)
    end();
}
void Game::pointForPlayerTwo()
{
  if (millis() - timeLastPoint < MAX_TIME)
    points_2 += 1;
  if (points_2 >= max_points)
    end();
}

uint8_t Game::getPlayerOnePoints()
{
  return points_1;
}
uint8_t Game::getPlayerTwoPoints()
{
  return points_2;
}