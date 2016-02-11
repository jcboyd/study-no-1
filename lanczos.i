/* lanczos.i */
%module lanczos
%{
/* Put header files here or function declarations like below */
extern double gamma_x(double rez, double imz);
%}

extern double gamma_x(double rez, double imz);