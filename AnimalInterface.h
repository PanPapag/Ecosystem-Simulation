#pragma once

#include <cstring>

#include "PlantInterface.h"
#include "DefaultValues.h"

using namespace std;

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

class Herbivore : public Animal {

  public:
    Herbivore(string, char, int, int, int, int, int, bool, bool);
    ~Herbivore();
    bool CanClimb(void);
    bool Pleased(void);
    void Eat(Plant*);

  private:
    bool can_climb;
};

class Carnivore : public Animal {

  public:

  private:
    int attack;
    int defence;
};
