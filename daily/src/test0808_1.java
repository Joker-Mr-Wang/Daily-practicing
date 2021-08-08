import java.util.Scanner;

public class test0808_1 {
//    Fibonacci数列是这样定义的：
//    F[0] = 0
//    F[1] = 1
//    for each i ≥ 2: F[i] = F[i-1] + F[i-2]
//    因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。
//    给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
//    输入描述:
//    输入为一个正整数N(1 ≤ N ≤ 1,000,000)
//    输出描述:
//    输出一个最小的步数变为Fibonacci数"
//    输入15
//    输出2
public static void main(String[] args) {
    Scanner scanner=new Scanner(System.in);
    while (scanner.hasNext()){
        int i = scanner.nextInt();
        int l1 = 0;
        int l2 = 1;
        int l3 = 0;
        //找到比i大的那个斐波那契数
        while (l2<i){
            l3=l1;
            l1=l2;
            l2=l1+l3;
        }
        //比较i前后两个斐波那契数谁距离i近
        //Math.abs求绝对值
        if (Math.abs(l1-i)<Math.abs(l2-i)){
            System.out.println(Math.abs(l1-i));
        }else {
            System.out.println(Math.abs(l2-i));
        }
    }
}
}
