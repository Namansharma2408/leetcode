class Solution {
public:
    class ListNode {
    public:
        long long val;
        ListNode* next;
        ListNode(long long val) {
            this->val = val;
            this->next = NULL;
        }
    };

    bool isSorted(ListNode* head) {
        if (head == NULL)
            return true;
        ListNode* temp = head;
        while (temp && temp->next != NULL) {
            if (temp->val > temp->next->val) {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }
    bool findMinAndRem(ListNode* head) {
        if (!head || !head->next)
            return false;

        ListNode* temp = head;
        ListNode* best = head;
        long long minSum = head->val + head->next->val;

        while (temp && temp->next) {
            long long s = temp->val + temp->next->val;
            if (s < minSum) {
                minSum = s;
                best = temp;
            }
            temp = temp->next;
        }
        
        best->val += best->next->val;
        best->next = best->next->next;
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        ListNode* head = new ListNode(nums[0]);
        int n = nums.size();
        ListNode* temp = head;
        for (int i = 1; i < n; i++) {
            ListNode* node = new ListNode(nums[i]);
            temp->next = node;
            temp = node;
        }
        int ans = 0;
        while (!isSorted(head)) {
            if (!findMinAndRem(head))
                break;
            ans++;
        }
        return ans;
    }
};
