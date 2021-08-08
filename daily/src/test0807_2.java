public class test0807_2 {
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
            public ListNode Merge(ListNode list1, ListNode list2) {
                //判断这个两个链表是否存在空
                //递归版本
                if (list1==null){
                    return list2;
                }
                if (list2==null){
                    return list1;
                }
                //当list的值比list2小时，我们就用list.next和list2进行比较
                //从而找到最大的值放在最后面
                if (list1.val<=list2.val){
                    list1.next=Merge(list1.next,list2);
                    //当找到list.next的值后返回list1确保下一个链可以继续进行
                    return list1;
                }else {
                    list2.next=Merge(list1,list2.next);
                    return list2;
                }
            }
        }
}
