#include <Arduino.h>
#include <Game.h>

// Crea el modulo de juego.
Game::Game(uint8_t maxP)
{
  max_points = maxP;
}

// Formatea el juego.
void Game::begin()
{
  points_1 = 0;
  points_2 = 0;

  in_play = false;
  predicted = false;

  uint8_t timeLastPoint = 0;
}

// Inicia el juego.
void Game::start()
{
  bool in_play = true;
}
void Game::end()
{
  bool in_play = false;
}

// Verifica si hay un juego en progreso.
bool Game::inProgress()
{
  return in_play;
}

// Verifica si ya se realizó la predicción.
bool Game::isPredicted()
{
  return predicted;
}

// Predice si la victoria está decidida para alguno de los dos jugadores.
bool Game::predictedVictory()
{
  if (predictedVictoryForOne() || predictedVictoryForTwo())
    return true;
  else
    return false;
}

// Predice si la victoria está decidida para el jugador uno.
bool Game::predictedVictoryForOne()
{
  if (points_1 >= max_points / 2)
    return true;
  else
    return false;
}

// Predice si la victoria está decidida para el jugador dos.
bool Game::predictedVictoryForTwo()
{
  if (points_1 >= max_points / 2)
    return true;
  else
    return false;
}

// Acredita un punto al jugador uno.
void Game::pointForPlayerOne()
{
  if (millis() - timeLastPoint < MAX_TIME)
    points_1 += 1;
  if (predictedVictoryForOne())
    predicted = true;
  if (points_1 >= max_points)
    end();
}

// Acredita un punto al jugador dos.
void Game::pointForPlayerTwo()
{
  if (millis() - timeLastPoint < MAX_TIME)
    points_2 += 1;
  if (predictedVictoryForTwo())
    predicted = true;
  if (points_2 >= max_points)
    end();
}

// Devuelve los puntos del jugador uno.
uint8_t Game::getPlayerOnePoints()
{
  return points_1;
}

// Devuelve los puntos del jugador dos.
uint8_t Game::getPlayerTwoPoints()
{
  return points_2;
}