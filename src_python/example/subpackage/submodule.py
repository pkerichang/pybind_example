"""This is a Python module."""

from typing import Optional, Tuple


answer = 42


def add(a: int, b: int=3) -> int:
    return a + b


class SampleClass:
    """A sample class.

    Parameters
    ----------
    value : Optional[Tuple[int, double]]
        set the class variables to the given tuple.
    """
    foobar = "foobar"  # type: str

    def __init__(self, value: Optional[Tuple[int, float]]=None) -> None:
        """__init__(self, value: Optional[Tuple[int, float]]=None) -> None"""
        self._var_private = 0  # type: int
        self.var_public = 1.0  # type: float
        if value is not None:
            self._var_private = value[0]  # type: int
            self.var_public = value[1]  # type: float

    def add_to_private(self, val: int) -> int:
        """Add given value to private var and return result"""
        return self._var_private + val

    @classmethod
    def get_desc(cls) -> str:
        """get a description string"""
        return "A sample class"

    @property
    def var_private(self) -> int:
        return self._var_private

    @var_private.setter
    def var_private(self, val: int) -> None:
        self._var_private = val
