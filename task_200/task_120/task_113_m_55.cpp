// Вам дан целочисленный массив nums.Изначально вы находитесь в первом индексе массива,
// и каждый элемент массива представляет максимальную длину прыжка в этой позиции.
// Верните true, если вы можете добраться до последнего индекса, или false в противном случае.
// 55

// let = nums = [2, 3, 1, 1, 4];
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return true;

    int end = 0;
    int maxPos = 0;

    for (int i = 0; i < n - 1; i++)
    {
        maxPos = max(maxPos, i + nums[i]);

        if (i == end)
        {
            end = maxPos;
            if (end >= n - 1)
                return 1;
        }
    }

    return 0;
}

int main()
{
    // int A[] = {3, 2, 1, 0, 4};
    // int A[] = {2, 3, 1, 1, 4};
    // nums = [1]
    // nums = [ 2, 0 ]
    // int N = 5;
    // int result = canReach(A, N);
    // vector<int> nums = {5, 8, 3, 7, 9, 1};
    vector<int> nums = {3, 2, 1, 0, 4};
    int result = canJump(nums);

    std::cout << "Пройдет : " << result << std::endl;
    return 0;
}

// int canReach(int A[], int N)
//  {
//      if (N == 1)
//          return true;

//     int end = 0;
//     int maxPos = 0;

//     for (int i = 0; i < N - 1; i++)
//     {
//         maxPos = max(maxPos, i + A[i]);

//         if (i == end)
//         {
//             end = maxPos;
//             if (end >= N - 1)
//                 return 1;
//         }
//     }

//     return 0;
// };