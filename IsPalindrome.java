class Solution {
    //1将字符串中的字母和数字提出来形成一个新字符串
    //2利用StringBuffer里面的reverse()方法，反转字符串
    //3比较反转后的字符串和原字符串是否相等
    //用equalsIgnoreCase()进行比较，不区分大小写
    public boolean isPalindrome(String s) {
        //建立一个字符串缓冲区sbd用于修改字符串
    StringBuilder sbd = new StringBuilder();
        //将字母和数字提出来，其余字符串都去除掉
    for(int i = 0;i<s.length();i++){
        if((s.charAt(i)>='0'&&s.charAt(i)<='9')||(s.charAt(i)>='A'&&s.charAt(i)<='Z')||(s.charAt(i)>='a'&&s.charAt(i)<='z')){
            //将符合要求的字符放入缓冲区中
            sbd.append(s.charAt(i));
        }
    }
    //将缓冲区的字符变成新的字符串
        s=sbd.toString();
        //反转字符串得到新的字符串
        String ss = sbd.reverse().toString();
        //如果两个字符串相等（不区分字母大小写）
        if(s.equalsIgnoreCase(ss)){
            //返回true；
            return true;
        }
        //否则，返回false
        return false;
    }
}
