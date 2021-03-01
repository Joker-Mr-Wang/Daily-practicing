class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        //num代表nums1数组的长度
    int num=m+n;
         while(m>0&&n>0){
          if(nums1[m-1]>nums2[n-1]){
         nums1[num-1]=nums1[m-1];
          m--;
        }else{
         nums1[num-1]=nums2[n-1];
           n--; 
        }
         num--;   
    }
     //如果有剩余元素，将剩余元素直接放入数组中
    while(n>0){
        nums1[num-1]=nums2[n-1];
        n--;
        num--;
        }
    }
}
