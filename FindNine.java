package Java_201208;
//1�� 100 �����������г��ֶ��ٸ�����9
public class FindNine {
    public static void main(String[] args) {

        int res=0;
        for (int i = 1; i <=100 ; i++) {
            if ((i/10)==9){//
                res++;
            }
            if ((i%10)==9){
                res++;
            }
        }
        System.out.println("1�� 100 �����������г���"+res+"������9");

    }
}
