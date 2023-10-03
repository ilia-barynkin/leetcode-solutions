#include "../util.hpp"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* result = head;
        auto left = insertPrev(head);
        auto right = head;
        
        for (int i = 0; right && i < n; ++i)
            right = right->next;

        while (right) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;

        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    // head = [1,2,3,4,5], n = 2
    // Output: [1,2,3,5]

    auto result = sol.removeNthFromEnd(initList({1,2,3,4,5}), 2);
    printList(result);

    return 0;
}