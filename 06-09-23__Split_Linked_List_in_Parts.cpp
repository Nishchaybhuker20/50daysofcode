class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *cur = head;
        vector<ListNode*> answer(k) ;
        int ptr = 0, listLength = 0;

        // Calculate the length of the linked list
        while (cur != nullptr) {
            listLength++;
            cur = cur->next;
        }

        // Calculate the extra elements in some parts
        int extra = listLength % k;
        // Calculate the base length for each part
        int partLength = listLength / k;
        cur = head;

        while (cur != nullptr) {
            answer[ptr++] = cur;
            // Calculate the length of the current part
            int currentLength = partLength - 1 + ((extra-- > 0) ? 1 : 0);

            // Move the current pointer to the end of the current part
            for (int i = 0; i < currentLength; i++)
                cur = cur->next;

            // Disconnect the current part from the next part
            ListNode *temp = cur->next;
            cur->next = nullptr;
            cur = temp;
        }
        return answer;
    }
};