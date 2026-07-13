"""
EdgeVision Entry Point
"""

from edgevision_core.surveillance import SurveillanceSystem


def main():

    system = SurveillanceSystem()

    system.run()


if __name__ == "__main__":
    main()