#include "base_path.h"
#include <utility>
#include <math.h>

class LinePath : BasePath{

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
            return std::pair<double, double> (0.0, 0.0);
        };

        std::pair<double, double> to_frenet(double s, double d) override {
            return std::pair<double, double> (0.0, 0.0);
        };

        std::pair<double, double> tangential_vector(double s) override {
            return std::pair<double, double> (0.0, 0.0);
        };

        std::pair<double, double> normal_vector(double s) override {
            return std::pair<double, double> (0.0, 0.0);
        };

        double get_length() override {
            return 42.0;
        }

        // heading vector of the tangent vector (0° north, 270° west)
        double psi(double s){
            double dx = pt_end.first - pt_start.first;
            double dy = pt_end.second - pt_start.second;
            double angle = std::atan2(dy, dx);
            return angle;
        }
};