#ifndef __ECOSYSTEM__
#define __ECOSYSTEM__

using namespace std;

class Tile {

  public:
    Tile();
    ~Tile();
    void SetGround(char);
    char GetGround();

  private:
    char ground;

};

class Ecosystem {

  public:
    Ecosystem(int,string);
    ~Ecosystem();

  private:
    int terrain_size;
    string current_season;

    class Tile **terrain_grid;

    void MapGenerator();
    int GenerateRiver();
    int GenerateLake();
    int GenerateHills();
    int GenerateMeadow();
};

#endif
