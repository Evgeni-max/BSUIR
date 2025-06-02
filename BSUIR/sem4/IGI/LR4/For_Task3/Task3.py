"""
Lab #4: Text Analysis Program
Version: 1.0
Author: Matynkevich Evgeni
Date: 2025-05-20

This program calculates the series expansion of ln((x+1)/(x-1)) for |x|>1, computes statistical parameters of the series terms, and plots the comparison between the series approximation and the exact math function.
"""

import math
import pickle
import numpy as np
import matplotlib.pyplot as plt
from abc import ABC, abstractmethod


class StatisticsMixin:
    """
    A mixin class providing statistical calculations for a list of numerical terms.
    The host class must have a 'terms' attribute, which is a list of numbers.
    """

    def mean(self):
        """Calculate the mean (average) of the terms."""
        if not self.terms:
            return 0.0
        return sum(self.terms) / len(self.terms)

    def median(self):
        """Calculate the median of the terms."""
        if not self.terms:
            return 0.0
        sorted_terms = sorted(self.terms)
        n = len(sorted_terms)
        mid = n // 2
        if n % 2 == 1:
            return sorted_terms[mid]
        else:
            return (sorted_terms[mid - 1] + sorted_terms[mid]) / 2

    def mode(self):
        """Calculate the mode of the terms. Returns None if no mode exists."""
        if not self.terms:
            return None
        counts = {}
        for term in self.terms:
            counts[term] = counts.get(term, 0) + 1
        max_count = max(counts.values())
        if max_count == 1:
            return None
        modes = [k for k, v in counts.items() if v == max_count]
        return modes if len(modes) > 1 else modes[0]

    def variance(self):
        """Calculate the variance of the terms."""
        if not self.terms:
            return 0.0
        mu = self.mean()
        return sum((x - mu) ** 2 for x in self.terms) / len(self.terms)

    def std_dev(self):
        """Calculate the standard deviation of the terms."""
        return math.sqrt(self.variance())


class SeriesCalculator(ABC):
    """Abstract base class for series calculators."""

    @abstractmethod
    def compute_series(self):
        pass


class LnSeriesCalculator(SeriesCalculator, StatisticsMixin):
    """
    Computes the series expansion of ln((x+1)/(x-1)) and provides statistical analysis of the terms.

    Attributes:
        x (float): Input value where |x| > 1.
        epsilon (float): Convergence threshold for the series terms.
        terms (list[float]): List of computed terms.
        sum_series (float): Sum of the terms up to convergence.
        n_terms (int): Number of terms computed.
        math_value (float): Exact value from math.log((x+1)/(x-1)).
    """

    _count = 0  # Static attribute to count instances

    def __init__(self, x, epsilon):
        """Initialize with x and epsilon, and compute the series."""
        if abs(x) <= 1:
            raise ValueError("x must satisfy |x| > 1")
        self._x = x
        self._epsilon = epsilon
        self.terms = []
        self.sum_series = 0.0
        self.n_terms = 0
        self.math_value = math.log((x + 1) / (x - 1))
        self.compute_series()
        LnSeriesCalculator._count += 1

    def __str__(self):
        """String representation of the instance."""
        return f"LnSeriesCalculator(x={self.x}, epsilon={self.epsilon}, terms={len(self.terms)})"

    @property
    def x(self):
        """Get the current x value."""
        return self._x

    @x.setter
    def x(self, value):
        """Set x and recompute the series and math value."""
        if abs(value) <= 1:
            raise ValueError("x must satisfy |x| > 1")
        self._x = value
        self.math_value = math.log((value + 1) / (value - 1))
        self.compute_series()

    @property
    def epsilon(self):
        """Get the current epsilon value."""
        return self._epsilon

    @epsilon.setter
    def epsilon(self, value):
        """Set epsilon and recompute the series."""
        if value <= 0:
            raise ValueError("epsilon must be positive")
        self._epsilon = value
        self.compute_series()

    def compute_series(self):
        """Compute the series terms until the term's absolute value is below epsilon."""
        self.terms = []
        self.sum_series = 0.0
        n = 0
        while True:
            term = 2 / ((2 * n + 1) * (self.x ** (2 * n + 1)))
            if abs(term) < self._epsilon or n >= 1000:
                break
            self.terms.append(term)
            self.sum_series += term
            n += 1
        self.n_terms = n

    def get_stats(self):
        """Get a dictionary of statistical measures for the terms."""
        return {
            'mean': self.mean(),
            'median': self.median(),
            'mode': self.mode(),
            'variance': self.variance(),
            'std_dev': self.std_dev()
        }

    def save(self, filename):
        """Save the instance to a file using pickle."""
        with open(filename, 'wb') as f:
            pickle.dump(self, f)

    @classmethod
    def load(cls, filename):
        """Load an instance from a file."""
        with open(filename, 'rb') as f:
            return pickle.load(f)


