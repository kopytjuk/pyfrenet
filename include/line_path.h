#include "base_path.h"
#include <utility>

class LinePath : BasePath{

    private:
        std::pair<double, double> x_start;
        std::pair<double, double> x_end;

    public:
        LinePath(std::pair<double, double> x0, std::pair<double, double> x1): x_start(x0), x_end(x1) {
        };

        LinePath(){
            x_start = std::pair<double, double> (0.0, 0.0);
            x_end = std::pair<double, double> (1.0, 1.0);
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
};