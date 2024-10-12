class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> cp;
        vector<int> cp1;
        ListNode* temp = head;
        int size = 0;

        while(temp){
            temp = temp->next;
            size++;
        }
        if( size < 4){
            cp1.push_back(-1);
            cp1.push_back(-1);
            return cp1;
        }
        temp = head;
        int rise = 0;
        while(temp->next->next != NULL){
            if(((temp->val < temp->next->val) && (temp->next->next->val < temp->next->val)) || ((temp->val > temp->next->val) && (temp->next->next->val > temp->next->val))){
                cp.push_back(rise+1);
            }
            temp = temp->next;
            rise++;
        }
        int n = cp.size();
        if( n < 2){
            cp1.push_back(-1);
            cp1.push_back(-1);
            return cp1;
        }
        int mini = INT_MAX;
        for( int i = 0 ; i < n -1 ; i++){
            mini = min(mini,cp[i+1] - cp[i]);
        }
        cp1.push_back(mini);
        cp1.push_back(cp[n-1] - cp[0]);
        return cp1;
    }
};
