"""
EdgeVision Configuration Manager
"""

from pathlib import Path
import yaml


class Config:
    def __init__(self):
        self.project_root = Path(__file__).resolve().parent.parent

        settings_file = self.project_root / "settings.yaml"

        if not settings_file.exists():
            raise FileNotFoundError(f"{settings_file} not found")

        with open(settings_file, "r") as f:
            self.data = yaml.safe_load(f)

    @property
    def project(self):
        return self.data["project"]

    @property
    def camera(self):
        return self.data["camera"]

    @property
    def detector(self):
        return self.data["detector"]

    @property
    def recognizer(self):
        return self.data["recognizer"]

    @property
    def storage(self):
        return self.data["storage"]

    @property
    def display(self):
        return self.data["display"]


config = Config()
