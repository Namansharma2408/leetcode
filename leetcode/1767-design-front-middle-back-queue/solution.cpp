class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class FrontMiddleBackQueue {
public:
    Node* head;
    Node* tail;
    Node* mid;
    int size;
    FrontMiddleBackQueue() {
        this->head = NULL;
        this->tail = NULL;
        this->mid = NULL;
        this->size = 0;
    }
    void print(Node* head){
        Node* temp = head;
        while( temp != NULL) cout<<temp->val<<" ",temp = temp->next;
        cout<<endl;
    }
    void pushFront(int val) {
        Node* temp = new Node(val);
        if( size == 0 ){
            head = temp;
            tail = temp;
            mid = temp;
        }else {
            temp->next = head;
            head->prev = temp;
            head = temp;
            if( size%2 == 1 ) mid = mid->prev;
        }
        size++; 
        print(head);       
    }
    
    void pushMiddle(int val) {
        Node* temp = new Node(val);
        if( size == 0 ){
            head = temp;
            tail = temp;
            mid = temp;
        }else {
            if( size%2 == 0){
                temp->next = mid->next;
                temp->prev = mid;
                mid->next = temp;
                temp->next->prev = temp;
                mid = mid->next;

            }else if(size == 1){
                Node* temp = new Node(val);
                temp->next = head;
                head = temp;
                mid = head;
                tail->prev  = head;
            }else{
                temp->next = mid;
                temp->prev = mid->prev;
                temp->prev->next = temp;
                mid->prev = temp;
                mid = mid->prev;
            }
        }
        size++;
        print(head); 
        cout<<head->val<<" "<<mid->val<<" "<<tail->val<<endl<<endl;     
    }
    
    void pushBack(int val) {
        Node* temp = new Node(val);
        if( size == 0 ){
            head = temp;
            tail = temp;
            mid = temp;
        }else {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
            if( size%2 == 0 ) mid = mid->next;
        }
        size++;  
        print(head);        
    }
    
    int popFront() {
        if( size == 0 ) return -1;
        if( size == 1 ) {
            int ans = head->val;
            head = NULL;
            tail = NULL;
            mid = NULL;
            size--;
            return ans;
        }else{
            int ans = head->val;
            head = head->next;
            if( size%2 == 0) mid = mid->next;
            size--;
            return ans;
        }
    }
    
    int popMiddle() {
        if( size == 0 ) return -1;
        if( size == 1 ) {
            int ans = head->val;
            head = NULL;
            tail = NULL;
            mid = NULL;
            size--;
            return ans;
        }else if(size == 2){
            int ans = head->val;
            head = head->next;
            mid = mid->next;
            size--;
            return ans;
        }
        else{
            int ans = mid->val;
            mid->prev->next = mid->next;
            mid->next->prev = mid->prev;
            if( size%2 == 0) mid = mid->next;
            else mid = mid->prev;
            size--;
            return ans;
        }
    }
    
    int popBack() {
        if( size == 0 ) return -1;
        if( size == 1 ) {
            int ans = head->val;
            head = NULL;
            tail = NULL;
            mid = NULL;
            size--;
            return ans;
        }else{
            int ans = tail->val;
            tail = tail->prev;
            tail->next = NULL;
            if( size%2 == 1) mid = mid->prev;
            size--;
            return ans;
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
