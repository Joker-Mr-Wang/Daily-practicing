package Java_201208;

public class LeapYear {
    //1000-2000������
    public static void main(String[] args) {
        for (int i = 1000; i <=2000 ; i++) {
            if(i%100==0){
                //��������
                if (i%400==0){
                    System.out.println( i );
                }
            }else{
                //��ͨ����
                if (i%4==0){
                    System.out.println( i );
                }
            }
        }
    }
}
