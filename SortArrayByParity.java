class Solution {
    //1偶数除二可以除尽，奇数除不尽
    //2设置两个指针，如果是偶数则放在前面，i++
    //3如果是奇数，放在后面j--
    public int[] sortArrayByParity(int[] A) {
         if(A==null){
             return null;
         }
         int i= 0;
         int j =A.length-1;
         int[] res=new int[A.length];
         for(int num =0;num<A.length;num++){
             if(A[num]%2==0){
                 res[i]=A[num];
                 i++;
             }else{
                 res[j]=A[num];
                 j--;
             }
         }
         return res;
    }
}
