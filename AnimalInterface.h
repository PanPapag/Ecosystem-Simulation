#pragma once

#include <cstring>

#include "PlantInterface.h"

using namespace std;

#define HERB_TOKEN 'H'
#define CARN_TOKEN 'C'

#define Y_DEER_SIZE 2
#define Y_DEER_SPEED 4
#define Y_DEER_NEED_FOOD 4
#define A_DEER_SIZE 5
#define A_DEER_SPEED 8
#define A_DEER_NEED_FOOD 8
#define DEER_CLIMB false
#define DEER_HIBERNATION false

#define Y_RABBIT_SIZE 1
#define Y_RABBIT_SPEED 2
#define Y_RABBIT_NEED_FOOD 2
#define A_RABBIT_SIZE 2
#define A_RABBIT_SPEED 6
#define A_RABBIT_NEED_FOOD 4
#define RABBIT_CLIMB false
#define RABBIT_HIBERNATION false

#define Y_GROUNDHOG_SIZE 2
#define Y_GROUNDHOG_SPEED 3
#define Y_GROUNDHOG_NEED_FOOD 3
#define A_GROUNDHOG_SIZE 3
#define A_GROUNDHOG_SPEED 5
#define A_GROUNDHOG_NEED_FOOD 5
#define GROUNDHOG_CLIMB true
#define GROUNDHOG_HIBERNATION false

#define A_SALMON_SIZE 1
#define A_SALMON_SPEED 5
#define A_SALMON_NEED_FOOD 1
#define SALMON_CLIMB false
#define SALMON_HIBERNATION false

#define Y_FOX_SIZE 1
#define Y_FOX_SPEED 2
#define Y_FOX_NEED_FOOD 2
#define Y_FOX_ATTACK 1
#define Y_FOX_DEFENCE 1
#define A_FOX_SIZE 4
#define A_FOX_SPEED 6
#define A_FOX_NEED_FOOD 6
#define A_FOX_ATTACK 5
#define A_FOX_DEFENCE 5
#define FOX_HIBERNATION false

#define Y_WOLF_SIZE 1
#define Y_WOLF_SPEED 2
#define Y_WOFL_NEED_FOOD 2
#define Y_WOLF_ATTACK 2
#define Y_WOLF_DEFENCE 2
#define A_WOLF_SIZE 7
#define A_WOLF_SPEED 8
#define A_WOFL_NEED_FOOD 8
#define A_WOLF_ATTACK 8
#define A_WOLF_DEFENCE 6
#define WOLF_HIBERNATION false

#define Y_BEAR_SIZE 3
#define Y_BEAR_SPEED 4
#define Y_BEAR_NEED_FOOD 5
#define Y_BEAR_ATTACK 6
#define Y_BEAR_DEFENCE 6
#define A_BEAR_SIZE 10
#define A_BEAR_SPEED 4
#define A_BEAR_NEED_FOOD 10
#define A_BEAR_ATTACK 10
#define A_BEAR_DEFENCE 10
#define BEAR_HIBERNATION true

class Animal {

  public:
    Animal(string, char, int, int, int, int, int, bool);
    virtual ~Animal(){};

    string GetName(void);
    char GetToken(void);
    int GetSize(void);
    int GetNeededFood(void);
    int GetHunger(void);
    int GetEatCount(void);
    int GetCoordinateX(void);
    int GetCoordinateY(void);
    bool Alive(void);
    bool Hungry(void);
    bool IsInHeat(void);
    int GetSpeed(void);
    bool Hibernates(void);
    bool IsInHibernation(void);
    bool IsHerbivore(void);
    bool IsCarnivore(void);

    void IncreaseSize(int);
    void SetName(string);
    void Died(void);
    void SetHeat(bool);
    void SetHunger(bool);
    void SetHibernation(bool);

    void Move(int, int);

  protected:

    string name;
    char token;
    int size;
    int speed;
    int needed_food;
    int hunger_count;
    int eaten_food;
    int eat_count;
    int coordinate_x;
    int coordinate_y;
    bool is_alive;
    bool is_hungry;
    bool in_heat;
    bool hibernates;
    bool in_hibernation;
};

class Herbivores : public Animal {

  public:
    Herbivores(string, char, int, int, int, int, int, bool, bool);
    ~Herbivores();
    bool CanClimb(void);
    bool Pleased(void);
    void Eat(Plant*);

  private:
    bool can_climb;
};

class Carnivores : public Animal {

  public:

  private:
    int attack;
    int defence;
};
