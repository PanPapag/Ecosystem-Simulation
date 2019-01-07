#include <iostream>
#include <cstring>

#include "AnimalInterface.h"

using namespace std;

/*-------------------------- Class Animal methods ----------------------------*/
Animal::Animal(string nam, char token, int x, int y, int size, int speed, int needed_food, bool hibernates)
  :token(token), coordinate_x(x), coordinate_y(y), size(size), speed(speed), needed_food(needed_food) , hibernates(hibernates) {
     /* Initially, all animals are adult */
     string init = "Adult ";
     init.append(nam);
     name = init;
     /* initialize the remaining data members */
     hunger_count = 0;
     eaten_food = 0;
     eat_count = 0;
     is_alive = true;
     is_hungry = false;
     in_heat = false;
     in_hibernation = false;
     //cout << "I just constructed an animal" << endl;
}

string Animal::GetName(void) { return name; }

char Animal::GetToken(void) { return token; }

int Animal::GetSize(void) { return size; }

int Animal::GetNeededFood(void) { return needed_food; }

int Animal::GetHunger(void) { return hunger_count; }

int Animal::GetEatCount(void) { return eat_count; }

int Animal::GetCoordinateX(void) { return coordinate_x; }

int Animal::GetCoordinateY(void) { return coordinate_y; }

bool Animal::Alive(void) { return is_alive; }

bool Animal::Hungry(void) { return is_hungry; }

bool Animal::IsInHeat(void) { return in_heat; }

int Animal::GetSpeed(void) { return speed; }

bool Animal::Hibernates(void) { return hibernates; }

bool Animal::IsInHibernation(void){  return in_hibernation; }

bool Animal::IsHerbivore(void) { return (this -> token == HERB_TOKEN); }

bool Animal::IsCarnivore(void) { return (this -> token == CARN_TOKEN); }

void Animal::IncreaseSize(int magnitude) { size += magnitude; }

void Animal::SetName(string name) {
  this -> name = name;
}

void Animal::Died(void) { this -> is_alive = false; }

void Animal::SetHeat(bool condition) { this -> in_heat = condition; }

void Animal::SetHunger(bool condition) { this -> is_hungry = condition; }

void Animal::SetHibernation(bool condition) {
  if(this -> hibernates) {
    in_hibernation = condition;
  }
}


void Animal::Move(int x, int y) {
  coordinate_x = x;
  coordinate_y = y;
}

/*----------------------- Class Herbivore methods ----------------------------*/

Herbivore::Herbivore(string name, char token, int x, int y, int size, int speed, int needed_food, bool can_climb, bool hibernates)
        :Animal(name, token, x, y, size, speed, needed_food, hibernates), can_climb(can_climb) {
        //cout << "I just constructed an herbivore" << endl;
}

Herbivore::~Herbivore() {
  // cout << "I just destructed an herbivore" << endl;
}

bool Herbivore::CanClimb(void) { return can_climb; }

bool Herbivore::Pleased(void) { return (eaten_food == needed_food); }

void Herbivore::Eat(Plant* plant) {
  /*the animal eats only if it hasn't yeat reached the desired amount of food for the day*/
  if(!Pleased()) {
    eaten_food += eat_count;
    plant -> EatenByAnimal(eat_count);
  }
}

/*---------------------------Class Carnivore methods -------------------------*/
Carnivore::Carnivore(string name, char token, int x, int y, int size, int speed, int needed_food, int attack, int defence, bool hibernates)
        :Animal(name, token, x, y, size, speed, needed_food, hibernates), attack(attack), defence(defence) {
          //cout << "I just constructed a carnivore" << endl;
}

Carnivore::~Carnivore() {
  // cout << "I just destructed a carnivore" << endl;
}

int Carnivore::GetAttack(void) { return attack; }

int Carnivore::GetDefence(void) { return defence; }