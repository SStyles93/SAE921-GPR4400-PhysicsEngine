#include "Vector.h"

int main()
{
    Vector v1(2, 2);
    Vector v2(1, -1);
    Vector vTemp(0,0);
    vTemp = v1 + v2;
    vTemp = v1 - v2;

    vTemp = v1 + v2;
    float magn = vTemp.Magnitude();
    vTemp = v1 + v2;
    float sqrMagn = vTemp.SqrMagnitude();
    vTemp = v1 + v2;
    Vector vTemp2 = vTemp.Normalized();

    vTemp = v1 * magn;
    vTemp = v1 / magn;

    return EXIT_SUCCESS;
}