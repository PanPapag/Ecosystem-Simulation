struct point {
  int x;
  int y;
  point(int xx, int yy):x(xx), y(yy){}
};

class Plant{
  public:
    Plant(char*, int, int, char, int, int, int, int);
    ~Plant();
    bool IsDead(void);
    int GetLife(void);
    virtual void EatenByAnimal(int);
    virtual void Grow(void);
    virtual bool Reproduced(void);

  protected:
    char* name;
    point* coordinates;
    char token;
    int breeding_prob;
    int illness_prob;
    unsigned int life;
    int life_factor;
};

class Seedless : public Plant{
  public:
    Seedless(char*, int, int, char, int, int, int, int);
    void LooseLife(void);
    void EatenByAnimal(int);
    void Grow(void);
    bool Reproduced(void);
};

class Leaves{
public:
  Leaves(int);
  int GetNumber();
  void IncreaseSize(void);
  void DecreaseSize(void);
  void IncreaseNumber(int);
  void DecreaseNumber(int);

private:
  unsigned int size;
  unsigned int quantity;
};

class Seeded : public Plant{
  public:
    Seeded(char*, int, int, char, int, int, int, int, int, int);
    void EatenByAnimal(int);
    void Grow(void);
    bool Reproduced(void);
  private:
    Leaves foliage;
    int seeds;
};
