class Solution {
       //建立一个排好序的数组，
     //将二者一一比对，找到不相等的两个位置记为min和max
     //之后将原数组中下标[min,max]的数组重新进行排序，并返回
    public int findUnsortedSubarray(int[] nums) {
     //克隆复制一个新数组，将其排序
     int[] sortNums=nums.clone();
     Arrays.sort(sortNums);
     int i = 0;
     int j = nums.length-1;
     for(; i<nums.length;i++){
         if(sortNums[i]!=nums[i]){
             break;
        }
     }
       for(; j>=0;j--){
         if(sortNums[j]!=nums[j]){
             break;
        }
     }

    if(j-i<0){
         return 0;
    }
     return j-i+1;
    }
}
