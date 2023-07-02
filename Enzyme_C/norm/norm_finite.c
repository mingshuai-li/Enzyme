#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

float tdiff(struct timeval *start, struct timeval *end) {
  return (end->tv_sec - start->tv_sec) + 1e-6 * (end->tv_usec - start->tv_usec);
}

__attribute__((const, noinline))
double mag(const double *A, int n) {
  double amt = 0;
  for (int i = 0; i < n; i++) amt += A[i];
  return amt;
}

void normalize(double *__restrict__ out, const double *__restrict__ in, int n) {
  for (int i = 0; i < n; ++i)
    out[i] = in[i] / mag(in, n);
}

// Finite difference approximation of the gradient of normalize function
void finiteDifferenceNormalize(double *__restrict__ grad_A, const double *__restrict__ A, int n, double h) {
  double *tmp = (double*)malloc(sizeof(double) * n);
  assert(tmp != 0);

  double *tmp2 = (double*)malloc(sizeof(double) * n);
  assert(tmp2 != 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      tmp[j] = A[j];
      tmp2[j] = A[j];
    }

    tmp[i] += h;
    tmp2[i] -= h;

    double mag1 = mag(tmp, n);
    double mag2 = mag(tmp2, n);

    grad_A[i] = (mag1 - mag2) / (2 * h);
  }

  free(tmp);
  free(tmp2);
}

void __enzyme_autodiff(void*, ...);
int enzyme_const, enzyme_dup, enzyme_out;

int main(int argc, char *argv[]) {
  struct timeval start, end;
  int n = 1000000;
  int x = 20;
  if (argc > 1) {
    n = atoi(argv[1]);
    if (argc > 2) {
      x = atoi(argv[2]);
    }
  }

  double *A = (double*)malloc(sizeof(double) * n);
  assert(A != 0);

  double *B = (double*)malloc(sizeof(double) * n);
  assert(B != 0);
  for (int i = 0; i < n; i++)
    B[i] = x;


  double *grad_A = (double*)malloc(sizeof(double) * n);
  assert(grad_A != 0);
  for (int i = 0; i < n; i++)
    grad_A[i] = 1.0;

  double *grad_B = (double*)malloc(sizeof(double) * n);
  assert(grad_B != 0);
  for (int i = 0; i < n; i++)
    grad_B[i] = 0.0;


  gettimeofday(&start, NULL);

  normalize(A, B, n);

  gettimeofday(&end, NULL);
  printf("Serial Normalize %0.6f %f\n", tdiff(&start, &end), A[n-1]);

  gettimeofday(&start, NULL);

  __enzyme_autodiff((void*)normalize,
                    enzyme_dup, A, grad_A,
                    enzyme_dup, B, grad_B,
                    enzyme_const, n);

  gettimeofday(&end, NULL);
  printf("Gradient Normalize %0.6f %f %f\n", tdiff(&start, &end), A[n-1], grad_B[0]);

  // Calculate gradient using finite difference approximation
  double h = 1e-6; // Step size
  double *grad_A_finite = (double*)malloc(sizeof(double) * n);
  assert(grad_A_finite != 0);
  finiteDifferenceNormalize(grad_A_finite, A, n, h);

  printf("Finite Difference Gradient Normalize: %f\n", grad_A_finite[0]);

  free(A);
  free(B);
  free(grad_A_finite);
  return 0;
}
