# Stubs for example.subpackage.submodule (Python 3.7)
#
# NOTE: This dynamically typed stub was automatically generated by stubgen.

from typing import Optional, Tuple

answer: int

def add(a: int, b: int=...) -> int: ...

class SampleClass:
    foobar: str = ...
    var_public: float = ...
    def __init__(self, value: Optional[Tuple[int, float]]=...) -> None: ...
    def add_to_private(self, val: int) -> int: ...
    @classmethod
    def get_desc(cls: Any) -> str: ...
    @property
    def var_private(self) -> int: ...
    @var_private.setter
    def var_private(self, val: int) -> None: ...
