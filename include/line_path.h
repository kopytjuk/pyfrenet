#include "base_path.h"
#include <utility>
#include <math.h>
#include <complex>
#include<numeric>
#include<vector>

#ifndef LINEPATH_H
#define LINEPATH_H

class LinePath : public BasePath {

    private:
        std::pair<double, double> pt_start;
        std::pair<double, double> pt_end;

    public:
        LinePath(std::pair<double, double> x0, std::pair<double, double> x1): pt_start(x0), pt_end(x1) {
        };

        LinePath(double x0, double y0, double x1, double y1){
            pt_start = std::pair<double, double> (x0, y0);
            pt_end = std::pair<double, double> (x1, y1);
        };

        LinePath(){
            pt_start = std::pair<double, double> (0.0, 0.0);
            pt_end = std::pair<double, double> (1.0, 1.0);
        };

        std::pair<double, double> to_cartesian(double s, double d) override {

            std::pair<double, double> t_vector = tangential_vector(s);
            std::pair<double, double> n_vector = normal_vector(s);

            double x = pt_start.first + s*t_vector.first + d*n_vector.first;
            double y = pt_start.second + s*t_vector.second + d*n_vector.second;

            return std::pair<double, double> (x, y);
        };

        std::pair<double, double> to_frenet(double x, double y) override {

            double len = get_length();

            std::vector<double> a = {x - pt_start.first , y - pt_start.second};
            std::vector<double> p = {pt_end.first - pt_start.first , pt_end.second - pt_start.second};

            double s = std::inner_product(a.begin(), a.end(), p.begin(), 0.0)/len;

            double len_a = std::sqrt(std::inner_product(a.begin(), a.end(), a.begin() , 0.0));

            double d = 0.0;
            if (len_a > 0){
                d = len_a*sin(acos(s/len_a));
            }
            return std::pair<double, double> (s, d);
        };

        std::pair<double, double> tangential_vector(double s) override {

            double psi_angle = psi(s);

            double tx, ty;
            tx = cos(psi_angle);
            ty = sin(psi_angle);

            return std::pair<double, double> (tx, ty);
        };

        std::pair<double, double> normal_vector(double s) override {

            double psi_angle = psi(s);

            double nx, ny;
            nx = cos(psi_angle + M_PI_2);
            ny = sin(psi_angle + M_PI_2);

            return std::pair<double, double> (nx, ny);
        };

        double get_length() override {
            std::complex<double> p (pt_end.first - pt_start.first , pt_end.second - pt_start.second);
            return std::abs(p);
        }

        // heading vector of the tangent vector (0° north, 270° west)
        double psi(double s){
            double dx = pt_end.first - pt_start.first;
            double dy = pt_end.second - pt_start.second;
            double angle = std::atan2(dy, dx);
            return angle;
        }
};

#endif