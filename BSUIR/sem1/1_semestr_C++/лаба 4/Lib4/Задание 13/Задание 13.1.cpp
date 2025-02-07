#include <iostream>



long long abc(int i, int j, long long n) {
    return i * n + 1 + j;
}

int main()
{
    long long n;
    std::cout << "Enter the size of square: ";
    std::cin >> n;
    if (n % 2) {//////////////////////////////////////////////////////////////////////////////////////

        long long** a;
        a = (long long**)calloc(n, sizeof(long long*));
        for (int i = 0; i < n; i++) {
            a[i] = (long long*)calloc(n, sizeof(long long));
        }


        long long n2 = n * n + 1;
        long long x = 0, y = (n - 1) / 2, x1, y1;
        for (int i = 1; i < n2; i++) {
            a[x][y] = i;
            x1 = (x - 1 + n) % n;
            y1 = (y + 1 + n) % n;
            if (a[x1][y1] != 0) {
                x = (x + 1) % n;
            }
            else {
                x = x1;
                y = y1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << a[i][j] << '\t';
            }
            std::cout << std::endl;
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                sum += a[i][j];
            }
            std::cout << sum << ' ';
        }
        std::cout << std::endl;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                sum += a[j][i];
            }
            std::cout << sum << ' ';
        }
        std::cout << '\n' << '\n' << (n * n + 1) * n / 2;


        for (int i = 0; i < n; i++) {
            free(a[i]);
            a[i] = nullptr;
        }
        free(a);
        a = nullptr;
        
    }///////////////////////////////////////////////////////////////////////////////
    else if (n % 4) {
        long long** a;
        a = (long long**)calloc(n, sizeof(long long*));
        for (int i = 0; i < n; i++) {
            a[i] = (long long*)calloc(n, sizeof(long long));
        }


        long long n2 = n * n / 4 + 1, n12 = n / 2, n02 = n12 * n12;
        long long x = 0, y = (n12 - 1) / 2, x1, y1;
        for (int i = 1; i < n2; i++) {
            a[x + n12][y] = i + 3 * n02;
            a[x][y + n12] = i + 2 * n02;
            a[x][y] = i;
            a[x + n12][y + n12] = i + n02;
            x1 = (x - 1 + n12) % n12;
            y1 = (y + 1 + n12) % n12;
            if (a[x1][y1] != 0) {
                x = (x + 1) % n12;
            }
            else {
                x = x1;
                y = y1;
            }
        }



        long long m = (n - 6) / 4, l = m + 1;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < n12; j++) {
                a[j][i] = a[j][i] ^ a[j + n12][i];
                a[j + n12][i] = a[j][i] ^ a[j + n12][i];
                a[j][i] = a[j][i] ^ a[j + n12][i];
            }
        }

        long kk = n12 / 2, jj = kk + n12;
        a[kk][0] = a[kk][0] ^ a[jj][0];
        a[jj][0] = a[kk][0] ^ a[jj][0];
        a[kk][0] = a[kk][0] ^ a[jj][0];
    
        a[kk][l] = a[kk][l] ^ a[jj][l];
        a[jj][l] = a[kk][l] ^ a[jj][l];
        a[kk][l] = a[kk][l] ^ a[jj][l];




        long long nm = n - 1 - m;
        for (int i = n - 1; i > nm; i--) {
            for (int j = 0; j < n12; j++) {
                a[j][i] = a[j][i] ^ a[j + n12][i];
                a[j + n12][i] = a[j][i] ^ a[j + n12][i];
                a[j][i] = a[j][i] ^ a[j + n12][i];
            }
        }



        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << a[i][j] << '\t';
            }
            std::cout << std::endl;
        }

        for (int i = 0; i < n; i++) {
            free(a[i]);
            a[i] = nullptr;
        }
        free(a);
        a = nullptr;
    }//////////////////////////////////////////////////////////////////////////////
    else {
        long long** a;
        a = (long long**)calloc(n, sizeof(long long*));
        for (int i = 0; i < n; i++) {
            a[i] = (long long*)calloc(n, sizeof(long long));
        }


        //ugli
        int n4 = n / 4, n2 = n / 2;
        for (int i = 0; i < n4; i++) {
            for (int j = 0; j < n4; j++) {
                a[i][j] = abc(i, j, n);
                a[n - 1 - i][j] = abc(n - 1 - i, j, n);
                a[i][n - 1 - j] = abc(i, n - 1 - j, n);
                a[n - 1 - i][n - 1 - j] = abc(n - 1 - i, n - 1 - j, n);
            }
        }


        //vertical 
        long long n41 = n - n4, n22 = n * n, n34 = n / 4 * 3, n234 = n * n34;
        for (int i = n4; i < n - n4; i++) {
            a[0][i] = n22 - i;
            a[n34][i] = a[0][i] - n234;
            for (int j = 1; j < n4; j++) {
                a[j][i] = a[0][i] - n * j;
                a[j + n34][i] = a[j][i] - n234;
            }
        }


        //centre
        for (int i = n4; i < n41; i++) {
            for (int j = n4; j < n41; j++) {
                a[i][j] = abc(i, j, n);
            }

        }

        //gorizontal
        for (int i = 0; i < n4; i++) {
            a[n4][i] = n234 - i;
            a[n4][n34 + i] = a[n4][i] - n34;
        }

        for (int j = 1; j < n2; j++) {
            for (int i = 0; i < n4; i++) {
                a[n4 + j][i] = a[n4][i] - n * j;
                a[n4 + j][n34 + i] = a[n4][n34 + i] - n * j;
            }
        }

        //vivod
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << a[i][j] << '\t';
            }
            std::cout << std::endl;
        }

        for (int i = 0; i < n; i++) {
            free(a[i]);
            a[i] = nullptr;
        }
        free(a);
        a = nullptr;
    }
    return 0;
}
