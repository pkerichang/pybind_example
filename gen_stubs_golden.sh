#!/usr/bin/env bash
# this script generates .pyi interface files for Pycharm using mypy

export PYTHONPATH="src_python"
python -m mypy.stubgen --recursive -o stubs_golden example
