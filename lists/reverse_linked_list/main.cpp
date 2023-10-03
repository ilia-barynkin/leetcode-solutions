#include <memory>
#include <iostream>

#include "../util.hpp"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* shift = nullptr;

        while (head) {
            auto prevNxt = head->next;
            head->next = shift;
            shift = head;
            head = prevNxt;
        }

        return shift;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    auto test = initList({1,2,3,4,5});
    auto reversed = sol.reverseList(test);

    return 0;
}