#include <string>
#include <cassert>

class Solution {
public:
    bool isValid(std::string s) {

       std::string prtStack = " ";

        for (auto l : s) {
            switch (l) {
                case '}':
                    if (prtStack.back() != '{')
                        return false;
                    else
                        prtStack.pop_back();
                    break;
                case ']':
                    if (prtStack.back() != '[')
                        return false;
                    else
                        prtStack.pop_back();
                    break;
                case ')':
                    if (prtStack.back() != '(')
                        return false;
                    else
                        prtStack.pop_back();
                    break;
                default:
                    prtStack.push_back(l);
                    break;
            }
        }

        return prtStack == " ";
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    assert(sol.isValid("()"));
    assert(sol.isValid("()[]{}"));
    assert(!sol.isValid("(]"));
    assert(!sol.isValid("]"));

    return 0;   
}