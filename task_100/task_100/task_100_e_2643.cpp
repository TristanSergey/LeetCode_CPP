// Дана двоичная матрица размера m x n, найдите индексированную 0 позицию строки,
// которая содержит максимальное количество единиц, и количество единиц в этой строке.
// Если имеется несколько строк с максимальным количеством единиц, следует выбрать строку с наименьшим номером строки.
// Возвращает массив, содержащий индекс строки и количество единиц в ней.
// 2643
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    pair<int, int> result = make_pair(0, 0);
    int maxOnes = 0;
    for (int row = 0; row < mat.size(); row++)
    {
        int countNumber = 0;
        for (int col = 0; col < mat[row].size(); col++)
        {
            if (mat[row][col] & 1)
                countNumber++;
        }
        if (maxOnes < countNumber)
        {
            maxOnes = countNumber;
            result = make_pair(row, maxOnes);
        }
    }
    vector<int> finalResult = {result.first, result.second};
    return finalResult;
}

int main()
{
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 1}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1}};
    vector<int> result = rowAndMaximumOnes(mat);
    std::cout << "Индекс строки с максимальным количеством единиц: " << result[0] << std::endl;
    std::cout << "Количество единиц в этой строке: " << result[1] << std::endl;
    return 0;
}
