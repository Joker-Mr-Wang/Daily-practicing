class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        if(arr.length<3){
            return false;
        }
        int sum=0;
        //去整个数组的值
      for(int i=0;i<arr.length;i++){
        sum+=arr[i];        
      }
      //如果这个数组除三除不开，直接返回false；
      if(sum%3!=0){
          return false;
      }
      //tmp是三分之一
      int tmp=sum/3;
      int i=0;
      int num= 0;
      //设置两个指针，一个从前往后走，一个从后往前
      //当前面累加到等于tmp时，返回i的值
       for(;i<arr.length;i++){ 
           num+=arr[i];
        if(num==tmp){
            break;
        }        
      }
      //当后面累加到等于tmp时，返回j的值
       int j=arr.length-1;
       int num1= 0;
       for(;j>=0;j--){
           num1+=arr[j];
        if(num1==tmp){
            break;
        }        
      }
      //如果i+1的值大于或等于j，则说明无法分成三等分
      if(i+1>=j){
          return false;
      }
    //可以分成三等分
      return true;
      
    }
}
