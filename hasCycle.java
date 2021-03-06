/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        //快慢指针
        ListNode fast =head;
        ListNode slow =head;
        //快指针走两步,慢指针只走一步
        while(fast!=null&&fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
           if(fast==slow){
               return true;
           }
        }
        return false;
    }
}
