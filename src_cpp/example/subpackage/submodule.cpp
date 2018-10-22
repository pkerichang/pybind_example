#include <memory>

#include <string>

#include <example/subpackage/submodule.h>

class sample_class {
private:
  int var_private;

public:
  double var_public;
  const int var_readonly = 6;

  sample_class() : var_private(0), var_public(1) {}

  int get_var_private() { return var_private; }
  void set_var_private(int val) { var_private = val; }
  int add_to_private(int val) { return var_private + val; }

  static std::string get_desc() { return "A sample class"; }
  static const std::string foobar;
};

const std::string sample_class::foobar = "foobar";

void bind_subpackage_submodule(py::module &m_top) {
  py::module m = m_top.def_submodule("submodule");
  m.doc() = "This is a Python module.";

  // add module static method
  m.def("add", [](int a, int b = 3) { return a + b; }, "An add fuction.",
        py::arg("a"), py::arg("b") = 3);

  // add module variable
  m.attr("answer") = 42;

  // add module class
  auto c = py::class_<sample_class>(m, "SampleClass");
  // write the doc string for the class
  c.doc() = R"mydelim(A sample class.

Parameters
----------
value : Optional[Tuple[int, double]]
    set the class variables to the given tuple.
)mydelim";

  // add custom constructor that unpacks the given python tuple
  // disable auto-signature so we use correct type hinting
  py::options options;
  options.disable_function_signatures();

  const char *init_doc =
      "__init__(self, value: Optional[Tuple[int, float]]=None) -> None";
  c.def(py::init([](py::object value = py::none()) {
          auto ans = std::make_unique<sample_class>();
          if (!value.is_none()) {
            auto tmp = value.cast<py::tuple>();
            ans->set_var_private(tmp[0].cast<py::int_>());
            ans->var_public = tmp[1].cast<py::float_>();
          }
          return ans;
        }),
        init_doc, py::arg_v("value", py::none()).none(true));

  options.enable_function_signatures();

  // add method
  c.def("add_to_private", &sample_class::add_to_private,
        "Add given value to private var and return result ", py::arg("val"));

  // add class method
  c.def_static("get_desc", &sample_class::get_desc, "get a description string");

  // add public member
  c.def_readwrite("var_public", &sample_class::var_public, "A public member");

  // add private member through getter/setter
  c.def_property("var_private", &sample_class::get_var_private,
                 &sample_class::set_var_private, "A private member");

  // add read only property
  c.def_readonly("var_readonly", &sample_class::var_readonly,
                 "A readonly public member");

  // add class member
  c.def_property_readonly_static(
      "foobar", [](py::object) { return sample_class::foobar; },
      "A class member");
}
