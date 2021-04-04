import java.util.Scanner;

public class Test1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()){
            int N = scanner.nextInt();
            int res = fibonacciNum(N);
            System.out.println(res);
       }
    }

    private static int fibonacciNum(int n) {
        int res=0;
        int res1=0;
        int num1=0;
        int num2=1;
        while (res>=res1){
            res=n-num1;
            res1=n-num2;
            int tmp=num2;
            num2=num1+num2;
            num1=tmp;
            if (res1<0){
                res1=0-res1;
            }
            if (res<0){
                res=0-res;
            }
        }
       return res;
    }
}
