#pragma once

#include <cstring>

#include "PlantInterface.h"

using namespace std;

class Animal {

  public:
    Animal(string, char, int, int, int, int, int, bool);
    Animal(string, char, int, int, int, int, int, int, int, int, bool);

    virtual ~Animal(){};

    string GetName(void);
    char GetToken(void);
    int GetSize(void);
    int GetMaxSize(void);
    int GetSpeed(void);
    int GetMaxSpeed(void);
    int GetNeededFood(void);
    int GetMaxNeededFood(void);
    int GetHunger(void);
    int GetEatCount(void);
    int GetCoordinateX(void);
    int GetCoordinateY(void);
    bool IsAlive(void);
    bool IsAdult(void);
    bool Hungry(void);
    bool IsInHeat(void);
    bool Hibernates(void);
    bool IsInHibernation(void);
    bool Pleased(void);
    bool IsHerbivore(void);
    bool IsCarnivore(void);

    void IncreaseSize(int);
    void IncreaseSpeed(int);
    void IncreaseNeededFood(int);
    void SetName(string);
    void Died(void);
    void SetHeat(bool);
    void SetHunger(bool);
    void SetHibernation(bool);

    void Move(int, int);
    void Raise(void);
  protected:

    string name;
    char token;
    int current_size;
    int max_size;
    int current_speed;
    int max_speed;
    int current_needed_food;
    int max_needed_food;
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
    Herbivore(string, char, int, int, int, int, int, int, int, int, bool, bool);
    ~Herbivore();

    bool CanClimb(void);
    void Eat(Plant*);

  private:
    bool can_climb;
};

class Carnivore : public Animal {

  public:
    Carnivore(string, char, int, int, int, int, int, bool,int, int);
    ~Carnivore();

    int GetAttack(void);
    int GetDefence(void);

  private:
    int attack;
    int defence;
};
