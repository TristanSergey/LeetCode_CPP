#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;
const int mod = 1e9 + 7;
int findCatalan(int n)
{

    // code here
    vector<int> dp(n);
    {
        long long int mod = 1e9 + 7;
        vector<long long int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {

            for (int j = 0; j <= i; j++)
            {
                dp[i] += (dp[j - 1] * dp[i - j]) % mod;
                dp[i] = (dp[i]) % mod;
            }
        }

        return dp[n];
    }

    // {

    //     vector<long long int> pref(n + 1);
    //     pref[0] = 1;
    //     pref[1] = 1;
    //     for (int i = 2; i <= n; i++)
    //     {
    //         for (int j = 1; j <= i; j++)
    //         {
    //             pref[i] += (pref[j - 1] * pref[i - j]) % mod;
    //             pref[i] = (pref[i]) % mod;
    //         }
    //     }
    //     return pref[n];
    // }
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
    // vector<int> nums = {3, 2, 1, 0, 4};
    int n = 25;
    int result = findCatalan(n);

    std::cout << "Пройдет : " << result << std::endl;
    return 0;
}

// int findCatalan(int n)
// {
//     vector<int> dp(n, 0);
//     dp[0] = 1;
//     dp[1] = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = 0;
//         for (int j = 0; j < i; j++)
//         {
//             dp[i] += dp[j] * dp[i - j - 1];
//         }
//     }
//     int result = dp[n] % 1000000007;
//     return result;
// }