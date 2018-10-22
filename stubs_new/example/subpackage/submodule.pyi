# Stubs for example.subpackage.submodule (Python 3.7)
#
# NOTE: This dynamically typed stub was automatically generated by stubgen.

from typing import Any

answer: int

def add(a: int, b: int=3): ...

class SampleClass(pybind11_object):
    foobar: Any = ...
    var_private: Any = ...
    var_public: Any = ...
    def __init__(self, value: Optional[Tuple[int, double]]=None): ...
    def add_to_private(self, val: int): ...
    @classmethod
    def get_desc(cls): ...
