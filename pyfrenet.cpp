#include <pybind11/pybind11.h>

#include "line_path.h"

namespace py = pybind11;

PYBIND11_MODULE(pyfrenet, m) {
    m.doc() = "PyFrenet library."; // optional module docstring

    py::class_<LinePath>(m, "LinePath")
        .def(py::init<>())
        .def(py::init<std::pair<double, double>, std::pair<double, double>>())
        .def("get_length", &LinePath::get_length)
        .def("to_frenet", &LinePath::to_frenet)
        .def("to_cartesian", &LinePath::to_cartesian);
}
