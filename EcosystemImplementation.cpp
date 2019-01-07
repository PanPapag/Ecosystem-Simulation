#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include "EcosystemInterface.h"
#include "AnimalInterface.h"
#include "PlantInterface.h"

/* -------------------------------------- class Tile Implementation ------------------------------------- */
Tile::Tile() {
  ground = EMPTY;
  exist_plant = false;
  plant_token = EMPTY;
}

Tile::~Tile() {
  //cout << "Tile destructed" << endl;
}

char Tile::GetGround() { return ground; }

char Tile::GetPlanthToken() { return plant_token; }

bool Tile::ExistPlant() { return exist_plant; }

void Tile::SetGround(char category) {
  ground = category;
}

void Tile::SetPlantToken(char category) {
  plant_token = category;
}

/* ----------------------------------- class Ecosystem Implementation ----------------------------------- */

Ecosystem::Ecosystem(int size, string season) {
  terrain_size = size;
  current_season = season;

  terrain_grid = new Tile *[terrain_size];
  for(int i = 0; i < terrain_size; i++) {
      terrain_grid[i] = new Tile[terrain_size];
   }

   int total_points = terrain_size * terrain_size;
   points = new coordinates[total_points];
   FillPoints(points,terrain_size);
   ShufflePoints(points,0,total_points);

   max_no_of_plants = terrain_size * terrain_size;
   plant_array = new Plant *[max_no_of_plants];
   for(int i = 0; i < max_no_of_plants; i++) {
     plant_array[i] = NULL;
   }

   max_no_of_animals = terrain_size * terrain_size * ((rand() % (100 - 50 + 1)) + 50);
   animal_array = new Animal *[max_no_of_animals];
   for(int i = 0; i < max_no_of_animals; i++) {
     animal_array[i] = NULL;
   }

   MapGenerator();
}

Ecosystem::~Ecosystem() {

  for(int i = 0; i < terrain_size; i++) {
    delete [] terrain_grid[i];
  }
  delete [] terrain_grid;

  delete [] points;

  for(int i = 0; i < max_no_of_plants; i++){
       delete plant_array[i];
   }
   delete [] plant_array;

  for(int i = 0; i < max_no_of_animals; i++){
        delete animal_array[i];
  }
  delete [] animal_array;

  cout << "Ecosystem destroyed. End of the simulation!" << endl;
}

void Ecosystem::MapGenerator(void) {
  int river_tiles = GenerateRiver();
  int lake_tiles = GenerateLake();
  int hill_tiles = GenerateHills();
  int meadow_tiles = GenerateMeadow();

  no_of_grass = meadow_tiles / 3;
  no_of_algae = (river_tiles + lake_tiles) / 3;
  no_of_maple = (hill_tiles + meadow_tiles) / 3;
  no_of_oak = meadow_tiles / 3;
  no_of_pine = hill_tiles / 2;

  no_of_deer = meadow_tiles / 5;
  no_of_rabbit = meadow_tiles / 5;
  no_of_groundhog = meadow_tiles / 5;
  no_of_salmon = (river_tiles + lake_tiles) / 3;
  no_of_fox = meadow_tiles / 5;
  no_of_bear = hill_tiles / 2;
  no_of_wolf = (hill_tiles + meadow_tiles) / 5;

  PrintGrid();
  PlacePlants();
  PlaceAnimals();
}

int Ecosystem::GenerateRiver(void) {

  unsigned int no_tiles = 0;
  bool stop = false;
  int x, y, start_y;

  x = 0;
  y = (rand() % (terrain_size - 5 )) + 5;
  start_y = y;
  terrain_grid[x][y].SetGround(WATER_TILE);
  no_tiles++;

  while(true) {
    /* Before go one field further, check either if we should continue or not */
    if((y == 0 && start_y != 0)  || (y == terrain_size - 1 && start_y !=  terrain_size - 1) ||  x == terrain_size -1 ) {
      break;
    }
    /* make one step down at a time */
    x++;
    terrain_grid[x][y].SetGround(WATER_TILE);
    no_tiles++;
    /* Check the possiblity of river 's diversion */
    if(rand() % 101 < DIVERSION_FACTOR) {
      int direction = rand() % 2;
      int no_fields = rand() % 2 + 1;
      if(direction == RIGHT) {

        for(int i = 0; i < no_fields; i++) {
          if((y == 0 && start_y != 0)  || (y == terrain_size - 1 && start_y !=  terrain_size - 1) ||  x == terrain_size -1 ) {
            stop = true;
            break;
          }
          y++;
          terrain_grid[x][y].SetGround(WATER_TILE);
          no_tiles++;
        }
      } else if(direction == LEFT) {
        for(int i = 0; i < no_fields; i++) {
          if(y == 0 || y == terrain_size - 1 || x == terrain_size -1 ) {
            stop = true;
            break;
          }
          y--;
          terrain_grid[x][y].SetGround(WATER_TILE);
          no_tiles++;
        }
      }
    }
    /* Stop declares if we have reached to end of river's creation */
    if(stop == true) {
      break;
    }
  }

  return no_tiles;
}

