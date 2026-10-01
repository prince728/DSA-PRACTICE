/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;

        while (curr) {
            Node* nextOriginal  = curr->next;
            curr->next = nullptr;
            Node* copyNode  = new Node(curr->val);
            curr->next = copyNode;
            copyNode->next = nextOriginal;
            
            curr = nextOriginal;
        }


        curr= head;

        while(curr){
            if(curr->random){
            Node* randptr=curr->random;
            Node* Next = curr->next;

            Next->random = randptr->next;

            }

            curr= curr->next->next;
        }

        curr= head;
        Node * dummy = new Node(0);
        Node* tail = dummy;

        while(curr){
            Node* copyNode = curr->next;
            Node* nextOriginal = copyNode->next;
            
            tail->next = copyNode;
            tail = tail->next;
            
            curr->next = nextOriginal;
            
            curr = nextOriginal;
        }

        return dummy->next;


    }
};