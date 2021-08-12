public class test0811_1 {
    //输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。
    // 求所有子数组的和的最大值。要求时间复杂度为 O(n).
//    输入：[1,-2,3,10,-4,7,2,-5]
//    返回值：18
//    说明：
//    输入的数组为{1,-2,3,10,—4,7,2,一5}，和最大的子数组为{3,10,一4,7,2}，
//    因此输出为该子数组的和 18。
    public class Solution {
        public int FindGreatestSumOfSubArray(int[] array) {
            //设置一个arrMax数组保存每一个子数组的最大值
            int[] arrMax =new int[array.length];
            arrMax[0]=array[0];
            //每个子数组的最大值要么是它前一项的最大值加本身，要么就是它本身。
            for(int i =1;i<array.length;i++){
                arrMax[i]=Math.max(arrMax[i-1]+array[i],array[i]);
            }
            //寻找子数组最大值数组中最大的值并返回
            int res=arrMax[0];
            for(int i =1;i<arrMax.length;i++){
                res=Math.max(res,arrMax[i]);
            }
            return res;
        }
    }
}
