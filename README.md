# PyFrenet

[Frenet–Serret](https://en.wikipedia.org/wiki/Frenet%E2%80%93Serret_formulas) coordinate system transformation written in C++ and wrapped with pybind11.

## Build instructions

First setup `pyenv`, then

```
PYTHON_INCLUDE_PATH=/root/.pyenv/versions/3.9.13/include/python3.9
c++ -O3 -Wall -shared -std=c++11 -fPIC -I extern/pybind11/include example.cpp -I $PYTHON_INCLUDE_PATH -o example$(python-config --extension-suffix)
```
