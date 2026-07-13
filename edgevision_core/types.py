"""
Shared data types for EdgeVision.
"""

from dataclasses import dataclass


@dataclass(slots=True)
class Detection:
    """
    Represents one detected person.
    """

    x1: int
    y1: int
    x2: int
    y2: int

    confidence: float
    class_id: int