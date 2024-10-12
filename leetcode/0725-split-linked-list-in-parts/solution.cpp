class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v;
        int size = 0;
        ListNode* temp = head;
        while( temp){
            size++;
            temp = temp->next;
        }
        int a = size/k;
        int b = size%k;
        temp = head;
        ListNode* camp ;
        while( temp ){
            ListNode* c = new ListNode(100);
            ListNode* ctemp = c;
            int s = a;
            if(b > 0) s++;
            b--;
            for( int i = 1 ; i <= s ; i++){
                ctemp->next = temp;
                temp = temp->next;
                ctemp = ctemp->next;
            }
            ctemp->next = NULL;
            v.push_back(c->next);
        }
        if( v.size() < k){
            int extra = k - v.size();
            for( int i = 1 ; i <= extra ; i++){
                v.push_back(NULL);
            }
        }
        return v;      
    }
};
