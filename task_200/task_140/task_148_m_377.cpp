// Учитывая массив различных целых чисел nums и целевое целое число target,
// вернуть количество возможных комбинаций, которые в сумме дают target.
// Тестовые примеры генерируются таким образом, чтобы ответ мог уместиться в 32 - битном целом числе.
// 377

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

int combinationSum4(vector<int> &nums, int target)
{
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int num : nums)
        {
            if (i - num >= 0)
            {
                dp[i] += dp[i - num];
            }
        }
    }
    return dp[target];
};

int main()
{
    int target = 5;
    vector<int> nums = {1, 2, 3};
    bool result = combinationSum4(nums, target);

    std::cout << result << " ";

    std::cout << std::endl;
    return 0;
}
