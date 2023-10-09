#include <vector>
#include <utility>
#include <cassert>
#include <iostream>

struct Triplet {
    int val;
    int min;
    int max;
};

struct MinMaxStack {

    std::vector<Triplet> v;

    MinMaxStack() {
        
    }
    
    void push(int val) {
        if (!v.size()) {
            v.push_back(Triplet{val, val, val});
        }
        else {
            Triplet curr;
            curr.val = val;

            if (getMin() > val)
                curr.min = val;
            else
                curr.min = getMin();

            if (getMax() < val)
                curr.max = val;
            else
                curr.max = getMax();

            v.push_back(curr);
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().val;
    }
    
    int getMin() {
        return v.back().min;
    }

    int getMax() {
        return v.back().max;
    }

    MinMaxStack(std::vector<int> initVec) {
        for (auto v: initVec) {
            push(v);
        }
    }
};

int main(int argc, char* argv[]) {
    // [0,1,0,2,1,0,1,3,2,1,2,1]
    MinMaxStack stack({0,1,0,2,1,0,1,3,2,1,2,1});
    
    for (auto v: stack.v) {
        std::cout << v.min << " ";
    }

    std::cout << std::endl;

    for (auto v: stack.v) {
        std::cout << v.max << " ";
    }

    std::cout << std::endl;

    

    return 0;
}