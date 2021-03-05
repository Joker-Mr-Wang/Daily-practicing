/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        //判断两个链表是为空
        if(l1==null){
            return l2;
        }
        if(l2==null){
            return l1;
        }
        //两个链表都不是空
        ListNode cur1 = l1;
        ListNode cur2 = l2;
        //创建一个带傀儡结点的链表用于插入输出元素
        ListNode newList = new ListNode(0);
        ListNode tail = newList;
        //依次遍历两个数组，寻找较小值插入新链表中
        while(cur1!=null&&cur2!=null){
            if(cur1.val>cur2.val){
                //cur2的数值较小，移动cur2，cur1不动，
                ListNode node = new ListNode(cur2.val);
                tail.next=node;
                 //更新cur2的值
                cur2=cur2.next;
            }else{
                ListNode node = new ListNode(cur1.val);
                tail.next=node;
                //更新cur1的值
                cur1=cur1.next;
            }
            tail=tail.next;
         
          
        }
        //判断cur1链表是否遍历完，如果遍历完，将cur2剩余元素放在后面
        if(cur1==null){
            tail.next=cur2;
        }else{
           tail.next=cur1; 
        }
          //因为是带傀儡节点的链表，所以返回next才是真实值
    return newList.next;
    }
}
  
