#include <cassert>

#include "../util.hpp"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        for(auto fast = head; fast && fast->next; fast = fast->next->next) {
            head = head->next;
        }

        return head;
    }
};

int main(int argc, char* argv[]) {

    //head = [1,2,3,4,5,6]
    //[4,5,6]

    Solution sol;

    printList(sol.middleNode(initList({1,2,3,4,5,6})));

    return 0;
}