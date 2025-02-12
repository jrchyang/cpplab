#include <iostream>
#include "leetcode_listnode.h"

using namespace std;

ListNode *detect_cycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    do {
        if (!fast || !fast->next)
            return nullptr;

        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}

int main() {
    return 0;
}
