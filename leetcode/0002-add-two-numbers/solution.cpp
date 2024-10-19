class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v;
        ListNode* temp = l1;
        while( temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        temp = l2;
        int i = 0;
        int n = v.size();
        bool b = false;
        while( temp != NULL){
            if( i < n) v[i] += temp->val;
            else{
                v.push_back(temp->val);
                b = true;
            }
            i++;
            temp = temp->next;
        }
        n = v.size();
        for( int i = 0 ; i < n ; i++){
            if( v[i] > 9 && i < n-1) v[i+1] += v[i]/10, v[i] %= 10;
            else if( v[i] > 9 && i == n-1 ) v.push_back(v[i]/10), v[i] %= 10;

        }
        i = 0;
        n = v.size();
        v.pop_back();
        if( b == false){
            temp = l1;
            ListNode* ramp;
            while( i < n && temp != NULL){
                temp->val = v[i];
                i++;
                ramp = temp;
                temp = temp->next;
            }
            if( i < n){
                ListNode* camp = new ListNode(v[i]);
                ramp->next = camp;
            }
            return l1;
            
        }
        else {
            temp = l2;
            ListNode* ramp;
            while( i < n && temp != NULL){
                temp->val = v[i];
                i++;
                ramp = temp;
                temp = temp->next;
            }
            if( i < n){
                ListNode* camp = new ListNode(v[i]);
                ramp->next = camp;
            }
            return l2;
        }
    }
};
