#include <math.h>
#include <iostream>

void roots(long double t) {
    long double D = t * t - 4;
    switch (D >= 0 ? D == 0 ? 0 : 1 : -1) {
    case -1:
        std::cout << "No roots";
        break;
    case 0:
        std::cout << t / 2;
        break;
    case 1:
        D = sqrt(D);
        std::cout << (t - D) / 2 << ' ' << (t + D) / 2;
        break;
    }
}

int main()
{ 
    int N;
    std::cin >> N;

    if (N == 1) {
        long double a, b, c, D, dis11, dis12, dis0;
        int sol1, sol2;
        std::cin >> a >> b >> c;

        D = b * b - 4 * a * c;
        if (D < 0) std::cout << "No roots";
        else if (D == 0) {
            dis0 = -b / 2 / a;
            if (dis0 < 0) std::cout << "No roots";
            else if (dis0 == 0) std::cout << 0;
            else {
                dis0 = sqrt(dis0);
                std::cout << -dis0 << ' ' << dis0;
            }
        }
        else {
            dis11 = (-b + sqrt(D)) / 2 / a;
            dis12 = (-b - sqrt(D)) / 2 / a;
            
            sol1 = dis11 >= 0 ? dis11 == 0 ? 0 : 1 : -1;
            sol2 = dis12 >= 0 ? dis12 == 0 ? 0 : 1 : -1;

            switch (sol1) {
            case -1:
                if (sol2 == -1) std::cout << "No roots";
                else if (sol2 == 0) {
                    std::cout << 0;
                }
                else {
                    dis12 = sqrt(dis12);
                    std::cout << -dis12 << ' ' << dis12;
                }
                break;
            case 0: 
                std::cout << 0 << ' ';
                if (sol2 == 1) {
                    dis12 = sqrt(dis12);
                    std::cout << -dis12 << ' ' << dis12;
                }
                break;
            case 1: 
                dis11 = sqrt(dis11);
                std::cout << -dis11 << ' ' << dis11 << ' ';

                if (sol2 == 0) {
                    std::cout << 0;
                }
                else if (sol2 == 1) {
                    dis12 = sqrt(dis12);
                    std::cout << -dis12 << ' ' << dis12;
                }
                break;
            }
        }
    }
    else if (N == 2) {
        long double a, b, c, t, t1, t2, D1, D2, sw1, sw2, B;
        std::cin >> a >> b >> c;

        if (a == 0) {
            std::cout << 0;

            B = c / b;

            long double D = B * B - 4;

            switch (D >= 0 ? D == 0 ? 0 : 1 : -1) {
            case 0:
                std::cout << B / 2;
                break;
            case 1:
                D = sqrt(D);
                std::cout << (-B - D) / 2 << ' ' << (-B + D) / 2;
                break;
            }
        }
        else {
            long double Ds = b * b - 4 * a * (c - 2 * a);

            switch (Ds >= 0 ? Ds == 0 ? 0 : 1 : -1) {
            case -1:
                std::cout << "No roots";
                break;
            case 0:
                t = -b / 2 / a;
                roots(t);
                break;
            case 1:
                Ds = sqrt(Ds);

                t1 = (-b - Ds) / 2 / a;
                t2 = (-b + Ds) / 2 / a;

                D1 = t1 * t1 - 4;
                sw1 = D1 >= 0 ? D1 == 0 ? 0 : 1 : -1;

                D2 = t2 * t2 - 4;
                sw2 = D2 >= 0 ? D2 == 0 ? 0 : 1 : -1;

                if (sw1 == -1) {
                    if (sw2 == -1) std::cout << "No roots";
                    else if (sw2 == 0) std::cout << t2 / 2;
                    else {
                        D2 = sqrt(D2);
                        std::cout << (t2 - D2) / 2 << ' ' << (t2 + D2) / 2;
                    }
                }
                else if (sw1 == 0) {
                    if (sw2 == -1 || sw2 == 0) std::cout << 1;
                    else {
                        D2 = sqrt(D2);
                        std::cout << (t2 - D2) / 2 << ' ' << (t2 + D2) / 2;
                    }
                }
                else {
                    D1 = sqrt(D1);
                    std::cout << (t1 - D1) / 2 << ' ' << (t1 + D1) / 2;

                    if (sw2 == 0) std::cout << 1;
                    else if (sw2 == 1) {
                        D2 = sqrt(D2);
                        std::cout << (t2 - D2) / 2 << ' ' << (t2 + D2) / 2;
                    }
                }
                break;
            }
        }
    } 
    else {
        long double p, q, Q, R, s, fi, x1, x2, x3;
        std::cin >> p >> q;

        Q = -p / 3;
        R = q / 2;
        s = Q * Q * Q - R * R;

        int sw = s >= 0 ? s = 0 ? 0 : 1 : -1;

        switch (sw) {
        case 1:
            fi = (acos(R / pow(Q, 1.5))) / 3;
            x1 = -2 * sqrt(Q) * cos(fi);
            x2 = -2 * sqrt(Q) * cos(fi + atan(1) * 8 / 3);
            x3 = -2 * sqrt(Q) * cos(fi - atan(1) * 8 / 3);
            std::cout << x1 << ' ' << x2 << ' ' << x3;
            break;
        case 0:
            x1 = -2 * pow(R, 1 / 3);
            x2 = pow(R, 1 / 3); 
            std::cout << x1 << ' ' << x2;
            break;
        case - 1:
            std::cout << pow(-R + sqrt(-s), 1.0 / 3) - pow(R + sqrt(-s), 1.0 / 3);
            break;
        }
    } 
    return 0;
}

