public class test0810_1 {
//    一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶(n为正整数)总共有多少种跳法。
//    输入：     3
//    返回值：    4
public class Solution {
    public int jumpFloorII(int target) {
//        if(target==0){
//            return 0;
//        }
//        return 1 <<(target-1);
        int res=1;
        for (int i = 2; i <=target; i++) {
            res*=2;
        }
        return res;
    }
}
}
