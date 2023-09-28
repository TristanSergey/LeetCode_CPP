// Для заданного целого числа n верните наименьшее количество совершенных квадратных чисел, сумма которых равна n.
// Полный квадрат — это целое число, являющееся квадратом целого числа; другими словами,
// это произведение некоторого целого числа на самого себя.Например, 1, 4, 9 и 16 — правильные квадраты, а 3 и 11 — нет.
// 279

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
#include <stack>
using namespace std;

int numSquares(int n)
{

    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    return dp[n];
}

int main()
{
    int n = 4;

    int result = numSquares(n);
    cout << "Количество уникальных путей: " << result << endl;
    return 0;
}