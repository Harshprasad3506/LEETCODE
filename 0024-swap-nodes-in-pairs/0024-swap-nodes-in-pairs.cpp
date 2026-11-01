// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         vector<ListNode*> nodes;
//         ListNode* temp = head;

//         while (temp != NULL) {
//             nodes.push_back(temp);
//             temp = temp->next;
//         }

//         for (int i = 0; i + 1 < nodes.size(); i += 2) {
//             swap(nodes[i], nodes[i + 1]);
//         }

//         for (int i = 0; i + 1 < nodes.size(); i++) {
//             nodes[i]->next = nodes[i + 1];
//         }

//         if (!nodes.empty()) {
//             nodes.back()->next = NULL;
//             return nodes[0];
//         }

//         return NULL;
//     }
// };


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next != NULL &&
               prev->next->next != NULL) {

            ListNode* first = prev->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};