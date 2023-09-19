// Вы поднимаетесь по лестнице.Требуется n шагов, чтобы добраться до вершины.
// Каждый раз вы можете подняться либо на 1, либо на 2 ступеньки.
// Сколькими различными способами вы можете подняться на вершину?
// 70
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
// #include <utility>
using namespace std;

int climbStairs(int n)
{

    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    int prev2 = 1;
    int prev1 = 2;
    int current = 0;

    for (int i = 3; i <= n; i++)
    {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
};

int main()
{
    int n = 8;
    int result = climbStairs(n);
    cout << "Количество способов - : " << result << endl;
    return 0;
}