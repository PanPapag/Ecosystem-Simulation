#pragma once

#include <cstdlib>
#include <ctime>
#include <list>
#include <utility>

#include "DefaultValues.h"
#include "Utilities.h"

using namespace std;

class Tile {

  public:
    Tile();
    ~Tile();
    void SetGround(char);
    void SetPlantToken(char);
    void AddAnimalIndex(int);
    void RemoveAnimalIndex(int);
    char GetGround(void);
    char GetPlantToken(void);
    bool ExistPlant(void);
    list <int> & GetAnimalList(void);

  private:
    char ground;
    char plant_token;
    list <int> animal_index_list;

};

class Ecosystem {

  public:
    Ecosystem(int,string);
    ~Ecosystem();
    void RunEcosystem(int);
    void PrintSystem(int);

  private:
    string Seasons[4];
    int season_index;
    int terrain_size;
    int max_no_of_plants;
    int max_no_of_animals;
    string current_season;
    coordinates *points;

    int growth_period_plants;
    int growth_period_animals;
    int breeding_rep_period_plants;
    int breeding_rep_period_herb;
    int breeding_rep_period_carn;

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

    void DailyReset(int);
    void CheckDeadEntities(void);
    void AnimalMovement(void);
    void AnimalEating(void);
    coordinates FindFreeTile(int,int,int);
    void ApplySeason(void);

    void AnimalBreedingCarnivores(void);
    void AnimalBreedingHerbivores(void);
    void PlantBreeding(void);

    void PrintGrid(void);
    void PrintPlantStatistics(void);
    void PrintAnimalStatistics(void);

    int TotalAnimals(void);
    int TotalCarnivores(void);
    int TotalHerbivores(void);
    int TotalPlants(void);

    void MapGenerator(void);
    int GenerateRiver(void);
    int GenerateLake(void);
    int GenerateHills(void);
    int GenerateMeadow(void);
    void PlacePlants(void);
    void PlaceAnimals(void);
};
