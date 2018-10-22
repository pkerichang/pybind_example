#!/usr/bin/env bash
# this script generates .pyi interface files for Pycharm using mypy

export PYTHONPATH="build/lib.linux-x86_64-3.7"
python -m mypy.stubgen --recursive -o stubs_old example
python -m mypy.stubgen --recursive -o stubs_old example.subpackage
python -m mypy.stubgen --recursive -o stubs_old example.subpackage.submodule
