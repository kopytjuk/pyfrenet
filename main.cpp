#include <iostream>
#include <math.h>

#include "line_path.h"
#include "concatenated_path.h"

template<typename T>
T rad2deg(T angle)
{
    return angle*180/M_PI;
}

int main(int argc, char *argv[])
{
    LinePath lp(0.0, 0.0, 10.0, 10.0);
    std::cout << "lp.psi: " << rad2deg(lp.psi(4.0)) << "°" << std::endl;

    LinePath lp2(0.0, 0.0, 10.0, 1.0);
    auto pt_frenet = lp2.to_frenet(5.0, 1.0);
    std::cout << "lp.to_frenet(5.0, 1.0): s=" << pt_frenet.first << ", d=" << pt_frenet.second << std::endl;

    auto pt_cart = lp2.to_cartesian(5.0, 1.0);
    std::cout << "lp.to_cartesian(5.0, 1.0): x=" << pt_cart.first << ", y=" << pt_cart.second << std::endl;
}