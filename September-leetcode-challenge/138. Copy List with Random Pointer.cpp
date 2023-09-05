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
        Node *iter = head;              //      TC -> O(n)..    SC -> O(1)..
    Node *front = head;
     // First round: make copy of each node,
      // and link them together side-by-side in a single list.
    while (iter != NULL)
    {
        front = iter -> next;
        
        Node* copy = new Node(iter -> val);
        iter -> next = copy;
        copy -> next = front;

        iter = front;
    }
    // Second round: assign random pointers for the copy nodes.
    iter = head;
    while (iter != NULL)
    {
        if (iter-> random != NULL)
        {
            iter-> next -> random = iter-> random -> next;
        }
        iter = iter -> next -> next;
    }
    // Third round: restore the original list, and extract the copy list.
    iter = head;
    Node* PseudoHead = new Node(0);
    Node* copy = PseudoHead;
    
    while (iter != NULL)
    {
        front = iter -> next -> next;
        copy -> next = iter -> next;
        iter -> next = front;
        copy = copy -> next;
        iter = iter -> next;
    }
    return PseudoHead -> next;
    }
};