// Числа Фибоначчи, обычно обозначаемые F(n), образуют последовательность,
// называемую последовательностью Фибоначчи, так что каждое число является
// суммой двух предыдущих, начиная с 0 и 1. То есть,
// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), для n > 1.
// Учитывая n, вычислить F(n).
// 509 + GFG
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;
const int MOD = 1000000007;
int nthFibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int prev = 0;
    int current = 1;

    for (int i = 2; i <= n; ++i)
    {
        int next = (prev + current) % MOD;
        prev = current;
        current = next;
    }

    return current;
    // if (n <= 1)
    // {
    //     return n;
    // }
    // long long int prev = 0;
    // long long int current = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     long long int newFib = current + prev % 1000000007;
    //     prev = current;
    //     current = newFib;
    // }

    // return current;
}

int main()
{

    int n = 14521;

    int result = nthFibonacci(n);
    // int result = lengthOfLIS(nums);
    std::cout << "Фибоначчи : " << result << std::endl;
    return 0;
}
