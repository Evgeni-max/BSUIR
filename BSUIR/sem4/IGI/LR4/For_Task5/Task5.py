"""
Program for working with NumPy arrays
Lab #4: Text Analysis Program
Version: 1.0
Author: Matynkevich Evgeni
Date: 2025-05-20
"""

import numpy as np

def manual_median(arr):
    """Manual median calculation via sorting"""
    sorted_arr = np.sort(arr)
    n = len(sorted_arr)
    if n == 0:
        return None
    if n % 2 == 1:
        return sorted_arr[n//2]
    else:
        return (sorted_arr[n//2 - 1] + sorted_arr[n//2]) / 2

def main():
    while True:
        try:
            n = int(input("Enter number of rows n: "))
            m = int(input("Enter number of columns m: "))
            if n <= 0 or m <= 0:
                raise ValueError
            break
        except ValueError:
            print("Error! Please enter positive integers")

    A = np.random.randint(-100, 101, size=(n, m))
    print("\nGenerated matrix A:")
    print(A)

    while True:
        try:
            B = float(input("\nEnter threshold B: "))
            break
        except ValueError:
            print("Error! Please enter numeric value")

    C = A[np.abs(A) > B]
    count = C.size
    print(f"\nNumber of elements > |{B}|: {count}")

    if count == 0:
        print("No elements to calculate median")
        return

    print("\nArray C:")
    print(C)

    np_median = np.median(C)
    custom_median = manual_median(C)

    print(f"\nMedian (NumPy): {np_median:.2f}")
    print(f"Median (manual): {custom_median:.2f}")

if __name__ == "__main__":
    main()