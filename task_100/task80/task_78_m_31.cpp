#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int index = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(nums.begin(), nums.end());
        // return nums;
    }
    else
    {
        for (int i = n - 1; i > index; i--)
        {
            if (nums[i] > nums[index])
            {
                break;
            }
            swap(nums[i], nums[index]);
            reverse(nums.begin() + index + 1, nums.end());
        }
    }
    // return nums;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }

    return 0;
}