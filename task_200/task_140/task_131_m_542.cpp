// Учитывая бинарную матрицу m x n, верните расстояние до ближайшего 0 для каждой ячейки.
// Расстояние между двумя соседними ячейками равно 1.
// 542
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
#include <queue>
using namespace std;



vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int rows = mat.size();
    int cols = mat[0].size();
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<pair<int, int>> q;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({i, j});
            }
            else
            {
                mat[i][j] = INT_MAX;
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> cell = q.front();
        q.pop();
        int row = cell.first;
        int col = cell.second;

        for (pair<int, int> direction : directions)
        {
            int newRow = row + direction.first;
            int newCol = col + direction.second;

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && mat[newRow][newCol] > mat[row][col] + 1)
            {
                mat[newRow][newCol] = mat[row][col] + 1;
                q.push({newRow, newCol});
            }
        }
    }

    return mat;
}

int main()
{
    // int n = 5;
    vector<vector<int>> nums = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    // vector<int> nums = {[0, 0, 0], [ 0, 1, 0 ], [ 1, 1, 1 ] ]};

    vector<vector<int>> result = updateMatrix(nums);

    for (const std::vector<int> &row : result)
    {
        for (int num : row)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}