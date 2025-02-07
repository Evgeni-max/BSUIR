#include "pch.h"
#include <gtest/gtest.h>

int result(int** x, int** b, int n, int k) {
    int end = 0;
    for (int i = 0; i < k; i += 2) {
        for (int j = 0; j < n; j++) {
            if (x[j][i] % 2) {
                b[0][end] = x[j][i];
                end++;
            }
        }

    }

    return end;
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
    int** b = new int* [1];
    b[0] = new int[16] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    ASSERT_EQ(result(x, b, 4, 4), 4);

    // Освобождение памяти
    for (int i = 0; i < 4; i++) {
        delete[] x[i];
    }
    delete[] x;

    delete[] b[0];
    delete[] b;
}

TEST(Test__of_result_2_in_3) {
    int** x = new int* [4];
    for (int i = 0; i < 4; i++) {
        x[i] = new int[4];
        x[i][0] = i + 4;
        x[i][1] = i / 4;
        x[i][2] = i % 3;
        x[i][3] = i * i;
    }
    int** b = new int* [1];
    b[0] = new int[16] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    ASSERT_EQ(result(x, b, 4, 4), 3);

    // Освобождение памяти
    for (int i = 0; i < 4; i++) {
        delete[] x[i];
    }
    delete[] x;

    delete[] b[0];
    delete[] b;
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
    int** b = new int* [1];
    b[0] = new int[16] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    ASSERT_EQ(result(x, b, 4, 4), 4);

    // Освобождение памяти
    for (int i = 0; i < 4; i++) {
        delete[] x[i];
    }
    delete[] x;

    delete[] b[0];
    delete[] b;
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}