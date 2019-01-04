#ifndef __PLANT__
#define __PLANT__

#include <cstring>

using namespace std;

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


class Plant {

  public:
    Plant(string, int, int, char, int, int, int, int);
    ~Plant();
    bool Reproduced(void);
    bool IsDead(void);
    int GetLife(void);
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
    int life;
    int coordinate_x;
    int coordinate_y;
    int breeding_prob;
    int illness_prob;
    int life_factor;
};

class Seedless : public Plant {
  public:
    Seedless(string, int, int, char, int, int, int, int);
    ~Seedless();
    void LoseLife(void);
    void EatenByAnimal(int);
    void Grow(void);
    bool Reproduced(void);
};

class Grass : public Seedless {
  Grass(string, int, int, char, int, int, int, int);
  ~Grass();
};

class Algae : public Seedless {
  Algae(string, int, int, char, int, int, int, int);
  ~Algae();
};

class Leaves {

  public:
    Leaves(int);
    int GetNumber(void);
    void IncreaseSize(void);
    void DecreaseSize(void);
    void IncreaseNumber(int);
    void DecreaseNumber(int);

  private:
    unsigned int size;
    unsigned int quantity;
};

class Seeded : public Plant{

  public:
    Seeded(string, int, int, char, int, int, int, int, int, int);
    void EatenByAnimal(int);
    void Grow(void);
    bool Reproduced(void);

  private:
    Leaves foliage;
    int seeds;
};

#endif
