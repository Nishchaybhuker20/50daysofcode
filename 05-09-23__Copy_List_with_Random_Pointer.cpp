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
    unordered_map<Node*, Node*> mp;
    Node* copyRandomList(Node* head) {
        if (head==NULL) return NULL;
        if (mp.count(head)!=0) return mp[head];
        Node* newNode=new Node(head->val);
        mp[head]=newNode;
        newNode->next=copyRandomList(head->next);
        newNode->random=copyRandomList(head->random);
        return newNode;
    }
};