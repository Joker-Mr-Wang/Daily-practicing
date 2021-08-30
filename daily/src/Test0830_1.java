/**
 * 给你一个整数数组 arr，请你判断数组中是否存在连续三个元素都是奇数的情况：如果存在，请返回 true ；否则，返回 false 。
 *
 *
 * 输入：arr = [2,6,4,1]
 * 输出：false
 * 解释：不存在连续三个元素都是奇数的情况。
 *
 */
public class Test0830_1 {
    class Solution {
        public boolean threeConsecutiveOdds(int[] arr) {
            //1.数组长度大于3
            if(arr.length<3){
                return false;
            }
            int tmp = 0;
            //2.循环遍历数组
            for(int i = 0;i<arr.length;i++){
                //3.是奇数就tmp++并继续往后判断,偶数就清零
                if(arr[i]%2==1){
                    tmp++;
                }else{
                    tmp=0;
                }
                //4.当tmp==3时，返回true，否则返回false；
                if(tmp==3){
                    return true;
                }
            }
            return false;
        }
    }
}