int Ecosystem::GenerateLake(void) {
  int no_tiles = 0;
  int start_x = rand() % (terrain_size - 1);
  int start_y = rand() % (terrain_size - 1);
  int distance_x = terrain_size - 1 - start_x;
  int distance_y = terrain_size - 1 - start_y;

  int min_distance;
  int lake_size;
  int max_size;
  int min_size;

  if(distance_x < distance_y) {
    max_size = distance_x;
  } else {
    max_size = distance_y;
  }
  min_size = 2;

  if(max_size <= min_size) {
    lake_size = max_size;
  } else {
    lake_size = (rand() % (max_size - min_size + 1)) + min_size;
  }

  for(int x = start_x; x <= start_x + lake_size; x++) {
    for(int y = start_y; y <= start_y + lake_size; y++) {
      terrain_grid[x][y].SetGround(WATER_TILE);
      no_tiles++;
    }
  }

  return no_tiles;
}

int Ecosystem::GenerateHills(void) {
  int no_tiles = 0;
  int min_size = 2;
  int max_size = 4;

  int hill_size = (rand() % (max_size - min_size + 1)) + min_size;

  int start_x;
  int start_y;
  bool stop;

  while(true) {
    stop = false;

    start_x = rand() % (terrain_size - hill_size);
    start_y = rand() % (terrain_size - hill_size);
    /* Check not to overlay a water tile */
    for(int x = start_x; x <= start_x + hill_size; x++) {
      for(int y = start_y; y <= start_y + hill_size; y++) {
        if(terrain_grid[x][y].GetGround() == WATER_TILE) {
          stop = true;
          break;
        }
      }
      if(stop == true) {
        break;
      }
    }
    if(stop == false) {
      break;
    }
  }

  /* Everything is ok now */
  for(int x = start_x; x <= start_x + hill_size; x++) {
    for(int y = start_y; y <= start_y + hill_size; y++) {
      terrain_grid[x][y].SetGround(HILL_TILE);
      no_tiles++;
    }
  }
  return no_tiles;
}

int Ecosystem::GenerateMeadow(void) {
  int no_tiles = 0;

  for(int x = 0; x < terrain_size; x++) {
    for(int y = 0; y < terrain_size; y++) {
      if(terrain_grid[x][y].GetGround() == EMPTY) {
        terrain_grid[x][y].SetGround(MEADOW_TILE);
        no_tiles++;
      }
    }
  }

  return no_tiles;
}

