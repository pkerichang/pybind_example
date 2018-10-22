#include <example/subpackage/module.h>

void bind_subpackage(py::module &m_top) {
  py::module m = m_top.def_submodule("util");

  m.doc() = "This is a Python package contains a submodule and some "
            "functions/attributes.";

  // add module static method
  m.def("concat",
        [](const std::string &a, const std::stirng &b) { return a + b; },
        "Concatenate two strings.");

  // add module variable
  m.attr("where") = "the world";

  bind_subpackage_submodule(m);
}
