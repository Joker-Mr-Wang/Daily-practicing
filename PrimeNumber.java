package Java_201208;
//打印 1 - 100 之间所有的素数
public class PrimeNumber {
    public static void main(String[] args) {
        for (int i = 2; i <101 ; i++) {//在1-100里面找
            int tmp=0;//设置一个计数器
            for (int j = 1; j <=(int)Math.sqrt(i) ; j++) {
                if ((i%j==0)){
                    tmp++;//当可以整除时统计结果
                }
            }
            if (tmp==1){//当这个数只能被1整除则是质数
                System.out.print(i+" ");//输出结果
            }
        }
    }

}
