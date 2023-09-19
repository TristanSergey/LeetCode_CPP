#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
// #include <utility>
using namespace std;

int minimumRounds(vector<int> &tasks)
{
    int roundCount = 0;
    int remainder = 0;
    std::unordered_map<int, int> taskQuantity;

    for (int num : tasks)
    {
        taskQuantity[num]++;
    }

    for (const auto &pair : taskQuantity)

    {
        if (pair.second < 2)
            return -1;
        remainder = pair.second % 3;
        if ((remainder) == 0)
        {
            roundCount += pair.second / 3;
        }
        else
        {
            if ((pair.second % 3) == 1)
            {
                roundCount += (pair.second - 4) / 3 + 2;
            }
            else
            {
                roundCount += (pair.second - 2) / 3 + 1;
            }
        }
    }
    return roundCount;
}

int main()
{
    std::vector<int> array = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};
    // {1, 2, 3, 2, 1, 3, 2, 1, 4, 4, 2};
    int result = minimumRounds(array);
    cout << "Количество раундов - : " << result << endl;

    return 0;
}