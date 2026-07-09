"""
EdgeVision Entry Point
"""

from src.surveillance import SurveillanceSystem


def main():

    system = SurveillanceSystem()

    system.run()


if __name__ == "__main__":
    main()