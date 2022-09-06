#include <utility>

#ifndef BASEPATH_H
#define BASEPATH_H

class BasePath
{   
    public:
        virtual std::pair<double, double> to_cartesian(double s, double d) = 0;
        virtual std::pair<double, double> to_frenet(double x, double y) = 0;
        virtual std::pair<double, double> tangential_vector(double s) = 0;
        virtual std::pair<double, double> normal_vector(double s) = 0;
        virtual double get_length() = 0;
};

#endif