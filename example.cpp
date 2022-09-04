#include <pybind11/pybind11.h>

#include "line_path.h"

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");

    py::class_<LinePath>(m, "LinePath")
        .def(py::init<>())
        .def(py::init<std::pair<double, double>, std::pair<double, double>>())
        .def("get_length", &LinePath::get_length);
}
