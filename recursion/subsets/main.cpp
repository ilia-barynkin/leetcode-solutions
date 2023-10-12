#include <vector>
#include <cassert>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

class Solution {
    vector<vector<int>> result;
public:
    void dfs(vector<int> curr, vector<int> other) {
        if (other.size() == 0) {
            if (curr.size() == 0)
                result.push_back(curr);

            return;
        }
        
        int other_back = other.back();
        other.pop_back();
        dfs(curr, other);

        curr.push_back(other_back);
        dfs(curr, other);

        result.push_back(curr);

    }

    vector<vector<int>> subsets(const vector<int>& nums) {
        dfs({}, nums);

        return result;
    }

    bool test(const vector<vector<int>>& result, const vector<vector<int>>& expected) {
        auto result_s = set<set<int>>();

        for (auto& vec: result) {
            result_s.insert(set<int>(vec.begin(), vec.end()));
        }

        auto expected_s = set<set<int>>();

        for (auto& vec: expected) {
            expected_s.insert(set<int>(vec.begin(), vec.end()));
        }

        return result_s == expected_s;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    // Example 1:

    // Input: nums = [1,2,3]
    // Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

    sol.test(sol.subsets({1,2,3}), {{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}});



    // Example 2:

    // Input: nums = [0]
    // Output: [[],[0]]
    sol.test(sol.subsets({0}), {{},{0}});

    return 0;
}