#include <stdio.h>
#include <math.h>
#include <assert.h>

double __enzyme_fwddiff(void*, ...);

void compute_loops(float* a, float* b, float* ret) {
  double sum0 = 0.0;
  for (int i = 0; i < 100; i++) {
    sum0 += *a + *b;
  }
  *ret = sum0;
}

int main(int argc, char** argv) {
  float a = 2.0;
  float b = 3.0;

  float da = 1.0;//(float*) malloc(sizeof(float));
  float db = 1.0;//(float*) malloc(sizeof(float));

  float ret = 0;
  float dret = 1.0;

  __enzyme_fwddiff(compute_loops, &a, &da, &b, &db, &ret, &dret);
  printf("ret %f, dret %f, da: %f, db: %f\n", ret, dret, da, db);

  return 0;
}