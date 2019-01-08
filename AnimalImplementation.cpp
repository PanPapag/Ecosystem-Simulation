#include <iostream>
#include <cstring>

#include "AnimalInterface.h"

using namespace std;

/*---------------------------Class animal functions---------------------------*/

/*constructor for adult animal*/
Animal::Animal(string nam, char token, int x, int y, int size, int speed, int needed_food, bool hibernates)
  :token(token), coordinate_x(x), coordinate_y(y), current_size(size), max_size(size), current_speed(speed),
   max_speed(speed), current_needed_food(needed_food) , max_needed_food(needed_food), hibernates(hibernates) {

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


/*constructor for young animal*/
Animal::Animal(string nam, char token, int x, int y, int current_size, int max_size, int current_speed, int max_speed, int current_needed_food, int max_needed_food, bool hibernates)
  :token(token), coordinate_x(x), coordinate_y(y), current_size(current_size), max_size(max_size), current_speed(current_speed),
   max_speed(max_speed), current_needed_food(current_needed_food) , max_needed_food(max_needed_food), hibernates(hibernates) {

     string init = "Young ";
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

int Animal::GetSize(void) { return current_size; }

int Animal::GetMaxSize(void) { return max_size; }

int Animal::GetSpeed(void) { return current_speed; }

int Animal::GetMaxSpeed(void) { return max_speed; }

int Animal::GetNeededFood(void) { return current_needed_food; }

int Animal::GetMaxNeededFood(void) { return max_needed_food; }

int Animal::GetHunger(void) { return hunger_count; }

int Animal::GetEatCount(void) { return eat_count; }

int Animal::GetCoordinateX(void) { return coordinate_x; }

int Animal::GetCoordinateY(void) { return coordinate_y; }

bool Animal::IsAlive(void) { return is_alive; }

bool Animal::IsAdult(void) {
  return ((current_size == max_size) && (current_speed == max_speed) && (current_needed_food == max_needed_food));
}

bool Animal::Hungry(void) { return is_hungry; }

bool Animal::IsInHeat(void) { return in_heat; }

bool Animal::Hibernates(void) { return hibernates; }

bool Animal::IsInHibernation(void){  return in_hibernation; }

bool Animal::Pleased(void) { return (eaten_food >= current_needed_food); }

bool Animal::IsHerbivore(void) { return (this -> token == HERB_TOKEN); }

bool Animal::IsCarnivore(void) { return (this -> token == CARN_TOKEN); }

void Animal::IncreaseSize(int magnitude) {
  if(current_size + magnitude <= max_size) current_size += magnitude;
  else current_size = max_size;
}

void Animal::IncreaseSpeed(int magnitude) {
  if(current_size + magnitude <= max_size) current_size += magnitude;
  else current_size = max_size;
}

void Animal::IncreaseNeededFood(int magnitude) {
  if(current_size + magnitude <= max_size) current_size += magnitude;
  else current_size = max_size;
}

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

void Animal::Raise(void){
  string deer = "Young Deer", rabbit = "Young Rabbit", groundhog = "Young Groundhog",
  salmon = "Young Salmon", fox = "Young Fox", bear = "Young Bear", wolf = "Young Wolf";
  if(!IsAdult()) {
    if(name == deer) {
        IncreaseSize(1);
        IncreaseSpeed(2);
        IncreaseNeededFood(2);
    }
    else if(name == rabbit) {
        IncreaseSize(1);
        IncreaseSpeed(2);
        IncreaseNeededFood(2);
    }
    else if(name == groundhog) {
        IncreaseSize(1);
        IncreaseSpeed(2);
        IncreaseNeededFood(2);
    }
    else if(name == fox) {
        IncreaseSize(1);
        IncreaseSpeed(1);
        IncreaseNeededFood(1);
    }
    else if(name == bear) {
        IncreaseSize(2);
        IncreaseNeededFood(2);
    }
    else if(name == wolf) {
        IncreaseSize(1);
        IncreaseSpeed(2);
        IncreaseNeededFood(2);
    }
  }
  else {
    if(name.find("Young") != string::npos){
      EraseSubStr(name,"Young ");
      string adult = "Adult ";
      adult.append(name);
      name = adult;
    }
  }
}

/*-----------------------Class herbivores functions---------------------------*/

/*constructor for adult herbivores*/
Herbivore::Herbivore(string name, char token, int x, int y, int size, int speed, int needed_food, bool can_climb, bool hibernates)
        :Animal(name, token, x, y, size, speed, needed_food, hibernates), can_climb(can_climb) {
          //cout << "I just constructed an adult  herbivore" << endl;
        }

/*constructor for young herbivores*/
Herbivore::Herbivore(string name, char token, int x, int y, int current_size, int max_size, int current_speed, int max_speed, int current_needed_food, int max_needed_food, bool can_climb, bool hibernates)
        :Animal(name, token, x, y, current_size, max_size, current_speed, max_speed, current_needed_food, max_needed_food, hibernates), can_climb(can_climb){
          //cout << "I just constructed a young herbivore" << endl;
        }


Herbivore::~Herbivore() {
  // cout << "I just deleted an herbivore" << endl;
}

bool Herbivore::CanClimb(void) { return can_climb; }


void Herbivore::Eat(Plant* plant) {
  /*the animal eats only if it hasn't yeat reached the desired amount of food for the day*/
  if(!Pleased()) {
    eaten_food += eat_count;
    hunger_count -= eat_count;
    plant -> EatenByAnimal(eat_count);
  }
  if(Pleased()) is_hungry = false;
}

/*-----------------------Class Carnivores functions---------------------------*/

Carnivore::Carnivore(string name, char token, int x, int y, int size, int speed, int needed_food, bool hibernates, int attack, int defence)
        :Animal(name, token, x, y, size, speed, needed_food, hibernates), attack(attack), defence(defence) {
        //cout << "I just constructed an carnivore" << endl;
}

Carnivore::~Carnivore(){
  // cout << "I just deleted an herbivore" << endl;
}

int Carnivore::GetAttack(void) { return attack; }

int Carnivore::GetDefence(void) { return defence; }

void Carnivore::Eat(Animal *a){
  this -> is_hungry = false;
  eaten_food = current_needed_food;

  a -> Died();
}

/*----------------------------------------------------------------------------*/

/*fight between a carnivore and a herbivore*/
void Fight(Carnivore* a1, Herbivore* a2){
  /*if the first animal is a fox or a wolf, we apply the same food chain rules to them*/
  if((a1->GetName().find("Fox") != string::npos) || (a1->GetName().find("Wolf") != string::npos)){
    if((a1 -> GetSize() >= a2 -> GetSize()) && (a1 -> GetSpeed() >= a2 -> GetSpeed())){
      if(! (a2->GetName().find("Salmon") != string::npos)){
        a1 -> Eat(a2);
      }
    }
  }
  /*a bear eats every hervibore*/
  else if(a1->GetName().find("Bear")!= string::npos){
    a1 -> Eat(a2);
  }
}

/*if the first animal is a herbivore and the second a carnivore, then we already have a function for this*/
void Fight(Herbivore* a1, Carnivore* a2){
  Fight(a2,a1);
}

/*if we have 2 herbivores, we do nothing*/
void Fight(Herbivore* a1, Herbivore* a2){
  return;
}

void Fight(Carnivore* a1, Carnivore* a2){
  /*if the first animal is a fox, a wolf, or a young bear, we apply the same food chain rules to them*/
  if((a1->GetName().find("Fox") != string::npos) || (a1->GetName().find("Wolf") != string::npos) || (a1->GetName().find("Young Bear") != string::npos)){
    if((a1 -> GetSize() > a2 ->GetSize()) || ((a1 -> GetAttack() > a2 -> GetDefence()) && (a1 -> GetSize() > a2 ->GetSize()) ) ){
      a1 -> Eat(a2);
    }
  }
  /*a bear eats every hervibore, except of another bear*/
  else{
    if (! (a2->GetName().find("Bear") != string::npos)){
      a1 -> Eat(a2);
    }
  }
}
