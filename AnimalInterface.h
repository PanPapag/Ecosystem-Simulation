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
    int GetCoordinateX(void);
    int GetCoordinateY(void);
    bool IsAlive(void);
    bool Hungry(void);
    bool IsInHeat(void);
    bool Hibernates(void);
    bool IsInHibernation(void);
    bool Pleased(void);
    bool IsHerbivore(void);
    bool IsCarnivore(void);
    bool IsAdult();

    void IncreaseSize(int);
    void IncreaseSpeed(int);
    void IncreaseNeededFood(int);
    void SetName(string);
    void SetHeat(bool);
    void SetAlive(bool);
    void IncreaseHunger(void);
    void ResetHunger(void);
    void SetHunger(bool);
    void SetHibernation(bool);

    void Move(int, int);
    virtual bool CheckIfAdult(void) = 0;
    virtual void Raise(void) = 0;
    Animal* Reproduct(void);

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
    int coordinate_x;
    int coordinate_y;
    bool is_alive;
    bool is_adult;
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
    void Raise(void);
    void Eat(int);
    bool CheckIfAdult(void);
    int GetDaysNotHungry(void);
    void IncreaseDaysNotHungry(void);
    void ResetDaysNotHungry(void);

  private:
    bool can_climb;
    int days_not_hungry;
};

class Carnivore : public Animal {

  public:
    Carnivore(string, char, int, int, int, int, int, bool,int, int);
    Carnivore(string, char, int, int, int, int, int, int, int, int, bool, int, int, int, int);
    ~Carnivore();

    int GetAttack(void);
    int GetDefence(void);
    int GetMaxAttack(void);
    int GetMaxDefence(void);
    void IncreaseAttack(int);
    void IncreaseDefence(int);
    bool CheckIfAdult(void);

    void Raise(void);
    void Eat();

  private:
    int current_attack;
    int current_defence;
    int max_attack;
    int max_defence;
};

int Fight(Carnivore*, Herbivore*);
int Fight(Herbivore*, Carnivore*);
int Fight(Carnivore*, Carnivore*);
int Fight(Herbivore*, Herbivore*);
