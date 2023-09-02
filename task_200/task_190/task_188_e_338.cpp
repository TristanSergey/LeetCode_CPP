// Учитывая целое число n, верните массив ans длины n + 1 такой,
// что для каждого i(0 <= i <= n) ans[i] — это количество единиц в двоичном представлении i.
// 338

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

vector<int> countBits(int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp;
}

int main()
{
    int n = 5;
    std::vector<int> result = countBits(n);

    for (int num : result)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}