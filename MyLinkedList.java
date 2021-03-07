package Java_210306;
 class Node{
     int val;
     //一个指向前一个结点
     Node prev=null;
     //一个指向后一个结点
     Node next=null;
     public Node(int v){
         this.val=v;
     }

     @Override
     public String toString() {
         return "Node{" +
                  val +
                 '}';
     }
 }
 //实现双向链表
public class MyLinkedList {
     //记录头结点位置
     private Node head;
     //记录尾节点
     private Node tail;
     //链表的元素个数
     private  int length = 0;
     public  MyLinkedList(){
         //无傀儡节点的链表
         head=null;
         tail=null;
     }

     //链表长度
     public int length(){
         return this.length;
     }
     //插入结点
     //头插
     public void addFirst(int val){
         //将所需插入的值变成一个新节点
        Node newNode = new Node(val);
            //如果链表为空
         if(head == null){
             head = newNode;
             tail = head;
             length++;
             return;
         }
         //链表非空
         //将newNode插入head前面
         //将原有head的前指针指向newNode
         //更新head的引用，改成newNode；
         newNode.next=head;
         head.prev=newNode;
         head=newNode;
         //链长+1；
         length++;

     }
     //尾插
     public void addLast(int val){
       Node newNode = new Node(val);
       //链表为空
         if(head==null){
             head=newNode;
             tail=newNode;
             length++;
         }
         //链表非空
         tail.next=newNode;
         newNode.prev=tail;
         tail=tail.next;
         length++;
     }
     //指定位置插入
     public void add(int index,int val){
       if (index<0||index>length){
           return;
       }
       //如果是头插
         if(index==0){
             addFirst(val);
             return;
         }
         //如果是尾插
         if(index==length){
             addLast(val);
         }
         //其他情况
         Node newNode = new Node(val);
         //需要找到下标对应的节点
         Node nextNode =getNode(index);
         //将val的值插入这个链表当前位置，及相当于前插到这个nextNode结点
         //找到nextNode的前结点prevNode，将newNode插入二者当中
         Node prevNode = newNode.prev;
         //先修改prev.next的指向
         prevNode.next=nextNode;
         newNode.prev=prevNode;
         //在修改。newNode.next的指向
         newNode.next=nextNode;
         nextNode.prev=newNode;
         //数组长度+1
         length++;
     }

     //删除头结点
     public void removeFirst(){
       if (head==null){
           return;
       }
       //删除头结点,链表只有一个结点
       if (head.next==null){
           head=null;
           tail=null;
           length = 0;
           return;
       }
       //删除头结点，有多个元素
         //先找到第二个结点
         Node nextNode = head.next;
         //把第二个结点，前一个指向空
         nextNode.prev = null;
         //将head引用指向nextNode；
         head=nextNode;
         //减少链表长度
         length--;

     }

     //删除尾结点
     public void removeLast() {
         if (head==null){
             return;
         }
         if (head.next==null){
             head=null;
             tail=null;
             length = 0;
             return;
         }
         //先找到倒数第二个结点
         Node prevNode = tail.prev;
         prevNode.next=null;
         tail=prevNode;
         length--;
     }

     //删除结点(按照位置进行删除)
     public void removeByIndex(int index) {
         if (index<0||index>=length){
             return;
         }
         //如果删除的是头结点
         if(index==0){
             removeFirst();
             return;
         }
         //删除尾结点
         if (index==length){
             removeLast();
             return;
         }
         //找到删除结点
         Node toRemove=getNode(index);
         //记录删除前后结点
         Node prevNode = toRemove.prev;
         Node nextNode = toRemove.next;
         //删除节点
         prevNode.next=nextNode;
         nextNode.prev=prevNode;
         length--;
     }

     //删除结点（按照元素内容进行删除）
     public void removeByValue(int val) {
         int index = indexOf(val);
         //没找到
         if (index==-1){
             return;
         }
         removeByIndex(index);

     }

     // 根据下标找到节点
     public Node getNode(int index) {
         if (index<0||index>=length){
             return null;
         }
         Node cur =head;
         for (int i=0;i<index;i++){
             cur=cur.next;
         }
         return cur;
     }

     //查找--(返回值)
     public int get(int index){
         if (index<0||index>=length){
             throw new ArrayIndexOutOfBoundsException();
         }
        return getNode(index).val;

     }
     //查找返回索引
     public int indexOf(int val){
         Node cur=head;
         for (int i = 0;i<length;i++ ){
             if (cur.val==val){
                 return i;
             }
             cur=cur.next;
         }
         return -1;
     }

     //修改
     public void  set(int index,int value){
         if (index<0||index>=length){
             return ;
         }
         Node cur=getNode(index);
         cur.val=value;

     }

     //创捷链表
     public static Node createNode(){
         Node a = new Node(1);
         Node b = new Node(2);
         Node c = new Node(3);
         Node d = new Node(4);
         Node e = new Node(5);
         a.next=b;
         b.next=c;
         c.next=d;
         d.next=e;
         e.next=null;
         e.prev=d;
         d.prev=c;
         c.prev=b;
         b.prev=a;
         a.prev=null;
         return a;
     }
     private static void printNode(Node head) {
         Node cur = head;
         for (;cur!=null;cur=cur.next){
             System.out.println(cur);
         }
     }
     public static void main(String[] args){
              Node head=createNode();
              printNode(head);
     }



 }
