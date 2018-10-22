#include <example/module.h>

PYBIND11_MODULE(example, m) {
  m.doc() = "This Python package only contains a submodule.";

  bind_subpackage(m);
}
