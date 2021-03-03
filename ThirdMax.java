class Solution {
    //1.
    public int thirdMax(int[] nums) {
    Arrays.sort(nums);
    int len_n=nums.length;
    //如果数组长度小于3，则直接输出最大的数
    if(len_n<3){
        return nums[len_n-1];
    }
    //长度大于3
    int count=0;
    int i = len_n-1;
    //从后往前找，找第三大的数
    for(;i>0;i--){
        if(nums[i]!=nums[i-1]){
            count++;
        }
        if(count==2){
            break;
        }
    }
    //如果没找到第三大的数就返回最大值
    if(count==2){
         return  nums[i-1];
     
    }else{
          return nums[len_n-1];
    }
    }
}
