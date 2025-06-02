"""
Program Name: Geometric Shapes
Lab #4: Text Analysis Program
Version: 1.0
Author: Matynkevich Evgeni
Date: 2025-05-20

This program creates geometric shapes with color, calculates their areas, and draws them using matplotlib.
"""

from abc import ABC, abstractmethod
import math
import matplotlib.pyplot as plt


class GeometricShape(ABC):
    """Abstract base class for geometric shapes with area calculation."""

    @abstractmethod
    def area(self):
        """Calculate the area of the shape. Must be implemented by subclasses."""
        pass


class Color:
    """Class representing color using RGB values (0-255 range)."""

    def __init__(self, red=0, green=0, blue=0):
        self._red = red
        self._green = green
        self._blue = blue

    @property
    def rgb(self):
        """Get RGB tuple representation of the color."""
        return (self._red, self._green, self._blue)

    @property
    def hex(self):
        """Get hexadecimal representation of the color."""
        return "#{:02x}{:02x}{:02x}".format(self._red, self._green, self._blue)


class Rhombus(GeometricShape):
    """Class representing a rhombus with side length 'a' and acute angle 'angle_deg'."""

    shape_name = "Rhombus"

    def __init__(self, side_a, angle_deg, color):
        if side_a <= 0:
            raise ValueError("Side length must be positive")
        if not (0 < angle_deg < 90):
            raise ValueError("Acute angle must be between 0 and 90 degrees")

        self.side_a = side_a
        self.angle_deg = angle_deg
        self.color = color

    @classmethod
    def get_shape_name(cls):
        """Return the name of the shape."""
        return cls.shape_name

    def area(self):
        """Calculate area using formula: a² * sin(θ)."""
        angle_rad = math.radians(self.angle_deg)
        return self.side_a ** 2 * math.sin(angle_rad)

    def get_parameters(self):
        """Return formatted string with shape parameters."""
        return ("{name} (side: {a:.2f}, angle: {angle}°, "
                "color: {color}, area: {area:.2f})").format(
            name=self.get_shape_name(),
            a=self.side_a,
            angle=self.angle_deg,
            color=self.color.hex,
            area=self.area()
        )

    def draw(self, label=""):
        """Draw rhombus using matplotlib and save to file."""
        angle_rad = math.radians(self.angle_deg)
        half_diag1 = self.side_a * math.cos(angle_rad / 2)
        half_diag2 = self.side_a * math.sin(angle_rad / 2)

        points = [
            (half_diag1, 0),
            (0, half_diag2),
            (-half_diag1, 0),
            (0, -half_diag2)
        ]

        fig, ax = plt.subplots()
        polygon = plt.Polygon(points, facecolor=self.color.hex, edgecolor='black')
        ax.add_patch(polygon)

        ax.set_xlim(-self.side_a * 1.2, self.side_a * 1.2)
        ax.set_ylim(-self.side_a * 1.2, self.side_a * 1.2)
        ax.set_aspect('equal')
        plt.title(label if label else self.get_shape_name())

        plt.savefig('rhombus.png')
        plt.show()


def validate_color(value):
    """Validate color input in RGB format (0-255 for each component)."""
    try:
        parts = list(map(int, value.split()))
        if len(parts) != 3 or any(p < 0 or p > 255 for p in parts):
            return None
        return parts
    except:
        return None


def main():
    rhombus = None

    while True:
        print("\nMenu:")
        print("1. Create Rhombus")
        print("2. Show Parameters")
        print("3. Draw Shape")
        print("4. Exit")
        choice = input("Enter choice: ").strip()

        if choice == '1':
            while True:
                try:
                    a = float(input("Enter side length (a > 0): "))
                    angle = float(input("Enter acute angle (0 < angle < 90): "))
                    color_input = input("Enter color as R G B (0-255 each): ")

                    color_components = validate_color(color_input)
                    if not color_components:
                        print("Invalid color format! Use three 0-255 values")
                        continue

                    rhombus = Rhombus(a, angle, Color(*color_components))
                    break
                except ValueError as e:
                    print(f"Error: {e}")

        elif choice == '2':
            if rhombus:
                print(rhombus.get_parameters())
            else:
                print("No rhombus created yet!")

        elif choice == '3':
            if rhombus:
                label = input("Enter label for the shape (optional): ")
                rhombus.draw(label)
                print("Saved as rhombus.png")
            else:
                print("Create a rhombus first!")

        elif choice == '4':
            print("Exiting program")
            break

        else:
            print("Invalid choice!")


if __name__ == "__main__":
    main()