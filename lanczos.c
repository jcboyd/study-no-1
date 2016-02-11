#include <math.h>
#include <complex.h>

const double g = 1;

const double c[] = {
    1.000001502363886407565018998866435140371322631835938,
    0.464895966191246401422176859341561794281005859375000,
    -0.04956300218599807294594938866794109344482421875000,
    0.387353748287360133417678298428654670715332031250000,
    -2.32544894194688822608441114425659179687500000000000,
    8.977536034497006767196580767631530761718750000000000,
    -21.8474347546784883888904005289077758789062500000000,
    33.28472248815523926168680191040039062500000000000000,
    -30.7328214590961579233407974243164062500000000000000,
    15.70077904063509777188301086425781250000000000000000,
    -3.40185381879564374685287475585937500000000000000000}

double gamma_x(double rez, double imz) {
    if (rez < 0) {
        // Apply reflection formula for negative base
        // complex<double> z = (rez - 1) + imz;
        // return M_PI * z / sin(M_PI * z) * gamma(-rez, imz)
    }
    else {
        complex<double> z = (rez - 1) + imz;
        // z = complex(z) - 1  # Lanzcos solves for gamma(z + 1)

        series = c[0]
        for(int i = 1; i < sizeof(c)/sizeof(double); i++) {
            series += c[i]/(z + i)
        }

        double t = z + g + 0.5;
        prod = sqrt(2 * pi) * t ** (z + 0.5) * exp(-t) * series;
        return prod
    }
    return 0;
}

int main() {
    return 0;
}
