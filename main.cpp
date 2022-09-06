#include <iostream>
#include <math.h>

#include "line_path.h"

template<typename T>
T rad2deg(T angle)
{
    return angle*180/M_PI;
}

int main(int argc, char *argv[])
{
    LinePath lp(0.0, 0.0, 10.0, 10.0);
    std::cout << "lp.psi: " << rad2deg(lp.psi(4.0)) << "°" << std::endl;
}