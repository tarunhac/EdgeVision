from pathlib import Path


from pathlib import Path


def find_project_root():
    current = Path(__file__).resolve()

    while current != current.parent:

        # Repository root
        if (
            (current / "ros2").exists()
            and
            (current / ".git").exists()
        ):
            return current

        current = current.parent

    raise RuntimeError("Could not locate project root.")

PROJECT_ROOT = find_project_root()

KNOWN_FACES_DIR = PROJECT_ROOT / "known_faces"

UNKNOWN_FACES_DIR = PROJECT_ROOT / "unknown_faces"

MODELS_DIR = PROJECT_ROOT / "models"

LOGS_DIR = PROJECT_ROOT / "logs"

DATABASE_DIR = LOGS_DIR

DATABASE_PATH = DATABASE_DIR / "events.db"