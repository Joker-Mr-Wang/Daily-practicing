class Solution {
    //设置两个指针，i在前，j在后，遍历整个字符串
    //若前面是字母，后面也是字母，二者交换，之后i++，j--
    //如果前面不是字母则i++；
    //如果后面不是字母则j--；
    //当i>=j时则结束遍历
    //Character.isLetter(char):判断char是不是字母
    public String reverseOnlyLetters(String S) {
      char[] chars =S.toCharArray();
      int i = 0;
      int j = chars.length-1;
      while(i<j){
          //如果前面不是字母则i++；
          if(!Character.isLetter(chars[i])){
              i++;
          }
          //如果后面不是字母则j--；
          if(!Character.isLetter(chars[j])){
              j--;
          }
        //若前面是字母，后面也是字母，二者交换，之后i++，j--
          if(Character.isLetter(chars[i])&&          Character.isLetter(chars[j])){
              char tmp =chars[i];
              chars[i]=chars[j];
              chars[j]=tmp;
              i++;
              j--;
        }
      }
      return new String(chars);
    }
}
