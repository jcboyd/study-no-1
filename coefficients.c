#include <math.h>
#include <complex.h>
#include <stdio.h>

/*
The following code was used to produce the set of coefficients
*/

const double partials[][11] = {
    {0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 2, -6, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, -3, 24, -30, 0, 0, 0, 0, 0, 0, 0},
    {1, 4, -60, 180, -140, 0, 0, 0, 0, 0, 0},
    {1, -5, 120, -630, 1120, -630, 0, 0, 0, 0, 0},
    {1, 6, -210, 1680, -5040, 6300, -2772, 0, 0, 0, 0},
    {1, -7, 336, -3780, 16800, -34650, 33264, -12012, 0, 0, 0},
    {1, 8, -504, 7560, -46200, 138600, -216216, 168168, -51480, 0, 0},
    {1, -9, 720, -13860, 110880, -450450, 1009008, -1261260, 823680, -218790, 0},
    {1, 10, -990, 23760, -240240, 1261260, -3783780, 6726720, -7001280, 3938220, -923780}};

// Computes n! for integer n
long factorial(int n) {
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

// Computes (n + 1/2)! for integer n using gamma function identities
double gamma_identity(int n) {
    if (n < 0) {
        return sqrt(M_PI) * pow(-4.0, -n) * factorial(-n) / factorial(-2 * n);
    }
    else if(n == 0) {
        return sqrt(M_PI);
    }
    else {
        return sqrt(M_PI) * factorial(2 * n) / (pow(4.0, n) * factorial(n));
    }
}

// Computes the jth coefficient of the ith first-kind chebyshev polynomial
int chebyshev(int i, int j) {
    if(i > j && j >= 2) {
        return 2 * chebyshev(i - 1, j - 1) - chebyshev(i - 2, j);
    }
    else if(i >= 3 && j == i) {
        return 2 * chebyshev(i - 1, j - 1);
    }
    else if(i >= 3 && j == 1) {
        return -1 * chebyshev(i - 2, 1);
    }
    else {
        return 1;
    }
}

// Computes coefficient for series in the Lanczos formula
double p_coefficients(int k, double g) {
    double p = 0;
    for(int a = 0; a <= k; a++){
        double val = chebyshev(2 * k + 1, 2 * a + 1) * sqrt(2) / M_PI *
            gamma_identity(a) * pow(a + g + 0.5, -a - 0.5) * exp(a + g + 0.5);
        p += val;
    }
    return p;
}

// Computes coefficient for series in the Lanczos formula
double c_coefficients(int index, double g){
    double c = 0;
    for(int i = 0; i < sizeof(partials[0])/sizeof(double); i++) {
        c += partials[i][index] * p_coefficients(i, g);
    }
    return c;
}

int main() {
    // printf("%f\n", pow(2, 3));
    // printf("%d\n", chebyshev(15, 11));
    // printf("%d\n", chebyshev(15, 13));
    // printf("%d\n", chebyshev(15, 15));
    // printf("%.51lf\n", exp(1));
    // printf("%ld\n", sizeof(partials[0])/sizeof(double));
    // printf("%.51lf\n", M_PI);
    // printf("%.51lf\n", p_coefficients(7, 1));
    // printf("%d\n", factorial(14));
    //printf("%f\n", pow(4, 7));
    // printf("%.51lf\n", gamma_identity(7));
    double g = 1;
    printf("%.51lf\n", c_coefficients(0, g));
    printf("%.51lf\n", c_coefficients(1, g));
    printf("%.51lf\n", c_coefficients(2, g));
    printf("%.51lf\n", c_coefficients(3, g));
    printf("%.51lf\n", c_coefficients(4, g));
    printf("%.51lf\n", c_coefficients(5, g));
    printf("%.51lf\n", c_coefficients(6, g));
    printf("%.51lf\n", c_coefficients(7, g));
    printf("%.51lf\n", c_coefficients(8, g));
    printf("%.51lf\n", c_coefficients(9, g));
    printf("%.51lf\n", c_coefficients(10, g));
    // printf("%ld\n", sizeof(partials[0])/sizeof(double));
    return 0;
}
