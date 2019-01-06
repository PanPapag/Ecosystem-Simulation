#pragma once

#include <cstring>
#include "Utilities.h"

using namespace std;

#define ALIVE true

#define GRASS_TOKEN 'G'
#define GRASS_LIFE 5
#define GRASS_BREEDING 15
#define GRASS_ILLNESS 15
#define GRASS_LIFE_FACTOR 4

#define ALGAE_TOKEN 'A'
#define ALGAE_LIFE 5
#define ALGAE_BREEDING 25
#define ALGAE_ILLNESS 25
#define ALGAE_LIFE_FACTOR 2

#define MAPLE_TOKEN 'M'
#define MAPLE_FOLIAGE 5
#define MAPLE_SEEDS 10
#define MAPLE_SIZE 2
#define MAPLE_BREEDING 5
#define MAPLE_ILLNESS 5
#define MAPLE_LIFE_FACTOR 10

#define OAK_TOKEN 'O'
#define OAK_FOLIAGE 30
#define OAK_SEEDS 15
#define OAK_SIZE 5
#define OAK_BREEDING 20
#define OAK_ILLNESS 20
#define OAK_LIFE_FACTOR 15

#define PINE_TOKEN 'P'
#define PINE_FOLIAGE 40
#define PINE_SEEDS 20
#define PINE_SIZE 5
#define PINE_BREEDING 15
#define PINE_ILLNESS 15
#define PINE_LIFE_FACTOR 20

class Plant {

  public:
    Plant(string, int, int, char, int, int, bool, int);
    virtual ~Plant(){};
    bool Reproduced(void);
    bool IsAlive(void);
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
    void LoseLife(void);
    void EatenByAnimal(int);
    void Grow(void);
    bool Reproduced(void);
    int GetLife();

  private:
    int life;
};

class Grass : public Seedless {
  public:
    Grass(string, int, int, char, int, int, bool, int, int);
    ~Grass();
};

class Algae : public Seedless {
  public:
    Algae(string, int, int, char, int, int, bool, int, int);
    ~Algae();
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

  private:
    Leaves foliage;
    int seeds;
};

class Maple : public Seeded {
  public:
    Maple(string, int, int, char, int, int, bool, int, int, int);
    ~Maple();
};

class Oak : public Seeded {
  public:
    Oak(string, int, int, char, int, int, bool, int, int, int);
    ~Oak();
};

class Pine : public Seeded {
  public:
    Pine(string, int, int, char, int, int, bool, int, int, int);
    ~Pine();
};
