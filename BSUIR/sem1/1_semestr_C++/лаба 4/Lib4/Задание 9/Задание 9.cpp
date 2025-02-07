#include <iostream>

int main()
{
    unsigned int n;
    std::cin >> n;

    unsigned int*** a = (unsigned int***)malloc(n * sizeof(unsigned int**));
    for (int i = 0; i < n; i++) {
        a[i] = (unsigned int**)malloc(n * sizeof(unsigned int*));
        for (int j = 0; j < n; j++) {
            a[i][j] = (unsigned int*)malloc(n * sizeof(unsigned int));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                std::cin >> a[i][j][k];
            }
        }
    }
    
    int* sum = (int*)calloc(16, sizeof(int));

    //0
    for (int i = 0; i < n; i++) {
        sum[0] += a[i][i][i];
        sum[1] += a[n - 1 - i][i][i];
        sum[2] += a[i][n - 1 - i][i];
        sum[3] += a[i][i][n - 1 - i];
    }
   

    int max = sum[0], ind = 0;
    for (int i = 1; i < 16; i++) {
        if (max < sum[i]) {
            max = sum[i];
            ind = i;
        }
    }

    std::cout << "Number of diagonal= " << ind;

//очистка
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            free(a[i][j]);
        }
        free(a[i]);
        a[i] = nullptr;
    }
    free(a);
    a = nullptr;

    free(sum);
    sum = nullptr;

    return 0;
}
