"""
Detection model.
"""

from dataclasses import dataclass


@dataclass(slots=True)
class Detection:
    """
    Represents a detected object.
    """

    x1: int
    y1: int
    x2: int
    y2: int

    confidence: float
    class_id: int