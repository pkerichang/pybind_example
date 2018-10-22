#ifndef EXAMPLE_SUBPACKAGE_SUBMODULE_H
#define EXAMPLE_SUBPACKAGE_SUBMODULE_H

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bind_subpackage_submodule(py::module &);

#endif
