#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool search(vector<int> &nums, int target)
{

    if (nums.size() == 0)
    {
        return false;
    }
    int left = 0;
    int right = nums.size() - 1;
    int middle = 0;

    while (left <= right)
    {
        middle = (left + right) >> 1;
        if (nums[middle] == target)
        {
            return true;
        }
        if (nums[left] == nums[middle] && nums[middle] == nums[right])
        {
            left++;
            right--;
        }
        else if (nums[left] <= nums[middle])
        {
            if (nums[left] <= target && target < nums[middle])
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        else
        {
            if (nums[middle] < target && target <= nums[right])
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    bool result = search(nums, target);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
