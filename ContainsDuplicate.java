class Solution {
    //遍历数组，进行比较
    public boolean containsDuplicate(int[] nums) {
        //将数组重新排序
        Arrays.sort(nums);
        //若存在相同元素，则必定相邻
      for(int i = 0; i<nums.length-1;i++){
              if(nums[i]==nums[i+1]){
                  return true;
              }
      }
      return false;
    }
}
