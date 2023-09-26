// Учитывая, что массив целых чисел представляет собой ежедневную температуру,
// верните ответ массива, такой, что ответ[i] — это количество дней,
// которое вам нужно подождать после i - го дня, чтобы получить более высокую температуру.
// Если нет будущего дня, для которого это возможно, вместо этого сохраните ответ[i] == 0.
// 739
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> result(temperatures.size(), 0);
    stack<int> stack;
    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!stack.empty() && temperatures[i] > temperatures[stack.top()])
        {
            int prevItem = stack.top();
            stack.pop();
            result[prevItem] = i - prevItem;
        }
        stack.push(i);
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> days = dailyTemperatures(nums);

    for (const auto &day : days)
    { // Заменил "const day of days" на "const auto &day : days"
        cout << day << " ";
    }
    return 0;
}