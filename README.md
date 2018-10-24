# pybind11_example
An simple example of a python C++ extension built with pybind11 show-casing all the features

the `src_cpp` folder contains a Python C++ extension built with pybind11, the `src_python`
folder contains the equivalent pure-python version.


## Building with CMake

To build this example with CMake, simple install CMake, then run:
```
python setup_cmake.py build
```

## Building without CMake

To build this example without CMake, run:
```
python setup.py build
```

## Generating Python Interface Files

One purpose of this repo is to test `mypy`'s capability in generating Python interface
files for C extension modules.

To generate Python interface files, `mypy` must be searchable by Python, either via
installation or adding to `PYTHONPATH` variable.

Run the script `gen_stubs_golden.sh` to create .pyi files in the `stubs_golden` folder for
the Python version of the package.

Run the script `gen_stubs_old.sh` or `gen_stubs_new.sh` to create .pyi files in the
`stubs_old` or `stubs_new` folder for the C++ version.  `gen_stubs_old.sh` should be
used if `mypy`'s stub generation script fails to recursive walk the package hierarchy.
