class Solution {
    //1.将字符串转换成字符数组
    public int lengthOfLastWord(String s) {
        if(" ".equals(s)||s==null){
            return 0;
        }
       char[] cha = s.toCharArray();
       //2，从后往前遍历数组，寻找“ ”
       int num =0;
       for(int i = cha.length-1;i>=0;i--){
           //当找到“ ”且“ ”后面有非空字符，才停止计数
          if(cha[i]==' '&&num!=0){
            break;
            //当字符不是‘’则计数加一
          }else if(cha[i]!=' '){
              num++;
          }
       }
           return num;
    }
}
