#pragma once

using namespace std;

typedef struct {
  int x;
  int y;
  bool used;
} coordinates;

bool RandomResult(int);
void FillPoints(coordinates *,int);
void ShufflePoints(coordinates *,int,int);
void swap(coordinates *,coordinates *);
void EraseSubStr(string &, const string &);
