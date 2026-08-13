/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* NextNode = curr->next;
                Node* childHead = curr->child;
                Node* childTail = childHead;

                while (childTail->next) {
                    childTail = childTail->next;
                }

                childTail->next = NextNode;
                if (NextNode) {
                    NextNode->prev = childTail;
                }

                curr->next = childHead;
                childHead->prev = curr;

                curr->child = nullptr;
            }
            curr = curr->next;
        }

        return head;
    }
};