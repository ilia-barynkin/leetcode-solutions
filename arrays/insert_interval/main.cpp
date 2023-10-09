#include <vector>
#include <cassert>

using namespace std;

typedef vector<int> interval;

int bsearch(std::vector<int>& v, int target) {
    return bsearch(v.data(), target, 0, v.size());
}

int bsearch(int* arr, int target, int start, int end) {
    if (start == end)
        return -1;
    
    auto mid = start + (end - start) / 2;

    if (target == arr[mid])
        return mid;
    else if (target < arr[mid])
        return bsearch(arr, target, start, mid);
    else
        return bsearch(arr, target, mid, end);
}

class Solution {
public:
    vector<vector<int>> insert(vector<interval>& intervals, vector<int>& newInterval) {
        //auto id_start = bsearchId(intervals, 0, intervals.size(), newInterval[0]);
        //auto id_end = bsearchId(intervals, 0, intervals.size(), newInterval[1]);


        // vector<interval> result(intervals.size());(intervals.begin(), intervals.begin() + id_start);
        // result.push_back(interval{newInterval[0] > intervals[]})

        return vector<interval>();
    }
};

int main(int argc, char* argv[]){
    assert(bsearch(std::vector<int>{1,2,3,4}.data(), 0, 0, 4) == -1);
    assert(bsearch(std::vector<int>{1,2,3,4}.data(), 1, 0, 4) == 0);
    assert(bsearch(std::vector<int>{1,2,3,4}.data(), 3, 0, 4) == 2);
    assert(bsearch(std::vector<int>{1,2,3,4}.data(), 6, 0, 4) == -1);

    return 0;
}