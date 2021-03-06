import java.util.*;

/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
//
public class PalindromeList {
    public boolean chkPalindrome(ListNode A) {
        //链表为空
    if(A==null){
        return true;
    }
    //链表内只有一个元素
        if(A.next==null){
            return true;
        }
    //复制一遍之前链表
        ListNode newHead = new ListNode(0);
        ListNode newTail = newHead;
        for(ListNode cur = A;cur!=null;cur=cur.next){
            newTail.next=new ListNode(cur.val);
            newTail=newTail.next;
        }
        //用B保存复制过后的链表
        ListNode B = newHead.next;
        //将新链表逆置
        ListNode prev = null;
        ListNode cur = B;
            while(cur!=null){
                ListNode next = cur.next;
                if(next==null){
                    //如果cur是最后一个结点，则把这结点作为逆置后的头节点
                    B=cur;
                }
                //链表逆置
                cur.next=prev;
                //更新循环遍历
                prev = cur;
                cur = next;
            }
            //判断A，B两个链表是否相等
         ListNode cur1 = A;
         ListNode cur2 = B;
        while(cur1!=null&&cur2!=null){
            //有不相等里数组，。说明不是回文
            if(cur1.val!=cur2.val){
                return false;
            }
            cur1=cur1.next;
            cur2 = cur2.next;
        }
        //如果没有给都相等，则证明是回文
        return true;
         

    }
}
