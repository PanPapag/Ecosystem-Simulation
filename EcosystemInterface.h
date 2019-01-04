#ifndef __ECOSYSTEM__
#define __ECOSYSTEM__

#include <cstdlib>
#include <ctime>

using namespace std;

#define WATER_TILE '#'
#define HILL_TILE '^'
#define MEADOW_TILE '"'
#define EMPTY '.'

#define DIVERSION_FACTOR 30

#define LEFT 0
#define RIGHT 1

class Tile {

  public:
    Tile();
    ~Tile();
    void SetGround(char);
    char GetGround();

  private:
    char ground;

};

class Ecosystem {

  public:
    Ecosystem(int,string);
    ~Ecosystem();
    void PrintGrid();

  private:
    int terrain_size;
    string current_season;

    class Tile **terrain_grid;
    class Plant **plant_array;

    void MapGenerator();
    int GenerateRiver();
    int GenerateLake();
    int GenerateHills();
    int GenerateMeadow();
};

#endif
