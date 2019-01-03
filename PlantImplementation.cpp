#include <iostream>
#include <cstring>
#include "plants.h"

using namespace std;

bool RandomResult(int factor){
  int res = rand()%100;
  if (res > factor) return true;
  else return false;
}

/*Struct Plant functions */

Plant::Plant(char* nam, int xx, int yy, char tok, int breeding, int illness, int life_var, int life_fact)
  :token(tok), breeding_prob(breeding), illness_prob(illness), life(life_var), life_factor(life_fact){
    name = new char[strlen(nam)+1];
    strcpy(name, nam);
    coordinates = new point(xx,yy);
    cout << "I just constructed a " << name << endl;
  }

Plant::~Plant(){
  cout << "Deleting a " << name << endl;
  delete [] name;
  delete coordinates;
}
bool Plant::IsDead(void) { return (life == 0); }

int Plant::GetLife(void) { return life; }

/*Seedless Plant functions */

Seedless::Seedless(char* nam, int xx, int yy, char tok, int breeding, int illness, int life_var, int life_fact)
  : Plant(nam, xx, yy, tok, breeding, illness, life_var, life_fact){}

void Seedless::LooseLife(){ life -= life_factor; }

void Seedless::EatenByAnimal(int quantity){
  if( quantity < life ) life -= quantity;
  else life = 0;
}

void Seedless::Grow(void){
  int action = RandomResult(illness_prob);
  if (action) life += life_factor;
  else life -= life_factor;
}

bool Seedless::Reproduced(void){ //otan katalaveis ti kanei tha entypwsiasteis
  return (RandomResult(1-breeding_prob));
}
/*Leaves functions */

Leaves::Leaves(int n_of_leaves): quantity(n_of_leaves), size(1) {}

int Leaves::GetNumber(void){ return quantity; }

void Leaves::IncreaseSize(void){ size++; }

void Leaves::DecreaseSize(void){ size--; }

void Leaves::IncreaseNumber(int n){ this->quantity += n;}

void Leaves::DecreaseNumber(int n){ this->quantity -= n;}


/*Seeded Plant functions */

Seeded::Seeded(char* nam, int xx, int yy, char tok, int breeding, int illness, int life_var, int life_fact, int fol, int seed)
  :Plant(nam, xx, yy, tok, breeding, illness, life_var, life_fact), foliage(fol), seeds(seed){}

void Seeded::EatenByAnimal(int quantity){
  if (quantity < seeds ) seeds -= quantity;
  else{
    seeds = 0;
    int remaining = quantity - seeds;
    if( remaining < life ){
      life -= remaining;
      if (foliage.GetNumber() > remaining) foliage.DecreaseNumber(remaining);
      else foliage.DecreaseNumber(foliage.GetNumber());
    }
    else life = 0;
  }
}

void Seeded::Grow(void){
  int action = RandomResult(illness_prob);
  if (action) {
    foliage.IncreaseNumber(life_factor);
    seeds += 2 * life_factor;
  }
  else{
    foliage.DecreaseNumber(life_factor);
    seeds -= 2 * life_factor;
  }
  if( foliage.GetNumber() % life_factor == 0 ){
    if (action) foliage.IncreaseSize();
    else  foliage.DecreaseSize();
  }
}

bool Seeded::Reproduced(void){
  return (RandomResult(1-breeding_prob));
}
