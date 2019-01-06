#pragma once

#include "PlantInterface.h"
#include <cstring>

class Animal {

  public:
    Animal(string, char, int, int, int, int, int, int, bool);
    virtual ~Animal(void);

    string GetName(void);
    char GetToken(void);
    int GetSize(void);
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
    void Hibernation(bool);

    void Move(int, int);
  protected:
    string name;
    char token;
    int size;
    int hunger_count;
    int eaten_food;
    int eat_count;
    int coordinate_x;
    int coordinate_y;
    bool is_alive;
    bool is_hungry;
    bool in_heat;
    int speed;
    bool hibernates;
    bool in_hibernation;
};

class Herbivores : public Animal {

  public:
    Herbivores(string, char, int, int, int, int, int, int, bool, bool, int);

    bool CanClimb(void);
    int GetNeededFood(void);
    bool Pleased(void);
    void Eat(Plant*);
  private:
    bool can_climb;
    int needed_food;
};

class Carnivores : public Animal {

  public:

  private:
    int attack;
    int defence;
};
