// Дан массив целых чисел nums, содержащий n + 1 целых чисел,
// где каждое целое число находится в диапазоне[1, n] включительно.
// В nums есть только одно повторяющееся число, верните
// это повторяющееся число.
// Вы должны решить проблему, не изменяя массив nums и
// используя только постоянное дополнительное пространство.
// 287

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

int findDuplicate(vector<int> &nums)
{

    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    int ptr1 = nums[0];
    int ptr2 = slow;

    while (ptr1 != ptr2)
    {
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }

    return ptr1;
}

int main()
{

    vector<int> nums = {1, 3, 4, 1, 7, 6, 2, 5};

    int result = findDuplicate(nums);

    std::cout << result << " ";

    std::cout << std::endl;
    return 0;
}
