package Java_201208;
//1到 100 的所有整数中出现多少个数字9
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
        System.out.println("1到 100 的所有整数中出现"+res+"个数字9");

    }
}
