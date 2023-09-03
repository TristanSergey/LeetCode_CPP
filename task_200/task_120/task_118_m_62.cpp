// На сетке m x n стоит робот.Робот изначально расположен в верхнем левом углу(т.е.grid[0][0]).
// Робот пытается переместиться в нижний правый угол(т.е.grid[m - 1][n - 1]).
// Робот может двигаться только вниз или вправо в любой момент времени.
// Имея два целых числа m и n, верните количество возможных уникальных путей,
// по которым робот может добраться до правого нижнего угла.
// Тестовые случаи генерируются таким образом, чтобы ответ был меньше или равен 2 * 109.
// 62

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)

        {

            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
};

int main()
{
    int m = 3;
    int n = 7;
    int result = uniquePaths(m, n);
    cout << "Количество уникальных путей: " << result << endl;
    return 0;
}