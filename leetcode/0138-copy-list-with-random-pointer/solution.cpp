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
    Node* merge(Node* l1,Node* l2){

        Node* t1 = l1;
        Node* t2 = l2;
        Node* t11 = t1->next;
        Node* t22 = t2->next;
        while(t1 != NULL){
            t1->next = t2;
            t2->next = t11;
            if( t11 == NULL) break;
            t1 = t11;
            t2 = t22;
            t11 = t11->next;
            t22 = t22->next;
        }
        return l1;
    }
    void randomassign(Node* d){
        Node* temp = d;
        while( temp != NULL && temp->next != NULL ){
            if(temp->next != NULL && temp->random != NULL) temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
    }
    Node* copyRandomList(Node* head) {
        if( head == NULL) return NULL;
        Node* dummy = makedummy(head);
        Node* d = merge(head,dummy);
        randomassign(d);
        Node* list1 = d;
        Node* list2 = d->next;
        Node* temp = d;
        Node* temp1 = list1;
        Node* temp2 = list2;
        int count = 1;
        while( temp1 != NULL && temp1->next->next != NULL){
            temp1->next = temp1->next->next;
            temp1 = temp1->next;
            temp2->next = temp1->next;
            temp2 = temp2->next;
        }
        temp1->next = NULL;
        temp2->next = NULL;
        
        return list2;
    }
};