void Ecosystem::PlacePlants(void) {
  int plant_index = 0;
  int points_index;
  int x,y;
  int total_points = terrain_size * terrain_size;

  /* Place Grass */
  for(int i = 0; i < no_of_grass; i++) {
    points_index = 0;
    x = points[points_index].x;
    y = points[points_index].y;
    points_index++;

    while(terrain_grid[x][y].GetGround() != MEADOW_TILE || terrain_grid[x][y].ExistPlant() == true) {
      x = points[points_index].x;
      y = points[points_index].y;
      points_index++;
    }

    plant_array[plant_index] = new Seedless("Grass",x,y,GRASS_TOKEN,GRASS_BREEDING,GRASS_ILLNESS,
      ALIVE,GRASS_LIFE_FACTOR,GRASS_LIFE);
    terrain_grid[x][y].SetPlantToken(plant_array[plant_index]->GetToken());
    plant_index++;
  }
  /* Place Algae */
  for(int i = 0; i < no_of_algae; i++) {
    points_index = 0;
    x = points[points_index].x;
    y = points[points_index].y;
    points_index++;

    while(terrain_grid[x][y].GetGround() != WATER_TILE || terrain_grid[x][y].ExistPlant() == true) {
      x = points[points_index].x;
      y = points[points_index].y;
      points_index++;
    }

    plant_array[plant_index] = new Seedless("Algae",x,y,ALGAE_TOKEN,ALGAE_BREEDING,
      ALGAE_ILLNESS,ALIVE,ALGAE_LIFE_FACTOR,ALGAE_LIFE);
    terrain_grid[x][y].SetPlantToken(plant_array[plant_index]->GetToken());
    plant_index++;
  }
  /* Place Maple */
  for(int i = 0; i < no_of_maple; i++) {
    points_index = 0;
    x = points[points_index].x;
    y = points[points_index].y;
    points_index++;

    while(terrain_grid[x][y].GetGround() == WATER_TILE || terrain_grid[x][y].ExistPlant() == true) {
      x = points[points_index].x;
      y = points[points_index].y;
      points_index++;
    }

    plant_array[plant_index] = new Seeded("Maple",x,y,MAPLE_TOKEN,MAPLE_BREEDING,MAPLE_ILLNESS,
      ALIVE,MAPLE_LIFE_FACTOR,MAPLE_FOLIAGE,MAPLE_SEEDS,MAPLE_SIZE);
    terrain_grid[x][y].SetPlantToken(plant_array[plant_index]->GetToken());
    plant_index++;
  }
  /* Place Oak */
  for(int i = 0; i < no_of_oak; i++) {
    points_index = 0;
    x = points[points_index].x;
    y = points[points_index].y;
    points_index++;

    while(terrain_grid[x][y].GetGround() != MEADOW_TILE || terrain_grid[x][y].ExistPlant() == true) {
      x = points[points_index].x;
      y = points[points_index].y;
      points_index++;
    }

    plant_array[plant_index] = new Seeded("Oak",x,y,OAK_TOKEN,OAK_BREEDING,OAK_ILLNESS,ALIVE,
      OAK_LIFE_FACTOR,OAK_FOLIAGE,OAK_SEEDS,OAK_SIZE);
    terrain_grid[x][y].SetPlantToken(plant_array[plant_index]->GetToken());
    plant_index++;
  }
  /* Place Pine */
  for(int i = 0; i < no_of_pine; i++) {
    points_index = 0;
    x = points[points_index].x;
    y = points[points_index].y;
    points_index++;

    while(terrain_grid[x][y].GetGround() != HILL_TILE || terrain_grid[x][y].ExistPlant() == true) {
      x = points[points_index].x;
      y = points[points_index].y;
      points_index++;
    }

    plant_array[plant_index] = new Seeded("Pine",x,y,PINE_TOKEN,PINE_BREEDING,PINE_ILLNESS,ALIVE,
      PINE_LIFE_FACTOR,PINE_FOLIAGE,PINE_SEEDS,PINE_SIZE);
    terrain_grid[x][y].SetPlantToken(plant_array[plant_index]->GetToken());
    plant_index++;
  }
}

