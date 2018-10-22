#ifndef EXAMPLE_SUBPACKAGE_MODULE_H
#define EXAMPLE_SUBPACKAGE_MODULE_H

#include <pybind11/pybind11.h>

#include <example/subpackage/submodule.h>

void bind_subpackage(py::module &);

#endif
