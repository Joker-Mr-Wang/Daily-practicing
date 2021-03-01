class Solution {
   
    public boolean isLongPressedName(String name, String typed) {
      
      if(name.length()>typed.length()){
          return false;
      }
      int i=0;
      int j=0;
      while(j<typed.length()){
          //i<name.length()若二者相等，则都往后走一位
          if(i<name.length()&&name.charAt(i)==typed.charAt(j)){
              i++;
              j++;
              //如果不等，看看typed是否与前一个相等
          }else if(j>0&&(typed.charAt(j)==typed.charAt(j-1))){
              j++;
              //都不等，直接返回false；
          }else{
              return false;
          }
      }
      //判断循环是不是因为将name遍历完全才结束
      return (i==name.length());
    }
}
