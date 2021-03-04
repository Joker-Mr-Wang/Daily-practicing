class Solution {

   public int compress(char[] chars) {
       //利用StringBuilder来保存结果     
        StringBuilder sb = new StringBuilder();
        int i = 0;
        for (;i < chars.length;i++) {
            //设置一个计数器count，用来表示重复数字的个数
            int count = 1;
            //让i与i+1比较，如果二者相等则count++；
            while (i < chars.length - 1  && chars[i] == chars[i + 1]) {
                i++;
                count++;
            }
            //当count只有一个时，只输出字符
            if (count == 1) {
                sb.append(chars[i]);
                //当count>1时，输出字符及所含个数
            } else if (count > 1) {
                sb.append(chars[i]);
                sb.append(count);
            }  
        }
        char[] newChars = sb.toString().toCharArray();
        //将新数组的内容放回原数组中
        for (int j = 0; j < newChars.length ; j++) {
            chars[j] = newChars[j];
        }
        return newChars.length;
    }
}
