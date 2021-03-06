/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
 //判断两个的链表是否有重合的值，如果有则说明是相交，没有则说明不相交
public class Solution {
    public int getLength(ListNode cur){
        int length = 0;
        for(ListNode node=cur;cur!=null;cur=cur.next){
            length++;
        }
        return length;
    }
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode cur1 = headA;
        ListNode cur2 = headB;
         if(cur1==null||cur2==null){
            return null;
        }
        int len1=getLength(cur1);
        int len2=getLength(cur2);
        if(len1>len2){
            int steps = len1-len2;
            for(int i = 0;i<steps;i++){
                cur1=cur1.next;
            }
        }else{
            int steps = len2-len1;
            for(int i = 0;i<steps;i++){
                cur2=cur2.next;
            }
        }
        //A,或b为空
       
        while(cur1!=null&&cur2!=null){
           if(cur1==cur2){
               return cur1;
           }
           cur1=cur1.next;
           cur2=cur2.next;
        }
        return null;
    }
}
