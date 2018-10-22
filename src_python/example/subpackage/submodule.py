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
        self._a = 0  # type: int
        self.b = 1.0  # type: float
        if value is not None:
            self._a = value[0]  # type: int
            self.b = value[1]  # type: float

    def add_to_private(self, val: int) -> int:
        """Add given value to private var and return result"""
        return self._a + val

    @classmethod
    def get_desc(cls) -> str:
        """get a description string"""
        return "A sample class"

    @property
    def a(self) -> int:
        return self._a

    @a.setter
    def a(self, val: int) -> None:
        self._a = val
