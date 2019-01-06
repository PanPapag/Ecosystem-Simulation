#pragma once

#include <cstdlib>
#include <ctime>

#include "Utilities.h"

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
    void SetPlantToken(char);
    char GetGround(void);
    char GetPlanthToken(void);
    bool ExistPlant(void);

  private:
    char ground;
    char plant_token;
    bool exist_plant;

};

class Ecosystem {

  public:
    Ecosystem(int,string);
    ~Ecosystem();

  private:
    int terrain_size;
    int max_no_of_plants;
    string current_season;
    coordinates *points;

    int no_of_grass;
    int no_of_algae;
    int no_of_maple;
    int no_of_oak;
    int no_of_pine;

    class Tile **terrain_grid;
    class Plant **plant_array;

    void PrintGrid(void);

    void MapGenerator(void);
    int GenerateRiver(void);
    int GenerateLake(void);
    int GenerateHills(void);
    int GenerateMeadow(void);
    void PlacePlants(void);
};
