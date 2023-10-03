#include <vector>
#include <string>
#include <unordered_map>
#include <cassert>

struct Stack {
    std::vector<int> vals;
    void push(int val) {
        vals.push_back(val);
    }

    int pop() {
        int res = vals.back();
        vals.pop_back();
        return res;
    }
};

enum Operator {
    Plus,
    Minus,
    Multiply,
    Divide
};

struct Solution {
    std::unordered_map<std::string, Operator> operators = {
        {"+", Operator::Plus},
        {"-", Operator::Minus},
        {"*", Operator::Multiply},
        {"/", Operator::Divide}
    };

    int strToInt(std::string st) {
        return atoi(st.data());
    }

    int evalRPN(std::vector<std::string> tokens) {
        Stack stack;

        for (auto t: tokens) {
            if (operators.count(t)) {
                switch(operators.at(t)) {
                    case Operator::Plus: {
                        stack.push(stack.pop() + stack.pop());
                        break;
                    }
                    case Operator::Minus: {
                        int t = stack.pop();
                        stack.push(stack.pop() - t);
                        break;
                    }
                    case Operator::Multiply: {
                        stack.push(stack.pop() * stack.pop());
                        break;
                    }
                    case Operator::Divide: {
                        int t = stack.pop();
                        stack.push(stack.pop() / t);
                        break;
                    }
                }
            }
            else {
                stack.push(strToInt(t));
            }
        }

        return stack.pop();
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    assert(123 == sol.strToInt("123"));
    assert(sol.evalRPN({"1", "1", "+"}) == 2);

    // Example 1:

    // Input: tokens = ["2","1","+","3","*"]
    // Output: 9
    // Explanation: ((2 + 1) * 3) = 9

    assert(sol.evalRPN({"2","1","+","3","*"}) == 9);

    // Example 2:

    // Input: tokens = ["4","13","5","/","+"]
    // Output: 6
    // Explanation: (4 + (13 / 5)) = 6

    assert(sol.evalRPN({"4","13","5","/","+"}) == 6);

    // Example 3:

    // Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    // Output: 22
    // Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    // = ((10 * (6 / (12 * -11))) + 17) + 5
    // = ((10 * (6 / -132)) + 17) + 5
    // = ((10 * 0) + 17) + 5
    // = (0 + 17) + 5
    // = 17 + 5
    // = 22

    assert(sol.evalRPN({"10","6","9","3","+","-11","*","/","*","17","+","5","+"}) == 22);

    assert(-4 == sol.strToInt("-4"));

    return 0;
}