package Java_201208;

import java.util.Scanner;

//��ӡ����
public class FindPrimeNumber {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("��������Ҫ�жϵ�����");
        int num =input.nextInt();
        if (num==1){
            System.out.println("��������");
            System.exit(0);
        }
            int tmp=0;//����һ��������
            for (int j = 1; j <=(int)Math.sqrt(num) ; j++) {
                if ((num%j==0)){
                    tmp++;//����������ʱͳ�ƽ��
                }
            }
            if (tmp==1){//�������ֻ�ܱ�1��������������������
                System.out.print(num+"������");//������
            }
            else{
                System.out.println(num+"��������");
            }
        }

    }
