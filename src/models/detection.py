from dataclasses import dataclass


@dataclass(slots=True)
class Detection:

    x1: int
    y1: int
    x2: int
    y2: int

    confidence: float

    class_id: int

    track_id: int | None = None