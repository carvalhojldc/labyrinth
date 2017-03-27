#include "labyrinth.h"

Labyrinth::Labyrinth() {
    map = new Map();

    costDiagonal   = 0.0;
    costVertical   = 0.0;
    costHorizontal = 0.0;
}

Labyrinth::Labyrinth(Map *map, \
    float costHorizontal, float costVertical, float costDiagonal)
{
    setMap(map);
    setCostHorizontal(costHorizontal);
    setCostVertical(costVertical);
    setCostDiagonal(costDiagonal);
}

Labyrinth::Labyrinth(int lines, int columns, \
    float costHorizontal, float costVertical, float costDiagonal)
{
    this->map = new Map(lines, columns);

    this->costDiagonal   = costDiagonal;
    this->costVertical   = costVertical;
    this->costHorizontal = costHorizontal;
}

Labyrinth::~Labyrinth()
{
    delete map;
}

void Labyrinth::setMap(Map* map) {
    delete map;
    map = nullptr;
    this->map = map;
}

void Labyrinth::setCostHorizontal(float costHorizontal)
{ this->costHorizontal = costHorizontal; }

void Labyrinth::setCostVertical(float costVertical)
{ this->costVertical = costVertical; }

void Labyrinth::setCostDiagonal(float costDiagonal)
{ this->costDiagonal = costDiagonal; }

void Labyrinth::setLabyrinth(Map* map, float costHorizontal, float costVertical, float costDiagonal) {
    setMap(map);
    setCostHorizontal(costHorizontal);
    setCostVertical(costVertical);
    setCostDiagonal(costDiagonal);
}

Map* Labyrinth::getMap() const
{ return map; }

float Labyrinth::getCostVertical() const
{ return costVertical; }

float Labyrinth::getCostHorizontal() const
{ return costHorizontal; }

float Labyrinth::getCostDiagonal() const
{ return costDiagonal; }
