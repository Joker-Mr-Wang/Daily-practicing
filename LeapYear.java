package Java_201208;

public class LeapYear {
    //1000-2000的润年
    public static void main(String[] args) {
        for (int i = 1000; i <=2000 ; i++) {
            if(i%100==0){
                //世纪润年
                if (i%400==0){
                    System.out.println( i );
                }
            }else{
                //普通润年
                if (i%4==0){
                    System.out.println( i );
                }
            }
        }
    }
}
