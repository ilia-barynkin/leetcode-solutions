#include <limits>
#include <vector>
#include <cassert>
#include <iostream>

#include "util.hpp"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(DUMMY_VAL);
        ListNode* tail = head;
        int i = 0;

        printList(list1);
        printList(list2);
        
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next ? tail->next : tail;
        }

        if (list1)
            tail->next = list1;
        else if (list2)
            tail->next = list2;

        return head->next;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    //Input: list1 = [1,2,4], list2 = [1,3,4]
    //Output: [1,1,2,3,4,4]

    auto res = sol.mergeTwoLists(initList({1,2,4}), initList({1,3,4}));
    assert(listToVec(res) == std::vector<int>({1,1,2,3,4,4}));

    //Input: list1 = [], list2 = []
    //Output: []

    res = sol.mergeTwoLists(initList({}), initList({}));
    assert(listToVec(res) == std::vector<int>({}));

    //Input: list1 = [], list2 = [0]
    //Output: [0]

    res = sol.mergeTwoLists(initList({}), initList({0}));
    assert(listToVec(res) == std::vector<int>({0}));

    return 0;
}