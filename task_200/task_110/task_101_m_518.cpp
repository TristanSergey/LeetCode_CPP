// Вам дан целочисленный массив монет, представляющий монеты разного номинала,
// и целочисленная сумма, представляющая общую сумму денег.
// Возвращает количество комбинаций, составляющих эту сумму.
// Если эта сумма денег не может быть компенсирована какой - либо комбинацией монет, верните 0.
// Вы можете предположить, что у вас есть бесконечное количество монет каждого вида.
// 518
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

long long int count(int coins[], int N, int sum)
{

    // vector<long long int> dp(sum + 1, 0);
    // dp[0] = 1;

    // for (int i = 0; i < N; i++)
    //     for (long long int j = coins[i]; j <= sum; j++)
    //         dp[j] += dp[j - coins[i]];

    // return dp[sum];

    vector<long long int> dp(sum + 1, 0);
    dp[0] = 1;
    // std::cout << "Способы  : " << dp[0] << " - " << dp[1] << " - " << dp[2] << " - " << dp[3] << " - " << dp[4] << " - " << dp[5] << " - " << dp[5] << std::endl;
    for (int coin = 0; coin < N; coin++)
    {
        //  std::cout << "++++++++++++++++ : " << std::endl;
        for (int i = coins[coin]; i <= sum; i++)
        {

            //    std::cout << "I  : " << i << " Coin :  " << coin << " sum : " << sum << std::endl;
            dp[i] += dp[i - coins[coin]];
            //   std::cout << "Способы  : " << dp[0] << " - " << dp[1] << " - " << dp[2] << " - " << dp[3] << " - " << dp[4] << " - " << dp[5] << " - " << dp[6] << std::endl;

            //    std::cout << "-------------------- : " << std::endl;
        }
    }

    // std::cout << "Результат   : " << dp[sum] << std::endl;
    // return static_cast<long long int>(dp[sum]);
    return dp[sum];
}

int main()
{
    // int amount = 5;
    // vector<int> coins = {5, 7, 5, 6, 5, 5, 5, 6, 7};

    // int coins[] = {5, 7, 5, 6, 5, 5, 5, 6, 7};
    int coins[] = {9, 8, 7, 9, 8, 5, 6};
    // int coins[] = {1, 2, 5};
    int N = 7;
    int sum = 7;

    long long int result = count(coins, N, sum);
    // int result = change(amount, coins);
    std::cout << "Индекс строки с максимальным количеством единиц : " << result << std::endl;
    // std::cout << "Количество единиц в этой строке: " << result[1] << std::endl;
    return 0;
}

// int change(int amount, vector<int> &coins)
// {
//     vector<int> dp(amount + 1, 0);
//     dp[0] = 1;
//     for (const auto &coin : coins)
//     {
//         for (int i = coin; i <= amount; i++)
//         {
//             dp[i] += dp[i - coin];
//         }
//     }
//     return dp[amount];
// }

// long long int count(int coins[], int N, int sum)
// {
//     vector<int> dp(N + 1, 0);
//     dp[0] = 1;
//     for (int coin = 0; coin <= N; coin++)
//     {
//         for (int i = coin; i <= sum; i++)
//         {
//             dp[i] += dp[i - coin];
//         }
//     }
//     return static_cast<long long int>(dp[sum]);
// }