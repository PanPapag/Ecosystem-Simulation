#pragma once

#include <cstdlib>
#include <ctime>

#include "DefaultValues.h"
#include "Utilities.h"

using namespace std;

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
    int max_no_of_animals;
    string current_season;
    coordinates *points;

    int no_of_grass;
    int no_of_algae;
    int no_of_maple;
    int no_of_oak;
    int no_of_pine;

    int no_of_deer;
    int no_of_rabbit;
    int no_of_groundhog;
    int no_of_salmon;
    int no_of_fox;
    int no_of_bear;
    int no_of_wolf;

    class Tile **terrain_grid;
    class Plant **plant_array;
    class Animal **animal_array;

    void PrintGrid(void);
    void PrintPlantStatistics(void);
    void PrintAnimalStatistics(void);

    void MapGenerator(void);
    int GenerateRiver(void);
    int GenerateLake(void);
    int GenerateHills(void);
    int GenerateMeadow(void);
    void PlacePlants(void);
    void PlaceAnimals(void);
};
