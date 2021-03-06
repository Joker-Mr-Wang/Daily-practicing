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
    //获取链表长度
    public int getLength(ListNode head) {
        int length = 0;
        for (ListNode cur = head; cur != null; cur = cur.next) {
            length++;
        }
        return length;
    }
    
    public boolean chkPalindrome(ListNode A) {
        //链表为空
    if(A==null){
        return true;
    }
    //链表内只有一个元素
        if(A.next==null){
            return true;
        }
    //1找到中间节点
        int length = getLength(A);
        int steps = length/2;
        ListNode B = A;
        for(int i = 0;i< steps ; i++){
            B=B.next;
        }
        //B已经移动到中间节点
        //将B后面的链表进行翻转
        ListNode prev = null;
        ListNode cur = B;
        while(cur!=null){
            ListNode next = cur.next;
            if(next==null){
                B=cur;
            }
        //链表逆置
            cur.next=prev;
            //更新结果
            prev=cur;
            cur=next;
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
