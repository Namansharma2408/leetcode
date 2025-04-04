class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class MyLinkedList {
public:
    Node* head;
    MyLinkedList() {
        this->head = NULL;
    }
    
    int get(int index) {
        int idx = 0;
        Node* temp = head;
        while( idx < index && temp != NULL){
            temp = temp->next;
            idx++;
        }
        if(temp != NULL)return temp->val;
        else return -1;
    }
    
    void addAtHead(int val) {
        Node* h = new Node(val);
        h->next = head;
        head = h;
    }
    
    void addAtTail(int val) {
        if( head == NULL){
            addAtHead(val);
            return;
        }
        Node* temp = head;
        while( temp->next != NULL){
            temp = temp->next;
        }
        Node* a = new Node(val);
        temp->next = a;
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0) {
            addAtHead(val);
            return;
        }        
        Node* temp = head;
        int idx = 1;
        while( idx < index && temp!= NULL){
            temp = temp->next;
            idx++;
        }
        Node* a = new Node(val);
        if(temp != NULL){
            a->next = temp->next;
            temp->next = a;
        }

    }
    
    void deleteAtIndex(int index) {
        if( head == NULL) return;
        if(index == 0){
            head = head->next;
        }else{
            Node* temp = head;
            int idx = 1;
            while( idx < index && temp != NULL){
                temp = temp->next;
                idx++;
            }
            if(temp != NULL && temp->next != NULL )temp->next = temp->next->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
