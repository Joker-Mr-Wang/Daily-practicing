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
    public ListNode detectCycle(ListNode head) {
        //快慢指针
       ListNode slow = head;
       ListNode fast = head;
    while(fast!=null&&fast.next!=null){
        //fast走两步，last只走一步
        fast=fast.next.next;
        slow=slow.next;
        if(fast==slow){
            break;
        }
    }
    //若返回空，则表示是不带环的
    if(fast==null||fast.next==null){
        return null;
    }
    //如果带环，则找出入环的第一个结点
    //从链表头和相重合位置到环的第一个结点位置是相同的
    ListNode cur1 =head;
    ListNode cur2 =fast;
    while(cur1!=cur2){
        cur1=cur1.next;
        cur2=cur2.next;
    }
    return cur1;
    }
}
