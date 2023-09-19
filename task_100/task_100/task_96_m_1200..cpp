#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
// #include <utility>
using namespace std;
vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{

    {

        vector<vector<int>> result;
        int minDiff = INT_MAX;

        sort(arr.begin(), arr.end());

        for (int i = 1; i < arr.size(); ++i)
        {
            int diff = arr[i] - arr[i - 1];
            if (diff < minDiff)
            {
                minDiff = diff;
                result.clear();
            }
            if (diff == minDiff)
            {
                result.push_back({arr[i - 1], arr[i]});
            }
        }

        return result;
    }
}

int main()
{
    vector<int> arr = {4, 3, 1, 2};
    vector<vector<int>> result = minimumAbsDifference(arr);
    for (const auto &pair : result)
    {
        cout << "Минимальная абсолютная разница: " << pair[0] << " и " << pair[1] << endl;
    }
    return 0;
}
