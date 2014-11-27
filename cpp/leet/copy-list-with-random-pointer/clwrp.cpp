/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    

    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> m;
        RandomListNode *re = head;
        
        RandomListNode *node = NULL;
        
        while (head) {
            if (m[head] != NULL) {
                node = m[head];
            } else {
                node = new RandomListNode(head->label);
                m[head] = node;
            }
            head = head->next;
        }
        
        head = re;
        while (head) {
            if (head->random) m[head]->random = m[head->random];
            if (head->next) m[head]->next = m[head->next];
            head = head->next;
        }
    
        return m[re];
    }
};