class Solution {
    
    public boolean canConstruct(String ransomNote, String magazine) {
            //0将两个字符串都变成字节数组
           char[] char1=ransomNote.toCharArray();
           char[] char2 = magazine.toCharArray();
           //1.遍历第一个数组，把第一个数组中的每一个元素与第二个数组中的值依次比较
           for(int i = 0; i<char1.length;i++){
               int j =0;
               for(;j<char2.length;j++){
                     //2若存在相同元素则判断下一个元素，并将第二个数组该元素变成空，
                   if(char1[i]==char2[j]){
                       char2[j]='A';
                       break;
                   }
               }
                   //3.若存在未找到元素则直接结束循环，返回false
               if(j==char2.length){
                   return false;
               }
           }
             //4.若一直寻找结束，则返回true，证明存在该元素
           return true;
    }
}
