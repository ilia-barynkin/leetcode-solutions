#include <vector>
#include <cassert>

using namespace std;

typedef vector<int> interval;

// int bsearch(int* arr, int target, int start, int end) {
//     if (start == end)
//         return -1;
    
//     auto mid = start + (end - start) / 2;

//     if (target == arr[mid])
//         return mid;
//     else if (target < arr[mid])
//         return bsearch(arr, target, start, mid);
//     else
//         return bsearch(arr, target, mid, end);
// }

typedef vector<interval>::iterator iter;

iter bsearch(iter begin, iter end, int val) {
    if ((end - begin) / 2 <= 0) 
        return begin;

    auto mid = begin + (end - begin) / 2;

    if ((*mid)[0] <= val && val <= (*mid)[1])
        return mid;

    if (val < (*mid)[0])
        return bsearch(begin, mid, val);

    return bsearch(mid, end, val);
}

/**
 * Merges two intervals and returns the merged interval.
 *
 * @param first the first interval to merge
 * @param second the second interval to merge
 *
 * @return a vector containing the merged interval
 *
 * @throws None
 */
void append(vector<interval>& intervals, interval& newInterval) {
    // |---| 
    //        |---|
    if (intervals.size() == 0 || intervals.back()[1] < newInterval[0])
        intervals.push_back(newInterval);

    // b) |---|
    //       |---|
    else //if (newInterval[0] <= intervals.back()[1]) 
        intervals.back()[1] = max(intervals.back()[1], newInterval[1]);
}

void prepend(vector<interval>& intervals, interval& newInterval) {
    //       |---| 
    // |---|
    if (intervals.size() == 0 || newInterval[1] < intervals.front()[0])
        intervals.push_back(newInterval);

    // b)    |---|
    //    |---|
    else //if (newInterval[0] <= intervals.back()[1]) 
        intervals.back()[0] = min(intervals.front()[0], newInterval);
}

class Solution {
public:
/**
 * Inserts a new interval into a vector of intervals and returns the updated vector.
 *
 * @param intervals the vector of intervals to insert into
 * @param newInterval the interval to insert
 *
 * @return the updated vector of intervals
 *
 * @throws None
 */
vector<vector<int>> insert(vector<interval>& intervals, vector<int>& newInterval) {
    vector<interval> result;
    result.reserve(intervals.size() + 1);

    auto left = bsearch(intervals.begin(), intervals.end(), newInterval[0]);
    if (left == intervals.end()) {
        append(result, newInterval);
        return result;
    }

    result.insert(result.end(), intervals.begin(), left + 1);
    append(result, newInterval);

    auto right = bsearch(intervals.begin(), intervals.end(), newInterval[1]);
    result.insert(result.end(), );

    return result;
}
};

int main(int argc, char* argv[]){
    auto test = vector<interval>{{1,2},{3,4}};
    assert(bsearch(test.begin(), test.end(), 1) == test.begin());
    assert(bsearch(test.begin(), test.end(), 0) == test.begin());
    assert(bsearch(test.begin(), test.end(), 4) == test.begin() + 1);
    assert(bsearch(test.begin(), test.end(), 5) == test.begin() + 1);

    return 0;
}