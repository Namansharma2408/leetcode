/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st;
        for( int i : nums ){
            st.insert(i);
        }
        int count = 0;
        ListNode* temp = head;
        int size = 0;
        while( temp ){
            if( st.find(temp->val) != st.end() ) {
                size++;
            }
            else {
                if( size > 0 ) {
                    count++;
                    size = 0;
                }
            }
            temp = temp->next;
        }
        if( size > 0 ) count++;
        return count;
    }
};
