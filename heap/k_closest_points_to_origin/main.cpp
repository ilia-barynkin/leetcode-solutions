#include <vector>
#include <queue>
#include <cassert>

using namespace std;

struct Compare {
    bool operator()(const vector<int>& v0, const vector<int>& v1) const {
        return (v0[0] * v0[0] + v0[1] * v0[1]) > (v1[0] * v1[0] + v1[1] * v1[1]);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(const vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> ranges(points.begin(), points.end());
        vector<vector<int>> res;

        for (; k >0; --k) {
            res.push_back(ranges.top());
            ranges.pop();
        }
        
        return res;
    }
};

int main(int argc, char* argv[]) {

    Solution sol;

// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

    //auto r = sol.kClosest({{1, 3}, {-2, 2}}, 1);

// Example 2:

// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted.

    auto rt = sol.kClosest({{3,3}, {5,-1}, {-2,4}}, 2);


    return 0;
}