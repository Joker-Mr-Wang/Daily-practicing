package Java_201208;

import java.util.Scanner;

//打印素数
public class FindPrimeNumber {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("请输入您要判断的数字");
        int num =input.nextInt();
        if (num==1){
            System.out.println("不是质数");
            System.exit(0);
        }
            int tmp=0;//设置一个计数器
            for (int j = 1; j <=(int)Math.sqrt(num) ; j++) {
                if ((num%j==0)){
                    tmp++;//当可以整除时统计结果
                }
            }
            if (tmp==1){//当这个数只能被1和它本身整除则是质数
                System.out.print(num+"是质数");//输出结果
            }
            else{
                System.out.println(num+"不是质数");
            }
        }

    }
