#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Utilities.h"

bool RandomResult(int factor) {
  int res = rand() % 101;
  if (res > factor) return true;
  else return false;
}

void FillPoints(coordinates *points_array,int size) {
  int index = 0;
  for(int j = 0; j < size; j++) {
    for(int k = 0; k < size; k++) {
      points_array[index].x = j;
      points_array[index].y = k;
      index++;
    }
  }
}

void swap(coordinates *arr1, coordinates *arr2) {
  coordinates *temp = arr1;
  arr1 = arr2;
  arr2 = temp;
}

void ShufflePoints(coordinates *points_array, int start, int end) {
  for (int i = end - 1; i > start; i--) {
    int j = rand() % (i+1);
    swap(points_array[i], points_array[j]);
   }
}
