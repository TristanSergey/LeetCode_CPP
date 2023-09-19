#include <iostream>
#include <vector>
#include <algorithm>

int canFormPairs(std::vector<int> &nums, int diff, int p)
{
    int pairs = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] - nums[i] <= diff)
        {
            pairs++;
            i++;
        }
    }
    return pairs >= p;
};

int minimizeMax(std::vector<int> &nums, int p)
{
    // int arr[] = {5, 2, 9, 1, 5, 6};
    int lengthNums = nums.size();

    std::sort(nums.begin(), nums.end());

    std::cout << "Sorted array: ";
    for (int i = 0; i < lengthNums; ++i)
    {
        std::cout << nums[i] << " ";
    }

    int left = 0;
    int right = nums[lengthNums - 1] - nums[0];
    int result = -1;
    int middle = 0;

    while (left <= right)
    {
        middle = (left + right) >> 1;
        if (canFormPairs(nums, middle, p))
        {
            result = middle;
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        };
    }
    return result;
}

int main()
{
    std::vector<int> nums = {10, 1, 2, 7, 1, 3};
    int p = 2;
    int peakIndex = minimizeMax(nums, p);
    int result = minimizeMax(nums, p);
    std::cout << "Result: " << result << std::endl;
    return 0;
}