class MyQueue {
    Stack<Integer> A = new Stack<>();
    Stack<Integer> B = new Stack<>();
    /** Initialize your data structure here. */
    public MyQueue() {
   
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
    //入队列
    while(!B.isEmpty()){
        int tmp = B.pop();
        A.push(tmp);
    }
    A.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
      if(A.isEmpty()&&B.isEmpty()){
          return 0;
      }
      while(!A.isEmpty()){
          int tmp = A.pop();
          B.push(tmp);
      }
      //删除b中元素
      return B.pop();
    }
    
    /** Get the front element. */
      public int peek() {
        if (A.isEmpty() && B.isEmpty()) {
            return 0;
        }
        while (!A.isEmpty()) {
            int tmp = A.pop();
            B.push(tmp);
        }
        // 删除 B 中的元素
        return B.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return A.isEmpty() && B.isEmpty();
    }

}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
