#include "Vector.h"

int main()
{
    Vector v1(1, 1);
    Vector v2(2, 2);
    Vector vTemp(0,0);
    vTemp = v1 + v2;
    vTemp = v1 - v2;

    vTemp = v1 + v2;
    float magn = vTemp.Magnitude();
    vTemp = v1 + v2;
    float sqrMagn = vTemp.SqrMagnitude();

    return EXIT_SUCCESS;
}