class Solution {
    //设置两个指针，一个从前往后，一个从后往前
    //找到了就返回二者的下标
    //最终判断是否找到(i>j坐标时，则没有找到)
    public int[] searchRange(int[] nums, int target) {
       if(nums==null||nums.length==0){
          return new int[]{-1,-1};
       }
       int i = 0;
       int j = nums.length-1;
       for(;i<nums.length;i++){
            if(nums[i]==target){
            break;
           }
        }
        for(;j>=0;j--){
            if(nums[j]==target){
            break;
           }
        }
        //判断是否找到
        if(i>j){
           return new int[]{-1,-1};
        }
        return new int[]{i,j};
    }
}
