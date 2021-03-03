class Solution {
    public int[] twoSum(int[] nums, int target) {
//设置两个指针，
//不断穷举直至找到结果
//当等于目标值，则返回二者
    for( int head = 0;head<nums.length-1;head++){
        for(int tail =head+1;tail<nums.length;tail++){
            if((nums[head]+nums[tail])==target){
               return new int[]{head,tail};
            }
        }
    }
    return new int[]{0};
    }
}
