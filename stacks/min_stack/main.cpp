#include <vector>
#include <utility>
#include <cassert>

class MinMaxStack {
    std::vector<std::pair<int, int>> v;
    int min_el;

public:

    MinMaxStack() {
        
    }
    
    void push(int val) {
        if (!v.size() || v.back().second > val) {
            v.push_back(std::pair<int, int>(val, val));
        }
        else {
            v.push_back(std::pair<int, int>(val, v.back().second));
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};

int main(int argc, char* argv[]) {
    MinMaxStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    assert(minStack.getMin() == -3); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
    assert(minStack.getMin() == -2);

    return 0;
}