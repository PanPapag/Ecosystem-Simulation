#ifndef __UTILITIES__
#define __UTILITIES__

typedef struct {
  int x;
  int y;
} coordinates;

bool RandomResult(int);
void FillPoints(coordinates *,int);
void ShufflePoints(coordinates *,int,int);
void swap(coordinates *,coordinates *);

#endif
