#include "Vector.h"

int main()
{
    Vector2 v1(2, 2);
    Vector2 v2(1, -1);
    Vector2 vTemp(0,0);
    vTemp = v1 + v2;
    vTemp = v1 - v2;

    vTemp = v1 + v2;
    float magn = vTemp.Magnitude();
    vTemp = v1 + v2;
    float sqrMagn = vTemp.SqrMagnitude();
    vTemp = v1 + v2;
    Vector2 vTemp2 = vTemp.Normalized();

    vTemp = v1 * magn;
    vTemp = v1 / magn;

    vTemp = v1 + v2;
    vTemp += v1;
    vTemp -= v1;

    vTemp = Vector2(0, 1);
    vTemp2 = Vector2(1, 0);

    float dot = vTemp.Dot(vTemp2);

    return EXIT_SUCCESS;
}