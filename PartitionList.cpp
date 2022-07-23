/* Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.



Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]


Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200*/

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
struct ListNode
{
    int value;
    ListNode *next;
} class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        // we will make two list list1 contain element lesser than x and list two contain element bigger than x
        // and after that put list 2 in list1->next
        ListNode *list1 = new ListNode(0); // initially  given 0 to list 1
        ListNode *list2 = new ListNode(0); // initially  given 0 to list 2

        ListNode *l1 = list1; // l1=0 initially
        ListNode *l2 = list2; // l2=0  initially

        while (head)
        { // while head!=null ITERATE OVER THE ll
            if (head->val < x)
            {                    // IF val of head <x
                l1->next = head; // put head in l1->next   0->1->2->2->NULL
                l1 = l1->next;   // move next of l1
            }
            else
            {                    // if head->val not less than x
                l2->next = head; // put in l2->next      0->4->3->5->NULL
                l2 = l2->next;   // move l2->next
            }

            head = head->next; // iterating over the ll
        }
        l1->next = list2->next; // first element of list2 is 0 so we have to put 4 3 5 so putting next of list2
        l2->next = NULL;
        return list1->next; // return  1->2->2->4 >2->5->NULL  so we call next of list1
    }
};