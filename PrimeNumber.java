package Java_201208;
//��ӡ 1 - 100 ֮�����е�����
public class PrimeNumber {
    public static void main(String[] args) {
        for (int i = 2; i <101 ; i++) {//��1-100������
            int tmp=0;//����һ��������
            for (int j = 1; j <=(int)Math.sqrt(i) ; j++) {
                if ((i%j==0)){
                    tmp++;//����������ʱͳ�ƽ��
                }
            }
            if (tmp==1){//�������ֻ�ܱ�1������������
                System.out.print(i+" ");//������
            }
        }
    }

}
