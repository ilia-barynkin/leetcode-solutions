#include <vector>
#include <cassert>

using namespace std;

typedef vector<int> interval;

class Solution {
public:
    int bsearchId(vector<interval> intervals, int id_begin, int size, int target) {
        return bsearchId(&intervals, id_begin, size, target);
    }

    int bsearchId(vector<interval>* intervals, int id_begin, int size, int target) {
        auto id_mid = (size - id_begin) / 2;
        
        if (id_mid == 0)
            return -1;

        interval curr_interval = intervals->at(id_begin + id_mid);
        
        // point belongs to interval
        if (curr_interval[0] >= target && target <= curr_interval[1])
            return id_mid;
        
        if (target < curr_interval[0]) {
            auto result = bsearchId(intervals, id_begin, id_mid, target);
            return result > 0 ? result : id_mid;
        }

        else { //if (curr_interval[1] < target) {
            auto result = bsearchId(intervals, id_mid, size, target);
            return result > 0 ? result : id_mid;
        }
    }

    vector<vector<int>> insert(vector<interval>& intervals, vector<int>& newInterval) {
        auto id_start = bsearchId(intervals, 0, intervals.size(), newInterval[0]);
        auto id_end = bsearchId(intervals, 0, intervals.size(), newInterval[1]);

        // vector<interval> result(intervals.size());(intervals.begin(), intervals.begin() + id_start);
        // result.push_back(interval{newInterval[0] > intervals[]})

        return vector<interval>();
    }

    bool test_bsearchId() {
        assert(bsearchId({{0, 1}, {2, 3}, {4, 5}}, 0, 3, 1) == 0);
        assert(bsearchId({{0, 1}, {2, 3}, {4, 5}}, 0, 3, 5) == 2);
        assert(bsearchId({{0, 1}, {2, 3}, {4, 5}}, 0, 3, 3) == 1);
    }
};

int main(int argc, char* argv[]){
    //intervals = [[1,3],[6,9]], newInterval = [2,5]

    Solution sol;

    sol.test_bsearchId();

    return 0;
}