#include <iostream>
#include <cstring>

#include "PlantInterface.h"

/* -------------------------------------- class Plant Implementation ------------------------------------- */

Plant::Plant(string name, int x, int y, char token, int breeding, int illness, bool life_sit, int life_fact)
  : name(name), coordinate_x(x), coordinate_y(y), token(token),
    breeding_prob(breeding), illness_prob(illness), alive(life_sit), life_factor(life_fact) {
      //cout << "I just constructed a plant" << endl;
}

bool Plant::Reproduced(void) { return (RandomResult(100 - breeding_prob)); }

bool Plant::IsAlive(void) { return alive; }

int Plant::GetCoordinateX(void) { return coordinate_x; }

int Plant::GetCoordinateY(void) { return coordinate_y; }

int Plant::GetBreedingProb(void) { return breeding_prob; }

int Plant::GetIllnessProb(void) { return illness_prob; }

int Plant::GetLifeFactor(void) { return life_factor; }

char Plant::GetToken(void) { return token; }

string Plant::GetName(void) { return name; }


/* -------------------------------------- Seedless Implementation ------------------------------------- */

Seedless::Seedless(string name, int x, int y, char token, int breeding, int illness, bool life_sit, int life_fact, int life_var)
  : Plant(name, x, y, token, breeding, illness, life_sit, life_fact ), life(life_var) {
    //cout << "I just constructed a seedless plant" << endl;
}

Seedless::~Seedless() {
  //cout << "Destructed a seedless plant" << endl;
}

void Seedless::LoseLife(void) { life -= life_factor; }

void Seedless::EatenByAnimal(int quantity) {
  if(quantity < life) {
    life -= quantity;
  } else {
    life = 0;
  }

  if(life <= 0) {
    alive = false;
  }
}

void Seedless::Grow(void) {
  bool action = RandomResult(illness_prob);

  if (action) {
    life += life_factor;
  } else {
    life -= life_factor;
  }

  if(life <= 0) {
    alive = false;
  }
}

int Seedless::GetLife(void) {
  return life;
}

Grass::Grass(string name, int x, int y, char token, int breeding, int illness, bool life_sit, int life_fact, int life_var)
  : Seedless(name, x, y, token, breeding, illness, life_sit, life_fact, life_var) {
    //cout << "I just constructed a grass plant" << endl;
}

Grass::~Grass() {
  //cout << "Destructed a grass plant" << endl;
}

Algae::Algae(string name, int x, int y, char token, int breeding, int illness, bool life_sit, int life_fact, int life_var)
  : Seedless(name, x, y, token, breeding, illness, life_sit, life_fact, life_var) {
    //cout << "I just constructed an Algae plant" << endl;
}

Algae::~Algae() {
  //cout << "Destructed an Algae plant" << endl;
}

/* ---------------------------------------- Seeded Implementation --------------------------------------- */

Leaves::Leaves(int no_of_leaves, int size): quantity(no_of_leaves), size(size) {}

Leaves::~Leaves() {}

int Leaves::GetNumber(void) { return quantity; }

int Leaves::GetSize(void) { return size; }

void Leaves::IncreaseSize(void) { size++; }

void Leaves::DecreaseSize(void) { size--; }

void Leaves::IncreaseNumber(int n) { quantity += n; }

void Leaves::DecreaseNumber(int n) { quantity -= n; }


Seeded::Seeded(string name, int x, int y, char token, int breeding, int illness, bool life_sit, int life_fact, int fol, int seed, int size)
  :Plant(name, x, y, token, breeding, illness, life_sit, life_fact), foliage(fol,size), seeds(seed) {
    //cout << "I just constructed a seeded plant" << endl;
}

Seeded::~Seeded() {
  //cout << "Destructed a seeded plant" << endl;
}

void Seeded::EatenByAnimal(int quantity) {

  if (quantity < seeds ) {
    seeds -= quantity;
  } else {
    seeds = 0;
    if (foliage.GetNumber() > quantity) foliage.DecreaseNumber(quantity);
    else foliage.DecreaseNumber(foliage.GetNumber());
  }

  if(foliage.GetNumber() <= 0) {
    alive = false;
  }
}

void Seeded::Grow(void) {
  bool action = RandomResult(illness_prob);

  if (action) {
    foliage.IncreaseNumber(life_factor);
    seeds += 2 * life_factor;
  } else {
    foliage.DecreaseNumber(life_factor);
    seeds -= 2 * life_factor;
  }

  if(foliage.GetNumber() % life_factor == 0) {
    if (action) {
      foliage.IncreaseSize();
    } else {
      foliage.DecreaseSize();
    }
  }

  if(foliage.GetNumber() <= 0 ) {
    alive = false;
  }
}

int Seeded::GetSeeds(void) { return seeds; }

Maple::Maple(string name, int x, int y, char token, int breeding, int illness, bool life_sit, int life_fact, int fol, int seed)
  : Seeded(name, x, y, token, breeding, illness, life_sit, life_fact, fol, seed, MAPLE_SIZE) {
    //cout << "I just constructed an Algae plant" << endl;
}

Maple::~Maple() {
  //cout << "Destructed a maple plant" << endl;
}

Oak::Oak(string name, int x, int y, char token, int breeding, int illness, bool life_sit, int life_fact, int fol, int seed)
  : Seeded(name, x, y, token, breeding, illness, life_sit, life_fact, fol, seed, OAK_SIZE) {
    //cout << "I just constructed an Algae plant" << endl;
}

Oak::~Oak() {
  //cout << "Destructed a maple plant" << endl;
}

Pine::Pine(string name, int x, int y, char token, int breeding, int illness, bool life_sit, int life_fact, int fol, int seed)
  : Seeded(name, x, y, token, breeding, illness, life_sit, life_fact, fol, seed, PINE_SIZE) {
    //cout << "I just constructed an Algae plant" << endl;
}

Pine::~Pine() {
  //cout << "Destructed a pine plant" << endl;
}
