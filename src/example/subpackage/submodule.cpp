#include <memory>

#include <example/subpackage/submodule.h>

class sample_class {
private:
  int var_private;

public:
  double var_public;

  sample_class() : var_private(0), var_public(1) {}

  int get_var_private() { return var_private; }
  void set_var_private(int val) { var_private = val; }
  int add_to_private(int val) { return var_private + val; }

  static std::string get_desc() { return "A sample class"; }
  static std::string foobar = "foobar";
};

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
      "__init__(self, value: Optional[Tuple[int, double]]=None) -> None";
  c.def(py::init([](py::tuple value) {
          auto ans = std::make_unique<sample_class>();
          if (value != nullptr) {
            ans->set_var_private(value[0]);
            ans->var_public = value[1];
          }
          return ans;
        }),
        init_doc, py::arg_v("value", nullptr).none(true));

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

  // add class member
  c.def_property_static("foobar", &sample_class::foobar, "A class member");
}