void Ecosystem::PlaceAnimals(void) {
  int animal_index = 0;
  int points_index;
  int x,y;
  int total_points = terrain_size * terrain_size;
  /* Place Deer */
  for(int i = 0; i < no_of_deer; i++) {
    points_index = 0;
    x = points[points_index].x;
    y = points[points_index].y;
    points_index++;

    while(terrain_grid[x][y].GetGround() != MEADOW_TILE) {
      x = points[points_index].x;
      y = points[points_index].y;
      points_index++;
    }

    animal_array[animal_index] = new Herbivore("Deer",HERB_TOKEN,x,y,A_DEER_SIZE,A_DEER_SPEED,A_DEER_NEED_FOOD,
      DEER_CLIMB,DEER_HIBERNATION);
    animal_index++;
  }
  /* Place Rabbit */
  for(int i = 0; i < no_of_rabbit; i++) {
    points_index = 0;
    x = points[points_index].x;
    y = points[points_index].y;
    points_index++;

    while(terrain_grid[x][y].GetGround() != MEADOW_TILE) {
      x = points[points_index].x;
      y = points[points_index].y;
      points_index++;
    }

    animal_array[animal_index] = new Herbivore("Rabbit",HERB_TOKEN,x,y,A_RABBIT_SIZE,A_RABBIT_SPEED,
      A_RABBIT_NEED_FOOD,RABBIT_CLIMB,RABBIT_HIBERNATION);
    animal_index++;
  }
  /* Place Groundhog */
  for(int i = 0; i < no_of_groundhog; i++) {
    points_index = 0;
    x = points[points_index].x;
    y = points[points_index].y;
    points_index++;

    while(terrain_grid[x][y].GetGround() != MEADOW_TILE) {
      x = points[points_index].x;
      y = points[points_index].y;
      points_index++;
    }

    animal_array[animal_index] = new Herbivore("Groundhog",HERB_TOKEN,x,y,A_GROUNDHOG_SIZE,A_GROUNDHOG_SPEED,
      A_GROUNDHOG_NEED_FOOD,GROUNDHOG_CLIMB,GROUNDHOG_HIBERNATION);
    animal_index++;
  }
  /* Place Salmon */
  for(int i = 0; i < no_of_salmon; i++) {
    points_index = 0;
    x = points[points_index].x;
    y = points[points_index].y;
    points_index++;

    while(terrain_grid[x][y].GetGround() != WATER_TILE) {
      x = points[points_index].x;
      y = points[points_index].y;
      points_index++;
    }

    animal_array[animal_index] = new Herbivore("Salmon",HERB_TOKEN,x,y,A_SALMON_SIZE,A_SALMON_SPEED,
      A_SALMON_NEED_FOOD,SALMON_CLIMB,SALMON_HIBERNATION);
    animal_index++;
  }
  /* Place Fox */
  for(int i = 0; i < no_of_fox; i++) {
    points_index = 0;
    x = points[points_index].x;
    y = points[points_index].y;
    points_index++;

    while(terrain_grid[x][y].GetGround() != MEADOW_TILE) {
      x = points[points_index].x;
      y = points[points_index].y;
      points_index++;
    }

    animal_array[animal_index] = new Carnivore("Fox",CARN_TOKEN,x,y,A_FOX_SIZE,A_FOX_SPEED,
      A_FOX_NEED_FOOD,A_FOX_ATTACK,A_FOX_DEFENCE,FOX_HIBERNATION);
    animal_index++;
  }
  /* Place Bear */
  for(int i = 0; i < no_of_bear; i++) {
    points_index = 0;
    x = points[points_index].x;
    y = points[points_index].y;
    points_index++;

    while(terrain_grid[x][y].GetGround() != HILL_TILE) {
      x = points[points_index].x;
      y = points[points_index].y;
      points_index++;
    }

    animal_array[animal_index] = new Carnivore("Bear",CARN_TOKEN,x,y,A_BEAR_SIZE,A_BEAR_SPEED,
      A_BEAR_NEED_FOOD,A_BEAR_ATTACK,A_BEAR_DEFENCE,BEAR_HIBERNATION);
    animal_index++;
  }
  /* Place Wolf */
  for(int i = 0; i < no_of_wolf; i++) {
    points_index = 0;
    x = points[points_index].x;
    y = points[points_index].y;
    points_index++;

    while(terrain_grid[x][y].GetGround() == WATER_TILE) {
      x = points[points_index].x;
      y = points[points_index].y;
      points_index++;
    }

    animal_array[animal_index] = new Carnivore("Wolf",CARN_TOKEN,x,y,A_WOLF_SIZE,A_WOLF_SPEED,
      A_WOLF_NEED_FOOD,A_WOLF_ATTACK,A_WOLF_DEFENCE,WOLF_HIBERNATION);
    animal_index++;
  }
}

void Ecosystem::RunEcosystem(int day) {
  return;
}

void Ecosystem::PrintPlantStatistics(void) {
  cout << endl;
  cout << "Total number of grasses: " << no_of_grass << endl;
  cout << "Total number of algaes: " << no_of_algae << endl;
  cout << "Total number of maples: " << no_of_maple << endl;
  cout << "Total number of oaks: " << no_of_oak << endl;
  cout << "Total number of pines: " << no_of_pine << endl;
}

void Ecosystem::PrintAnimalStatistics(void) {
  cout << endl;
  cout << "Total number of deers: " << no_of_deer << endl;
  cout << "Total number of rabbits: " << no_of_rabbit << endl;
  cout << "Total number of groundhogs: " << no_of_groundhog << endl;
  cout << "Total number of salmons: " << no_of_salmon << endl;
  cout << "Total number of foxes: " << no_of_fox << endl;
  cout << "Total number of bears: " << no_of_wolf << endl;
}

void Ecosystem::PrintGrid(void) {
  for(int i = 0; i < terrain_size; i++) {
    for(int j = 0; j < terrain_size; j++) {
      if(terrain_grid[i][j].GetGround() == WATER_TILE){
        cout << BLU << terrain_grid[i][j].GetGround() << RESET;
      } else if(terrain_grid[i][j].GetGround() == HILL_TILE) {
        cout << RED << terrain_grid[i][j].GetGround() << RESET;
      } else if(terrain_grid[i][j].GetGround() == MEADOW_TILE) {
        cout << GRN << terrain_grid[i][j].GetGround() << RESET;
      }
    }
    cout << endl;
  }
}
