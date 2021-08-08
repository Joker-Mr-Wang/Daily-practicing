public class test0807_1 {
//    输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
//    输入
//    {1,3,5},{2,4,6}
//    输出
//    {1,2,3,4,5,6}
    public class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }
    public class Solution {
        public ListNode Merge(ListNode list1,ListNode list2) {
            //判断这个两个链表是否存在空
            if (list1==null){
                return list2;
            }
            if (list2==null){
                return list1;
            }
            //建立一个新链表
            ListNode head = null;
            ListNode tail = null;
            //二者都不为空
            while (list1!=null&&list2!=null){
                if (list1.val>=list2.val){
                    //判断新链表里面是否有元素
                    if (head==null){
                        head =tail=list2;
                    }else {
                        tail.next=list2;
                        //更新尾部
                        tail=tail.next;
                    }
                    //更新list2
                    list2=list2.next;
                }else {
                    if (head==null){
                        head =tail=list1;
                    }else {
                        tail.next=list1;
                        //更新尾部
                        tail=tail.next;
                    }
                    //更新list2
                    list1=list1.next;
                }
            }
            //当某一个链表已经为空时就把剩余元素链到新链表尾部
            if (list1==null){
               tail.next=list2;
            }
            if (list2==null){
                tail.next=list1;
            }
            return head;
        }
    }

}
