#include <unordered_set>
#include <cstdlib>
#include <cassert>

#include "../util.hpp"

class Solution {
public:
    bool hasCycleHash(ListNode *head) {
        std::unordered_set<ListNode*> passed;
        for (;;) {
            if (!head)
                return false;
            if (passed.find(head) != passed.end()) 
                return true;
            
            passed.insert(head);
            head = head->next;
        }

        return false;
    }

    bool hasCycle(ListNode* list) {
        auto slow = list;
        auto fast = list;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};

int main(int argc, char* argv[]) {
    //Input: head = [3,2,0,-4], pos = 1
    //Output: true

    Solution sol;

    auto list = initList({3,2,0,-4});
    makeLoop(list, 1);

    assert(sol.hasCycle(list));
    assert(!sol.hasCycle(initList({1})));

    return 0;
}