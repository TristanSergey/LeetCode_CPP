#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;
void solve(vector<vector<int>> &ans, vector<int> v, vector<int> &candidates, int target, int index);

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)

{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> v;
    int index = 0;

    solve(ans, v, candidates, target, index);
    return ans;
}

void solve(vector<vector<int>> &ans, vector<int> v, vector<int> &candidates, int target, int index)
{
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    if (target < 0)
    {
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        v.push_back(candidates[i]);
        solve(ans, v, candidates, target - candidates[i], i + 1);
        v.pop_back();
    }
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
    int target = 8;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> result = combinationSum2(candidates, target);

    std::cout << "Пройдет: ";
    for (const std::vector<int> &combination : result)
    {
        std::cout << "[";
        for (int num : combination)
        {
            std::cout << num << " ";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;
    return 0;
}