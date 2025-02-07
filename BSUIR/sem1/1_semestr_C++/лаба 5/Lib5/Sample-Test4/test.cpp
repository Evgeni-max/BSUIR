#include "pch.h"
#include <gtest/gtest.h>

int find_0(int** a, int n, int k) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (a[i][j] == 0) {
				count++;
				//std::cout << '(' << i << ',' << j << ')';
			}
		}
	}
	return count;
}

TEST(Test__of_result_1_in_3) {
    int** x = new int* [4];
    for (int i = 0; i < 4; i++) {
        x[i] = new int[4];
        x[i][0] = i + 5;
        x[i][1] = i;
        x[i][2] = i * 3;
        x[i][3] = i - 7;
    }

    ASSERT_EQ(find_0(x, 4, 4), 0);

    // Освобождение памяти
    for (int i = 0; i < 4; i++) {
        delete[] x[i];
    }
    delete[] x;
}

TEST(Test__of_result_2_in_3) {
    int** x = new int* [4];
    for (int i = 0; i < 4; i++) {
        x[i] = new int[4];
        x[i][0] = i + 4;
        x[i][1] = i / 4;
        x[i][2] = i % 3;
        x[i][3] = 0;
    }

    ASSERT_EQ(find_0(x, 4, 4), 7);

    // Освобождение памяти
    for (int i = 0; i < 4; i++) {
        delete[] x[i];
    }
    delete[] x;
}

TEST(Test__of_result_3_in_3)
{
    int** x = new int* [4];
    for (int i = 0; i < 4; i++) {
        x[i] = new int[4];
        x[i][0] = i;
        x[i][1] = i + 1;
        x[i][2] = i - 1;
        x[i][3] = i + 2;
    }

    ASSERT_EQ(find_0(x, 4, 4), 678);

    // Освобождение памяти
    for (int i = 0; i < 4; i++) {
        delete[] x[i];
    }
    delete[] x;
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}