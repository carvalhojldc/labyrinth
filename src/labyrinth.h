#ifndef LABYRINTH_H
#define LABYRINTH_H

#include "map.h"

class Labyrinth {

private:
    float costDiagonal;
    float costVertical;
    float costHorizontal;

public:
    Map* map;

public:
    Labyrinth();

    Labyrinth(Map *map, float costHorizontal, float costVertical, float costDiagonal);

    Labyrinth(int lines, int columns, \
        float costHorizontal, float costVertical, float costDiagonal);

    ~Labyrinth();

    void setMap(Map* map);

    void setCostHorizontal(float costHorizontal);

    void setCostVertical(float costVertical);

    void setCostDiagonal(float costDiagonal);

    void setLabyrinth(Map* map, float costHorizontal, float costVertical, float costDiagonal);

    Map* getMap() const;

    float getCostVertical() const;

    float getCostHorizontal() const;

    float getCostDiagonal() const;
};

#endif // LABYRINTH_H
