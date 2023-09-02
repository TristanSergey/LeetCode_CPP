// Дан массив целых чисел, найти длину самой длинной(строго) возрастающей подпоследовательности из данного массива.
// 300  + GFG

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

int longestSubsequence(int n, int a[])
{

    vector<int> remainder(n, 0);
    int length = 1;

    remainder[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > remainder[length - 1])
        {
            remainder[length] = a[i];
            length++;
        }
        else
        {
            int idx = lower_bound(remainder.begin(), remainder.begin() + length, a[i]) - remainder.begin();
            remainder[idx] = a[i];
        }
    }

    return length;
}
// int lengthOfLIS(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> remainder(n, 0);
//     int length = 1;

//     remainder[0] = nums[0];

//     for (int i = 1; i < n; i++)
//     {
//         if (nums[i] > remainder[length - 1])
//         {
//             remainder[length] = nums[i];
//             length++;
//         }
//         else
//         {
//             int idx = lower_bound(remainder.begin(), remainder.begin() + length, nums[i]) - remainder.begin();
//             remainder[idx] = nums[i];
//         }
//     }

//     return length;
// }
// int lengthOfLIS(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n, 1);
//     int maxLen = 1;

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (nums[i] > nums[j])
//                 dp[i] = max(dp[i], dp[j] + 1);
//             maxLen = max(maxLen, dp[i]);
//         }
//     }

//     return maxLen;
// }
// && dp[i] <= dp[j] + 1
int main()
{
    int a[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = 16;
    // vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    //  vector<int> nums = {0, 1, 0, 3, 2, 3};
    //   vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
    vector<int> nums = {5, 8, 3, 7, 9, 1};
    int result = longestSubsequence(n, a);
    // int result = lengthOfLIS(nums);
    std::cout << "Длина последовательности : " << result << std::endl;
    return 0;
}

// vector<int> dp(n, 1);
// int maxLen = 1;
// for (int i = 1; i < n; i++)
// {
//     for (int j = 0; j < i; j++)
//     {
//         if (a[i] > a[j])
//         dp[i] = max(dp[i], dp[j] + 1);
//         maxLen = max(maxLen, dp[i]);
//     }
// }
// return maxLen;