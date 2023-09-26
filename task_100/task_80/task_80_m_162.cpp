// Пиковый элемент — это элемент, который строго больше своих соседей.
// Учитывая 0 - индексированный целочисленный массив nums, найдите пиковый элемент и верните его индекс.
// Если массив содержит несколько пиков, верните индекс для любого из пиков.
// Вы можете себе представить, что nums[-1] = nums[n] = -∞. Другими словами, элемент всегда считается строго большим,
// чем соседний элемент, находящийся вне массива.
// Вы должны написать алгоритм, который работает за время O(log n).

// 162
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start < end)
    {
        int middle = (start + end) >> 1;
        if (nums[middle] < nums[middle + 1])
        {
            start = middle + 1;
        }
        else
        {
            end = middle;
        }
    }
    return start;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    int num = findPeakElement(nums);

    cout << num << " ";

    return 0;
}