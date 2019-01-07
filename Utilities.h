#pragma once

#include "DefaultValues.h"

typedef struct {
  int x;
  int y;
} coordinates;

bool RandomResult(int);
void FillPoints(coordinates *,int);
void ShufflePoints(coordinates *,int,int);
void swap(coordinates *,coordinates *);
