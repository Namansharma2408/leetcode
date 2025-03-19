class Solution {
public:
    Node* makedummy(Node* head){
        Node* dummy;
        Node* temp = head;
        Node* dtemp = new Node(temp->val);
        dummy = dtemp;
        while( temp != NULL){
            Node* d = new Node(temp->val);
            dtemp->next = d;
            dtemp = d;
            temp = temp->next;
        }
        return dummy->next;
    }
    
    Node* copyRandomList(Node* head) {
        if( head == NULL) return NULL;
        Node* head2 = makedummy(head);
        unordered_map<Node*,Node*> mp;
        Node* tempa = head;
        Node* tempb = head2;
        while( tempa!= NULL){
            mp[tempa] = tempb;
            tempa = tempa->next;
            tempb = tempb->next;
        }
        for( auto x : mp){
            Node* c = x.first;
            Node* d = x.second;
            if(c->random != NULL)  d->random = mp[c->random];
            else d->random = NULL;
            
        }
        return head2;
    }
};
