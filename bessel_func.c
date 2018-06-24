// series representations of bessel functions
// author: Cohen Robinson
// date: 24/06/18

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long double factorial(int);
double bessel_n(int, double);

#define MAX_ARRAY 1001

int main(void)
{
  FILE *fp = fopen("bessel.dat", "w");

  if (fp == NULL){
    printf("Error opening file!");
    exit(1);
  }
  double j0;
  double j1;
  double x = 0;

  float j0p[MAX_ARRAY];
  float j1p[MAX_ARRAY];
  float xp[MAX_ARRAY];

  int i;
  for (i=0;i<1001;i++){
    x = 0.01*i;

    j0 = bessel_n(0, x);
    j1 = bessel_n(1, x);

    j0p[i] = j0;
    j1p[i] = j1;

    fprintf(fp, " %f %f\n", j0, j1);
  }
  fclose(fp);
  return (0);
}

// factorial function for bessel function
long double factorial(int n)
{
  long double fact = 1;
  for (int c=1; c<=n; c++){
    fact = fact * c;
  }
  return fact;
}

// bessel function definition
double bessel_n(int n, double x)
{
  long double f_k = 0;
  long double f_kn = 0;
  int k;
  double frac = 1;
  double a_k = 0;
  for (k=0; k<=200; k++)
  {
    // determine factor of (-1)^k
    if (k%2 == 0) {
      frac = 1;
    }
    else {
      frac = -1;
    }

    // assign k! and (k+n)!
    f_k = factorial(k);
    f_kn = factorial(k+n);
    long double power = 1;
    // calculate exp function
    for (int i=1; i<=2*k+n; i++){
      // iteratively increase power
      power *= (0.5*x);
    }
    // sum the series
    a_k += (frac/(f_k*f_kn)) * power;
  }
  return a_k;
}
