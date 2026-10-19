// Лабораторна робота № 5.4, варіант 27
#include <iostream>
#include <cmath>

using namespace std;

// 1) рекурсивний спуск, параметр спадає
double S1(const int K, const int N, const int i, double t)
{
    t = t + (1. * i * i) / (K * K + N * N);
    if (i <= K)
        return t;
    else
        return S1(K, N, i - 1, t);
}

// 2) рекурсивний спуск, параметр зростає
double S2(const int K, const int N, const int i, double t)
{
    t = t + (1. * i * i) / (K * K + N * N);
    if (i >= N)
        return t;
    else
        return S2(K, N, i + 1, t);
}

// 3) рекурсивний підйом, параметр спадає
double S3(const int K, const int N, const int i)
{
    if (i < K)
        return 0;
    else
        return (1. * i * i) / (K * K + N * N) + S3(K, N, i - 1);
}

// 4) рекурсивний підйом, параметр зростає
double S4(const int K, const int N, const int i)
{
    if (i > N)
        return 0;
    else
        return (1. * i * i) / (K * K + N * N) + S4(K, N, i + 1);
}

// 5) ітераційний спосіб (для контролю)
double S5(const int K, const int N)
{
    double s = 0;
    for (int i = K; i <= N; i++)
        s += (1. * i * i) / (K * K + N * N);
    return s;
}

int main()
{
    int K, N;
    cout << "K = "; cin >> K;
    cout << "N = "; cin >> N;

    cout << "(rec down --)  S1 = " << S1(K, N, N, 0) << endl;
    cout << "(rec down ++)  S2 = " << S2(K, N, K, 0) << endl;
    cout << "(rec up --)    S3 = " << S3(K, N, N) << endl;
    cout << "(rec up ++)    S4 = " << S4(K, N, K) << endl;
    cout << "(iter)         S5 = " << S5(K, N) << endl;

    return 0;
}