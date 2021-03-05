/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
   
    //1，找到链表整个长度
    //2.链长的一般就是全场的一半
     public int listLength(ListNode head){
         int count= 0;
         ListNode cur = head;
         while(cur!=null){
             count++;
             cur=cur.next;
         }
         return count;
     }
    public ListNode middleNode(ListNode head) {
        ListNode cur = head;
        //写一个函数来表示链长
        int len_h = listLength(cur);
        for(int i= 0 ; i<len_h/2;i++){
            cur=cur.next;
        }
        return cur;
    }
    
}
