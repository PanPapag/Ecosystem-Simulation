#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

#define MIN_TERRAIN 10

int main(void) {

  int terrain_size, cycles;
  std::string season;

  do {
  std::cout << "Give terrain size of at least 10 fields: ";
  std::cin >> terrain_size;
  } while(terrain_size < MIN_TERRAIN);
  std::cout << std::endl;

  do {
  std::cout << "Give current season (Autumn, Winter, Spring, Summer): ";
  std::cin >> season;
  } while(season != "Autumn" && season != "Winter" && season != "Spring" && season != "Summer");
  std::cout << std::endl;

  std::cout << "Enter the number of simulation cycles: ";
  std::cin >> cycles;
  std::cout << std::endl;

  return 0;
}
