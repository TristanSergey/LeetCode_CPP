// Учитывая непустой массив целых чисел nums,
// каждый элемент появляется дважды, кроме одного.
// Найти этот элемент.
// Вы должны реализовать решение с линейной сложностью
// времени выполнения и использовать только постоянное
// дополнительное пространство.
// 136

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
#include <stack>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int result = 0;
    for (int num : nums)
    {
        result ^= num;
    }
    return result;
}

int main()
{
    vector<int> nums = {2, 2, 1};
    int num = singleNumber(nums);

    cout << num << " ";

    return 0;
}