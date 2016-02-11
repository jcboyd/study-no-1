# lanczos

The Lanczos approximation, named after Cornelius Lanczos (1893-1974), is a reformulation of the gamma function,

![gamma](http://jcboyd.github.io/img/gamma.png)

The gamma function is a vitally important function in many areas of mathematics, particularly statistics, where it underpins density functions. The gamma function interpolates the factorial function with,

![factorial](http://jcboyd.github.io/img/factorial.png)

with the unfortunate offset due to Legendre. The gamma function further extends the factorial functions to the real and complex domains. Apart from a few well-defined identities, the gamma function is difficult to evaluate, in contrast with, for example, the error function (erf), which can easily be approximated by a Maclaurin series. Classical approaches to approximating the gamma function utilised Stirling's approximation (see https://github.com/jcboyd/lastchancestats for a derivation).

The Lanzcos approximation reformulates the gamma function to include an infinite series,

![lanczos](http://jcboyd.github.io/img/lanczos.png)

The infinite series expansion is,

![series](http://jcboyd.github.io/img/series.png)

The p coefficients themselves have a complicated formulation, involving the coefficients of Chebyshev polynomial and gamma function identities. To save computation time, the series is reformulated by the method of partial fractions, producing a new set of coefficients that can be combined in a simplified way.

The reflection formula is a useful identity due to Euler, that relates the gamma function for positive and negative reals,

![reflection](http://jcboyd.github.io/img/reflection.png)

An implementation of the gamma function need only therefore account for complex numbers with positive real part then ''reflect'' any negatives.

This module provides an implementation of the gamma function as well as a set of functions used to compute the coefficients. This part is written in C, and an interface file for SWIG (https://github.com/swig/swig) and setup file is provided for use in Python.