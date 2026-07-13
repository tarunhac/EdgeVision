"""
EdgeVision Detection Model
"""

from dataclasses import dataclass


@dataclass
class Detection:
    """
    Represents one tracked person.
    """

    x1: int
    y1: int
    x2: int
    y2: int

    confidence: float
    class_id: int

    track_id: int | None = None

    # Face Recognition
    name: str = "Unknown"
    similarity: float = 0.0