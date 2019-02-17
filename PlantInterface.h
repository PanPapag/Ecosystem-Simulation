#pragma once

#include <cstring>
#include "Utilities.h"
#include "DefaultValues.h"

using namespace std;

class Plant {

  public:
    Plant(string, int, int, char, int, int, bool, int);
    virtual ~Plant(){};
    bool Reproduced(void);
    bool IsAlive(void);
    bool IsSeeded(void);
    int GetCoordinateX(void);
    int GetCoordinateY(void);
    int GetBreedingProb(void);
    int GetIllnessProb(void);
    int GetLifeFactor(void);
    char GetToken(void);
    string GetName(void);
    virtual void EatenByAnimal(int) = 0;
    virtual void Grow(void) = 0;

  protected:
    string name;
    char token;
    bool alive;
    bool seeded;
    int coordinate_x;
    int coordinate_y;
    int breeding_prob;
    int illness_prob;
    int life_factor;
};

class Seedless : public Plant {

  public:
    Seedless(string, int, int, char, int, int, bool, int, int);
    ~Seedless();
    void LoseLife(int);
    void EatenByAnimal(int);
    void Grow(void);
    bool Reproduced(void);
    int GetLife();

  private:
    int life;
};

class Leaves {

  public:
    Leaves(int,int);
    ~Leaves();
    int GetNumber(void);
    int GetSize(void);
    void IncreaseSize(void);
    void DecreaseSize(void);
    void IncreaseNumber(int);
    void DecreaseNumber(int);

  private:
    int size;
    int quantity;
};

class Seeded : public Plant{

  public:
    Seeded(string, int, int, char, int, int, bool, int, int, int, int);
    ~Seeded();
    void EatenByAnimal(int);
    void Grow(void);
    bool Reproduced(void);
    int GetSeeds(void);
    Leaves GetFoliage(void);

  private:
    Leaves foliage;
    int seeds;
};
