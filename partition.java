import java.util.*;

/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Partition {
    public ListNode partition(ListNode pHead, int x) {
        // 如果链表为空
        if(pHead==null){
            return null;
        }
        //如果只有一个结点
        if(pHead.next==null){
            return pHead;
        }
        //有多个结点
        //建立两个链表，一个存放比x小的链表，一个存放比x大的链表。
        ListNode bigHead = new ListNode(0);
        ListNode bigTail = bigHead;
        ListNode smallHead = new ListNode(0);
        ListNode smallTail = smallHead;
        for(ListNode cur = pHead;cur!=null;cur=cur.next){
            ListNode node = new ListNode(cur.val);
            if(cur.val<x){
                smallTail.next=node;
                smallTail=smallTail.next;
            }else{
                bigTail.next=node;
                bigTail=bigTail.next;
            }
        }
        //将两个链表进行拼接
       smallTail.next=bigHead.next;
        //返回链表
       return smallHead.next;
    }
}
