/*Class animal functions*/
Animal::Animal(string name, char token, int hunger, int eat_count, int x, int y, int speed, bool hibernates)
  :name(name), token(token), size(size), hunger_count(hunger), eaten_food(0), eat_count(eat_count), coordinate_x(x),
   coordinate_y(y), is_alive(true), is_hungry(true), in_heat(false), speed(speed), hibernates(hibernates), in_hibernation(false){
     //cout << "I just constructed an animal" << endl;
   }

Animal::~Animal(void){
  //cout << "I'm deleting an animal" << endl;
}

string Animal::GetName(void) { return name; }

char Animal::GetToken(void) { return token; }

int Animal::GetSize(void) { return size; }

int Animal::GetHunger(void){ return hunger_count; }

int Animal::GetEatCount(void){ return eat_count; }

int Animal::GetCoordinateX(void) { return coordinate_x; }

int Animal::GetCoordinateY(void) { return coordinate_y; }

bool Animal::Alive(void){ return is_alive; }

bool Animal::Hungry(void){ return is_hungry; }

bool Animal::IsInHeat(void){ return in_heat; }

int Animal::GetSpeed(void){ return speed; }

bool Animal::Hibernates(void){ return hibernates; }

bool Animal::IsInHibernation(void){ return in_hibernation; }
