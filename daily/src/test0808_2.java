import java.util.HashSet;
import java.util.Scanner;

//    每个输入包含 1 个测试用例。每个测试用例的第 i 行，表示完成第 i 件料理需要哪些材料，
//    各个材料用空格隔开，输入只包含大写英文字母和空格，输入文件不超过 50 行，每一行不超过 50 个字符。
//    输出描述:
//    输出一行一个数字表示完成所有料理需要多少种不同的材料。
//    输入
//    BUTTER FLOUR
//    HONEY FLOUR EGG
//    输出  4
public class test0808_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashSet<String> set = new HashSet();
        while (scanner.hasNext()){
            String str = scanner.nextLine();
            String[] arr = str.split(" ");
            for (int i = 0; i <arr.length; i++) {
                set.add(arr[i]);
            }
        }
        System.out.println(set.size());
    }
}
