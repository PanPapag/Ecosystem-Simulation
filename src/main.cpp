#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include "../headers/EcosystemInterface.h"

#define MIN_TERRAIN 10

int main(void) {

  srand(time(NULL));

  int terrain_size, cycles;
  string season;

  do {
  cout << "Give terrain size of at least 10 fields: ";
  cin >> terrain_size;
  } while(terrain_size < MIN_TERRAIN);
  cout << endl;

  do {
  cout << "Give current season (Autumn, Winter, Spring, Summer): ";
  cin >> season;
  } while(season != "Autumn" && season != "Winter" && season != "Spring" && season != "Summer");
  cout << endl;

  cout << "Enter the number of simulation cycles: ";
  cin >> cycles;
  cout << endl;

  Ecosystem *ecosystem = new Ecosystem(terrain_size,season);

  ecosystem->PrintSystem(0);

  for(int day = 1; day <= cycles; day++) {
    ecosystem->RunEcosystem(day);
  }

  ecosystem->PrintSystem(cycles);

  delete ecosystem;

  return 0;
}