def main():
    current_calculator = None

    while True:
        print("\nMenu:")
        print("1. Compute series for x and epsilon")
        print("2. Show statistics for last computed series")
        print("3. Plot comparison between series and math function")
        print("4. Save current series to file")
        print("5. Load series from file")
        print("6. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            while True:
                try:
                    x = float(input("Enter x (|x| > 1): "))
                    if abs(x) <= 1:
                        print("x must be greater than 1 or less than -1")
                        continue
                    epsilon = float(input("Enter epsilon (positive): "))
                    if epsilon <= 0:
                        print("Epsilon must be positive.")
                        continue
                    current_calculator = LnSeriesCalculator(x, epsilon)
                    print("\nResults:")
                    print(f"x: {x}")
                    print(f"Epsilon: {epsilon}")
                    print(f"Number of terms: {current_calculator.n_terms}")
                    print(f"Series sum: {current_calculator.sum_series}")
                    print(f"Math value: {current_calculator.math_value}")
                    break
                except ValueError as e:
                    print(f"Invalid input: {e}")

        elif choice == '2':
            if current_calculator is None:
                print("No series computed yet. Please choose option 1 first.")
            else:
                stats = current_calculator.get_stats()
                print("\nStatistics of terms:")
                print(f"Mean: {stats['mean']}")
                print(f"Median: {stats['median']}")
                mode = stats['mode']
                if mode is None:
                    print("Mode: No mode found")
                elif isinstance(mode, list):
                    print(f"Mode: {', '.join(map(str, mode))}")
                else:
                    print(f"Mode: {mode}")
                print(f"Variance: {stats['variance']}")
                print(f"Standard Deviation: {stats['std_dev']}")

        elif choice == '3':
            try:
                x_start = float(input("Enter start x (>1): "))
                if x_start <= 1:
                    print("x must be greater than 1")
                    continue
                x_end = float(input("Enter end x (> start x): "))
                if x_end <= x_start:
                    print("End x must be greater than start x.")
                    continue
                epsilon = float(input("Enter epsilon for computation: "))
                if epsilon <= 0:
                    print("Epsilon must be positive.")
                    continue

                x_values = np.linspace(x_start, x_end, 100)
                series_values = []
                math_values = []
                for x in x_values:
                    try:
                        calc = LnSeriesCalculator(x, epsilon)
                        series_values.append(calc.sum_series)
                        math_values.append(calc.math_value)
                    except ValueError:
                        continue

                plt.figure()
                plt.plot(x_values, series_values, 'b-', label='Series Approximation')
                plt.plot(x_values, math_values, 'r--', label='Math Function')
                plt.xlabel('x')
                plt.ylabel('F(x)')
                plt.title('Comparison of Series Approximation and Math Function')
                plt.legend()
                plt.grid(True)
                plt.annotate(f'epsilon={epsilon}', xy=(0.05, 0.05), xycoords='axes fraction')
                plt.savefig('comparison_plot.png')
                plt.show()
                print("Plot saved as comparison_plot.png")

            except Exception as e:
                print(f"An error occurred: {e}")

        elif choice == '4':
            if current_calculator is None:
                print("No series to save.")
            else:
                filename = input("Enter filename to save: ")
                current_calculator.save(filename)
                print(f"Saved to {filename}")

        elif choice == '5':
            filename = input("Enter filename to load: ")
            try:
                current_calculator = LnSeriesCalculator.load(filename)
                print("Loaded successfully.")
                print(f"x: {current_calculator.x}")
                print(f"epsilon: {current_calculator.epsilon}")
                #print(f"terms: {current_calculator.terms}")
                #print(f"sum_series: {current_calculator.sum_series}")
            except Exception as e:
                print(f"Error loading: {e}")

        elif choice == '6':
            print("Exiting program.")
            break

        else:
            print("Invalid choice. Please enter a number between 1 and 6.")


if __name__ == "__main__":
    main()