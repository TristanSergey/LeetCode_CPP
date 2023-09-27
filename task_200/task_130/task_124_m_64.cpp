// Учитывая сетку m x n, заполненную неотрицательными числами,
// найдите путь из верхнего левого угла в нижний правый,
// который минимизирует сумму всех чисел на своем пути.
// Примечание.В любой момент времени вы можете двигаться только вниз или вправо.
// 64

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
#include <stack>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid[0].size();
    int n = grid.size();

    for (int i = 1; i < m; i++)
    {
        grid[0][i] = grid[0][i] + grid[0][i - 1];
    }

    for (int i = 1; i < n; i++)
    {
        grid[i][0] = grid[i][0] + grid[i - 1][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }

    return grid[n - 1][m - 1];
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    int result = minPathSum(grid);
    cout << "Количество уникальных путей: " << result << endl;
    return 0;
}