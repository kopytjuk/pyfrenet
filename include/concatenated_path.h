#include <utility>
#include <math.h>
#include <complex>
#include<numeric>
#include<vector>
#include<memory>

#include "base_path.h"
#include "line_path.h"

#ifndef CONCATPATH_H
#define CONCATPATH_H

class ConcatenatedPath : public BasePath{

    private:
        std::vector<std::shared_ptr<BasePath>> _paths;

    public:

        ConcatenatedPath(){
            //auto ptr = std::make_shared<LinePath>(0.0, 0.0, 1.0, 1.0);
            //auto ptr = std::shared_ptr<LinePath>(new LinePath());
            //_paths = { ptr};
        };

        ConcatenatedPath(std::vector<std::shared_ptr<BasePath>> paths){
            _paths = paths;
        };

        std::pair<double, double> to_cartesian(double s, double d) override {
            return std::pair<double, double> (0, 0);
        };

        std::pair<double, double> to_frenet(double x, double y) override {
            return std::pair<double, double> (0, 0);
        };

        std::pair<double, double> tangential_vector(double s) override {

            return std::pair<double, double> (0, 0);
        };

        std::pair<double, double> normal_vector(double s) override {

            return std::pair<double, double> (0, 0);
        };

        double get_length() override {
            return 42.0;
        }

        // heading vector of the tangent vector (0° north, 270° west)
        double psi(double s){
            return 0.0;
        }
};

#endif