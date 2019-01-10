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
     is_adult = true;
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
     if(nam == "Salmon") is_adult = true;
     else {is_adult = false;}
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

bool Animal::Hungry(void) { return is_hungry; }

bool Animal::IsStarving(void) { return (hunger_count == 10); }

bool Animal::IsInHeat(void) { return in_heat; }

bool Animal::Hibernates(void) { return hibernates; }

bool Animal::IsInHibernation(void){  return in_hibernation; }

bool Animal::Pleased(void) { return (eaten_food >= current_needed_food); }

bool Animal::IsHerbivore(void) { return (this -> token == HERB_TOKEN); }

bool Animal::IsCarnivore(void) { return (this -> token == CARN_TOKEN); }

bool Animal::IsAdult(void) { return is_adult; }

void Animal::IncreaseSize(int magnitude) {
  if(current_size + magnitude <= max_size) current_size += magnitude;
  else current_size = max_size;
}

void Animal::IncreaseSpeed(int magnitude) {
  if(current_speed + magnitude <= max_speed) current_speed += magnitude;
  else current_speed = max_speed;
}

void Animal::IncreaseNeededFood(int magnitude) {
  if(current_needed_food + magnitude <= max_needed_food) current_needed_food += magnitude;
  else current_needed_food = max_needed_food;
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

Animal* Animal::Reproduct(void){
  string deer = "Adult Deer", rabbit = "Adult Rabbit", groundhog = "Adult Groundhog",
  salmon = "Adult Salmon", fox = "Adult Fox", bear = "Adult Bear", wolf = "Adult Wolf";
  Animal* child = NULL;

  if(name == deer) {
    child = new Herbivore("Deer", HERB_TOKEN, this->coordinate_x, this->coordinate_y,
                                  Y_DEER_SIZE,A_DEER_SIZE,Y_DEER_SPEED,A_DEER_SPEED, Y_DEER_NEED_FOOD, A_DEER_NEED_FOOD
                                  ,DEER_CLIMB,DEER_HIBERNATION);

  } else if(name == rabbit) {
    child = new Herbivore("Rabit", HERB_TOKEN, this->coordinate_x, this->coordinate_y,
                                  Y_RABBIT_SIZE,A_RABBIT_SIZE,Y_RABBIT_SPEED,A_RABBIT_SPEED, Y_RABBIT_NEED_FOOD, A_RABBIT_NEED_FOOD
                                  ,RABBIT_CLIMB,RABBIT_HIBERNATION);

  } else if(name == groundhog) {
    child = new Herbivore("Groundhog", HERB_TOKEN, this->coordinate_x, this->coordinate_y,
                                  Y_GROUNDHOG_SIZE,A_GROUNDHOG_SIZE,Y_GROUNDHOG_SPEED,A_GROUNDHOG_SPEED, Y_GROUNDHOG_NEED_FOOD, A_GROUNDHOG_NEED_FOOD
                                  ,GROUNDHOG_CLIMB,GROUNDHOG_HIBERNATION);

  } else if(name == salmon) {
    child = new Herbivore("Salmon", HERB_TOKEN, this->coordinate_x, this->coordinate_y,
                                  A_SALMON_SIZE,A_SALMON_SIZE,A_SALMON_SPEED,A_SALMON_SPEED, A_SALMON_NEED_FOOD, A_SALMON_NEED_FOOD,
                                  SALMON_CLIMB,SALMON_HIBERNATION);

  } else if(name == fox) {
    child = new Carnivore("Fox", CARN_TOKEN, this->coordinate_x, this->coordinate_y,
                                Y_FOX_SIZE,A_FOX_SIZE,Y_FOX_SPEED,A_FOX_SPEED, Y_FOX_NEED_FOOD, A_FOX_NEED_FOOD
                                  ,FOX_HIBERNATION,Y_FOX_ATTACK,A_FOX_ATTACK,Y_FOX_DEFENCE,A_FOX_DEFENCE);

  } else if (name == bear) {
    child = new Carnivore("Bear", CARN_TOKEN, this->coordinate_x, this->coordinate_y,
                                Y_BEAR_SIZE,A_BEAR_SIZE,Y_BEAR_SPEED,A_BEAR_SPEED, Y_BEAR_NEED_FOOD, A_BEAR_NEED_FOOD
                                  ,BEAR_HIBERNATION,Y_BEAR_ATTACK,A_BEAR_ATTACK,Y_BEAR_DEFENCE,A_BEAR_DEFENCE);

  }else if (name == wolf) {
    child = new Carnivore("Wolf", CARN_TOKEN, this->coordinate_x, this->coordinate_y,
                                Y_WOLF_SIZE,A_WOLF_SIZE,Y_WOLF_SPEED,A_WOLF_SPEED, Y_WOLF_NEED_FOOD, A_WOLF_NEED_FOOD
                                  ,WOLF_HIBERNATION,Y_WOLF_ATTACK,A_WOLF_ATTACK,Y_WOLF_DEFENCE,A_WOLF_DEFENCE);
  } else {
    //cout << name << " " << current_size << " " << " " << current_speed << endl;
  }

  return child;
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

bool Herbivore::CheckIfAdult(void) {
  if(((current_size == max_size) && (current_speed == max_speed) && (current_needed_food == max_needed_food))) {
    is_adult = true;
  }
  return is_adult;
}

void Herbivore::Raise(void){
  string deer = "Young Deer", rabbit = "Young Rabbit", groundhog = "Young Groundhog";
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
    if(CheckIfAdult()) {
     if(name.find("Young") != string::npos){
      EraseSubStr(name,"Young ");
      string adult = "Adult ";
      adult.append(name);
      name = adult;
    }
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

/*constructor for adult Carnivores*/
Carnivore::Carnivore(string name, char token, int x, int y, int size, int speed, int needed_food, bool hibernates, int attack, int defence)
        :Animal(name, token, x, y, size, speed, needed_food, hibernates),
        current_attack(attack), current_defence(defence), max_attack(attack), max_defence(defence) {
          //cout << "I just constructed an carnivore" << endl;
        }

/*constructor for young Carnivores*/
Carnivore::Carnivore(string name, char token, int x, int y, int current_size, int max_size, int current_speed, int max_speed, int current_needed_food, int max_needed_food,
          bool hibernates, int current_attack, int max_attack, int current_defence, int max_defence)
            :Animal(name, token, x, y, current_size, max_size, current_speed, max_speed, current_needed_food, max_needed_food, hibernates),
             current_attack(current_attack),max_attack(max_attack),current_defence(current_defence),max_defence(max_defence){
              //cout << "I just constructed a young herbivore" << endl;
            }

Carnivore::~Carnivore(){
  // cout << "I just deleted an herbivore" << endl;
}

int Carnivore::GetAttack(void) { return current_attack; }

int Carnivore::GetDefence(void) { return current_defence; }

int Carnivore::GetMaxAttack(void) { return max_attack; }

int Carnivore::GetMaxDefence(void) { return max_defence; }

void Carnivore::IncreaseAttack(int magnitude) {
  if(current_attack + magnitude <= max_attack) current_attack += magnitude;
  else current_attack = max_attack;
}

void Carnivore::IncreaseDefence(int magnitude) {
  if(current_defence + magnitude <= max_defence) current_defence += magnitude;
  else current_defence = max_defence;
}

bool Carnivore::CheckIfAdult(void) {
  if((current_size == max_size) && (current_speed == max_speed) && (current_needed_food == max_needed_food) && (current_attack == max_attack) && (current_defence == max_defence)) {
    is_adult = true;
  }
  return is_adult;
}

void Carnivore::Raise(void){
  string fox = "Young Fox", bear = "Young Bear", wolf = "Young Wolf";
  if(!IsAdult()) {
    if(name == fox) {
        IncreaseSize(1);
        IncreaseSpeed(1);
        IncreaseNeededFood(1);
        IncreaseAttack(2);
        IncreaseDefence(2);
    }
    else if(name == bear) {
        IncreaseSize(2);
        IncreaseNeededFood(2);
        IncreaseAttack(2);
        IncreaseDefence(2);
    }
    else if(name == wolf) {
        IncreaseSize(1);
        IncreaseSpeed(2);
        IncreaseNeededFood(2);
        IncreaseAttack(2);
        IncreaseDefence(2);
    }
    if(CheckIfAdult()) {
     if(name.find("Young") != string::npos){
      EraseSubStr(name,"Young ");
      string adult = "Adult ";
      adult.append(name);
      name = adult;
    }
   }
  }
  else {
    is_adult = true;
    if(name.find("Young") != string::npos){
      EraseSubStr(name,"Young ");
      string adult = "Adult ";
      adult.append(name);
      name = adult;
    }
  }
}
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
  bool eaten = false;
  /*if the first animal is a fox, a wolf, or a young bear, we apply the same food chain rules to them*/
  if((a1->GetName().find("Fox") != string::npos) || (a1->GetName().find("Wolf") != string::npos) || (a1->GetName().find("Young Bear") != string::npos)){
    if((a1 -> GetSize() > a2 ->GetSize()) || ((a1 -> GetAttack() > a2 -> GetDefence()) && (a1 -> GetSize() > a2 ->GetSize()) ) ){
      a1 -> Eat(a2);
      eaten = true;
    }
  }
  /*a bear eats every hervibore, except of another bear*/
  else {
    if (! (a2->GetName().find("Bear") != string::npos)){
      a1 -> Eat(a2);
      eaten = true;
    }
  }
  /*if the first has not eaten the second, check if the second can eat the first*/
  if(eaten == false) {
    if((a2->GetName().find("Fox") != string::npos) || (a2->GetName().find("Wolf") != string::npos) || (a2->GetName().find("Young Bear") != string::npos)){
      if((a2 -> GetSize() > a1 ->GetSize()) || ((a2 -> GetAttack() > a1 -> GetDefence()) && (a2 -> GetSize() > a1 ->GetSize()) ) ){
        a2 -> Eat(a1);
        eaten = true;
      }
    }
    /*a bear eats every hervibore, except of another bear*/
    else {
      if (! (a1->GetName().find("Bear") != string::npos)){
        a2 -> Eat(a1);
        eaten = true;
      }
    }
  }
}
