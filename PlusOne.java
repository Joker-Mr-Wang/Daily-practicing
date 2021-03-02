class Solution {
    public int[] plusOne(int[] digits) {

        int len_d=digits.length;
        int i =len_d-1;
        //从后往前数，判断整个数组是不是都是由9组成
        for(;i>=0;i--){
            if(digits[i]!=9){
                break;
            }
        }
        //数组全都是9，数组需要扩容
        if(i==-1){
            digits=new int[len_d+1];
            int tmp = digits[0];
            digits[0]=1;
            digits[len_d]=tmp;
            //数组里面有i个9，则在第i的前一位加1并将后面的9都变成0
        }else if(i>=0&&i<len_d){
            digits[i]+=1;
            for(int j=i+1;j<len_d;j++){
                digits[j]=0;
            }
            //其他情况下，直接在个位+1；
        }else{
           digits[len_d-1]=digits[len_d-1]+1;
        }
       return digits;
    }
}
