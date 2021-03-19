import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        //输入数字及符号
        while(scanner.hasNext()){
            int N = scanner.nextInt();
            String s = scanner.next();
            //特殊用例1
             if(N==1){
                System.out.println(s);
                System.out.println(0);
                 continue;
            }
            //常规情况
        //计算层数
        int row = 0;
        int tmp = (N+1)/4;
            while((N+1)/2<(tmp*tmp)){
                tmp--;
            }
        //此时得到最大的行数,和剩余的个数
        row=tmp;
        int more = N-2*tmp*tmp+1;
        //开始打印字符
           //打印上半部分
        for(int i = 0; i<row;i++){
            for(int k = 0;k<i;k++){
                System.out.print(" ");
            }
            for(int j = 0;j<2*(row-i)-1;j++){
                System.out.print(s);
            }
            System.out.println();
        }
            //打印下半部分
        for(int i = 1; i<row;i++){
            for(int k = 0;k<row-1-i;k++){
                System.out.print(" ");
            }
            for(int j = 0;j<2*(i+1)-1;j++){
                System.out.print(s);
            }
            System.out.println();
        }
        System.out.println(more);    
    }
    }
}
