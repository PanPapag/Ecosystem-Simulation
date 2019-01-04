#include <iostream>
#include <cstring>
#include "PlantInterface.h"

bool RandomResult(int factor){
  int res = rand() % 101;
  if (res > factor) return true;
  else return false;
}

/* -------------------------------------- class Plant Implementation ------------------------------------- */

Plant::Plant(string name, int x, int y, char token, int breeding, int illness, int life_var, int life_fact)
  : name(name), coordinate_x(x), coordinate_y(y), token(token),
    breeding_prob(breeding), illness_prob(illness), life(life_var), life_factor(life_fact) {
      //cout << "I just constructed a plant" << endl;
}

Plant::~Plant() {
  //cout << "Destructed a plant" << endl;
}

bool Plant::Reproduced(void) { return (RandomResult(1 - breeding_prob)); }

bool Plant::IsDead(void) { return (life <= 0); }

int Plant::GetLife(void) { return life; }

int Plant::GetCoordinateX(void) { return coordinate_x; }

int Plant::GetCoordinateY(void) { return coordinate_y; }

int Plant::GetBreedingProb(void) { return breeding_prob; }

int Plant::GetIllnessProb(void) { return illness_prob; }

int Plant::GetLifeFactor(void) { return life_factor; }

char Plant::GetToken(void) { return token; }

string Plant::GetName(void) { return name; }


/* -------------------------------------- Seedless Implementation ------------------------------------- */

Seedless::Seedless(string name, int x, int y, char token, int breeding, int illness, int life_var, int life_fact)
  : Plant(name, x, y, token, breeding, illness, life_var, life_fact) {
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
}

void Seedless::Grow(void) {
  bool action = RandomResult(illness_prob);
  if (action) {
    life += life_factor;
  } else {
    life -= life_factor;
  }
}

Grass::Grass(string name, int x, int y, char token, int breeding, int illness, int life_var, int life_fact)
  : Seedless(name, x, y, token, breeding, illness, life_var, life_fact) {
    //cout << "I just constructed a grass plant" << endl;
}

Grass::~Grass() {
  //cout << "Destructed a grass plant" << endl;
}

Algae::Algae(string name, int x, int y, char token, int breeding, int illness, int life_var, int life_fact)
  : Seedless(name, x, y, token, breeding, illness, life_var, life_fact) {
    //cout << "I just constructed an Algae plant" << endl;
}

Algae::~Algae() {
  //cout << "Destructed an Algae plant" << endl;
}

/*Leaves functions */

Leaves::Leaves(int no_of_leaves): quantity(no_of_leaves), size(1) {}

int Leaves::GetNumber(void) { return quantity; }

void Leaves::IncreaseSize(void) { size++; }

void Leaves::DecreaseSize(void) { size--; }

void Leaves::IncreaseNumber(int n) { quantity += n; }

void Leaves::DecreaseNumber(int n) { quantity -= n; }


/*Seeded Plant functions */

Seeded::Seeded(string name, int x, int y, char token, int breeding, int illness, int life_var, int life_fact, int fol, int seed)
  :Plant(name, x, y, token, breeding, illness, life_var, life_fact), foliage(fol), seeds(seed) {
    //cout << "I just constructed a seeded plant" << endl;
}

void Seeded::EatenByAnimal(int quantity){
  if (quantity < seeds ) seeds -= quantity;
  else{
    seeds = 0;
    int remaining = quantity - seeds;
    if(remaining < life){
      life -= remaining;
      if (foliage.GetNumber() > remaining) foliage.DecreaseNumber(remaining);
      else foliage.DecreaseNumber(foliage.GetNumber());
    }
    else life = 0;
  }
}

void Seeded::Grow(void){
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

}
