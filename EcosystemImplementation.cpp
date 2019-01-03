#include <iostream>
#include <cstring>
#include <cstdlib>

#include "EcosystemInterface.h"


/* -------------------------------------- class Tile Implementation ------------------------------------- */
Tile::Tile() {
  ground = 'X';
}

Tile::~Tile() {
  //cout << "Tile destructed" << endl;
}

char Tile::GetGround() {
  return ground;
}

void Tile::SetGround(char category) {
  ground = category;
}

/* ----------------------------------- class Ecosystem Implementation ----------------------------------- */

Ecosystem::Ecosystem(int size, string season) {
  terrain_size = size;
  current_season = season;

  terrain_grid = new Tile *[terrain_size];
   for(int i = 0; i < terrain_size; i++) {
      terrain_grid[i] = new Tile();
   }
}

Ecosystem::~Ecosystem() {

  for(int i = 0; i < terrain_size; i++) {
    delete terrain_grid[i];
  }
  delete [] terrain_grid;

  cout << "Ecosystem destroyed. End of the simulation!" << endl;
}
