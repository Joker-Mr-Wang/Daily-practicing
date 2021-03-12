class Solution {
    public boolean isValid(String s) {
//先创建一个栈
        Stack<Character> stack = new Stack<>();
        //遍历字符串
        for(int i = 0;i<s.length();i++){
            char c = s.charAt(i);
            //如果遇到左括号，就需要入栈
            if(c=='('||c=='['||c=='{'){
                stack.push(c);
                continue;
            }
            
            //如果栈为空直接返回false；
            if(stack.isEmpty()){
                return false;
            }
            //取栈顶元素进行匹配
            Character top = stack.pop();
            if(top == '('&&c==')'){
                continue;
            }
              if(top == '['&&c==']'){
                continue;
            }
              if(top == '{'&&c=='}'){
                continue;
            }
            //如果三种都匹配不上，则返回false；
            return false;
        }
        //循环结束，看看栈内是否还有元素，没有则返回ture；
        if(stack.isEmpty()){
            return true;
        }
        return false;
    }
}
