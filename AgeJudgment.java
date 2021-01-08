package Java_201208;

import java.util.Scanner;

public class AgeJudgment {
    public static void main(String[] args) {
        //根据输入的年龄, 来打印出当前年龄的人是少年(低于18), 青年(19-28), 中年(29-55), 老年(56以上)

        Scanner input= new Scanner(System.in);
        System.out.println("请输入当年年龄：");
        int year =input.nextInt();
        if(year<19){
            System.out.println("他是少年");
        }else if (year>18&&year<29){
            System.out.println("他是青年");
        }else if (year>28&&year<56){
            System.out.println("他是中年");
        }else{
            System.out.println("他是老年");
        }
    }
}
