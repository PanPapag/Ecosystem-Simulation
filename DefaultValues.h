#pragma once

/*------------------------- Default values for plants ------------------------*/

#define ALIVE true

#define GRASS_TOKEN 'G'
#define GRASS_LIFE 5
#define GRASS_BREEDING 15
#define GRASS_ILLNESS 15
#define GRASS_LIFE_FACTOR 4

#define ALGAE_TOKEN 'A'
#define ALGAE_LIFE 5
#define ALGAE_BREEDING 25
#define ALGAE_ILLNESS 25
#define ALGAE_LIFE_FACTOR 2

#define MAPLE_TOKEN 'M'
#define MAPLE_FOLIAGE 5
#define MAPLE_SEEDS 10
#define MAPLE_SIZE 2
#define MAPLE_BREEDING 5
#define MAPLE_ILLNESS 5
#define MAPLE_LIFE_FACTOR 10

#define OAK_TOKEN 'O'
#define OAK_FOLIAGE 30
#define OAK_SEEDS 15
#define OAK_SIZE 5
#define OAK_BREEDING 20
#define OAK_ILLNESS 20
#define OAK_LIFE_FACTOR 15

#define PINE_TOKEN 'P'
#define PINE_FOLIAGE 40
#define PINE_SEEDS 20
#define PINE_SIZE 5
#define PINE_BREEDING 15
#define PINE_ILLNESS 15
#define PINE_LIFE_FACTOR 20

/*------------------------- Default values for animals -----------------------*/

#define HERB_TOKEN 'H'
#define CARN_TOKEN 'C'

#define Y_DEER_SIZE 2
#define Y_DEER_SPEED 4
#define Y_DEER_NEED_FOOD 4
#define A_DEER_SIZE 5
#define A_DEER_SPEED 8
#define A_DEER_NEED_FOOD 8
#define DEER_CLIMB false
#define DEER_HIBERNATION false

#define Y_RABBIT_SIZE 1
#define Y_RABBIT_SPEED 2
#define Y_RABBIT_NEED_FOOD 2
#define A_RABBIT_SIZE 2
#define A_RABBIT_SPEED 6
#define A_RABBIT_NEED_FOOD 4
#define RABBIT_CLIMB false
#define RABBIT_HIBERNATION false

#define Y_GROUNDHOG_SIZE 2
#define Y_GROUNDHOG_SPEED 3
#define Y_GROUNDHOG_NEED_FOOD 3
#define A_GROUNDHOG_SIZE 3
#define A_GROUNDHOG_SPEED 5
#define A_GROUNDHOG_NEED_FOOD 5
#define GROUNDHOG_CLIMB true
#define GROUNDHOG_HIBERNATION false

#define A_SALMON_SIZE 1
#define A_SALMON_SPEED 5
#define A_SALMON_NEED_FOOD 1
#define SALMON_CLIMB false
#define SALMON_HIBERNATION false

#define Y_FOX_SIZE 1
#define Y_FOX_SPEED 2
#define Y_FOX_NEED_FOOD 2
#define Y_FOX_ATTACK 1
#define Y_FOX_DEFENCE 1
#define A_FOX_SIZE 4
#define A_FOX_SPEED 6
#define A_FOX_NEED_FOOD 6
#define A_FOX_ATTACK 5
#define A_FOX_DEFENCE 5
#define FOX_HIBERNATION false

#define Y_WOLF_SIZE 1
#define Y_WOLF_SPEED 2
#define Y_WOLF_NEED_FOOD 2
#define Y_WOLF_ATTACK 2
#define Y_WOLF_DEFENCE 2
#define A_WOLF_SIZE 7
#define A_WOLF_SPEED 8
#define A_WOLF_NEED_FOOD 8
#define A_WOLF_ATTACK 8
#define A_WOLF_DEFENCE 6
#define WOLF_HIBERNATION false

#define Y_BEAR_SIZE 3
#define Y_BEAR_SPEED 4
#define Y_BEAR_NEED_FOOD 5
#define Y_BEAR_ATTACK 6
#define Y_BEAR_DEFENCE 6
#define A_BEAR_SIZE 10
#define A_BEAR_SPEED 4
#define A_BEAR_NEED_FOOD 10
#define A_BEAR_ATTACK 10
#define A_BEAR_DEFENCE 10
#define BEAR_HIBERNATION true

/*------------------------- Default values for ecosystem ---------------------*/

#define WATER_TILE '#'
#define HILL_TILE '^'
#define MEADOW_TILE '"'
#define EMPTY '.'

#define DIVERSION_FACTOR 30

#define LEFT 0
#define RIGHT 1

/*------------------------- Default values for colors ------------------------*/

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
