#include <iostream>
#include <cstring>
#include "AnimalInterface.h"

using namespace std;

/*---------------------------Class animal functions---------------------------*/
Animal::Animal(string nam, char token, int size, int hunger, int eat_count, int x, int y, int speed, bool hibernates)
  :token(token), size(size), hunger_count(hunger), eaten_food(0), eat_count(eat_count), coordinate_x(x),
   coordinate_y(y), is_alive(true), is_hungry(true), in_heat(false), speed(speed), hibernates(hibernates), in_hibernation(false){
     /*initially, all animals are young*/
     string init = "Young ";
     init.append(nam);
     name = init;
     //cout << "I just constructed an animal" << endl;
   }

Animal::~Animal(void){
  //cout << "I'm deleting an animal" << endl;
}

string Animal::GetName(void) { return name; }

char Animal::GetToken(void) { return token; }

int Animal::GetSize(void) { return size; }

int Animal::GetHunger(void) { return hunger_count; }

int Animal::GetEatCount(void) { return eat_count; }

int Animal::GetCoordinateX(void) { return coordinate_x; }

int Animal::GetCoordinateY(void) { return coordinate_y; }

bool Animal::Alive(void) { return is_alive; }

bool Animal::Hungry(void) { return is_hungry; }

bool Animal::IsInHeat(void) { return in_heat; }

int Animal::GetSpeed(void) { return speed; }

bool Animal::Hibernates(void) { return hibernates; }

bool Animal::IsInHibernation(void){ return in_hibernation; }

bool Animal::IsHerbivore(void){ return (this -> token == 'H'); }

bool Animal::IsCarnivore(void){ return (this -> token == 'C'); }

void Animal::IncreaseSize(int s){ size+=s; }

void Animal::SetName(string name){
  this -> name = name;
}

void Animal::Died(void){ this -> is_alive = false; }

void Animal::SetHeat(bool condition){ this -> in_heat = condition; }

void Animal::SetHunger(bool condition){ this -> is_hungry = condition; }

void Animal::Hibernation(bool condition){
  if(this -> hibernates) {
    in_hibernation = condition;
  }
}


void Animal::Move(int x, int y){
  coordinate_x = x;
  coordinate_y = y;
}


/*-----------------------Class herbivores functions---------------------------*/

Herbivores::Herbivores(string name, char token, int size, int hunger, int eat_count, int x, int y, int speed, bool hibernates, bool can_climb, int needed_food)
        :Animal(name, token, size, hunger, eat_count, x, y, speed, hibernates),
         can_climb(can_climb), needed_food(needed_food){
           //cout << "I just constructed an herbivore" << endl;
         }

bool Herbivores::CanClimb(void){ return can_climb; }

int Herbivores::GetNeededFood(void){ return needed_food; }

bool Herbivores::Pleased(void){ return (eaten_food == needed_food); }

void Herbivores::Eat(Plant* plant){
  /*the animal eats only if it hasn't yeat reached the desired amount of food for the day*/
  if(!Pleased()) {
    eaten_food += eat_count;
    plant -> EatenByAnimal(eat_count);
  }
}
