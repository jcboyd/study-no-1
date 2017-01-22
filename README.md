# lanczos

The Lanczos approximation, named after Cornelius Lanczos (1893-1974), is a reformulation of the gamma function,

![gamma](http://jcboyd.github.io/assets/lanczos/gamma.png)

The gamma function is a vitally important function in many areas of mathematics, such as geometry, calculus, and particularly statistics, where it underpins various density functions such as the chi-squared and Student's t-distribution. The gamma function interpolates the factorial function with,

![factorial](http://jcboyd.github.io/assets/lanczos//factorial.png)

which may be seen by integrating by parts. It is the only log-convex function that achieves this. The unfortunate offset is due to Legendre. The gamma function further extends the factorial function to the real and complex domains.

Apart from a few well-defined identities, the gamma function is difficult to evaluate, in contrast with, for example, the error function (erf), which can easily be approximated by a Maclaurin series. Classical approaches to approximating the gamma function utilised Stirling's approximation (see https://github.com/jcboyd/lastchancestats for a derivation). The Lanzcos approximation reformulates the gamma function to include an infinite series,

![lanczos](http://jcboyd.github.io/assets/lanczos//lanczos.png)

The infinite series expansion is,

![series](http://jcboyd.github.io/assets/lanczos//series.png)

where g is a freely-chosen positive real. The p coefficients themselves have a complicated formulation, involving the coefficients of Chebyshev polynomials and gamma function identities. To save computation time, the series is reformulated using partial fractions decomposition, producing a new set of coefficients that can be combined in a simplified way. For a well-chosen constant g and a small number of terms in the series, the Lanczos approximation is accurate to within floating-point precision. Consequently, it is scarcely more expensive than computing, say, trigonometric functions, or the exponential function.

The reflection formula is a useful identity due to Euler, that relates the gamma function for positive and negative reals,

![reflection](http://jcboyd.github.io/assets/lanczos//reflection.png)

An implementation of the gamma function therefore need only account for complex numbers with positive real part then ''reflect'' any negatives.

This module gives an implementation in C of the gamma function as well as a set of functions used to compute the coefficients. An interface file for SWIG (https://github.com/swig/swig) and setup file is provided for use in Python.
