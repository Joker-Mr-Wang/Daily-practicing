import java.util.Scanner;
//每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。
public class test0806_1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()){
           String str = scanner.nextLine();
           StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i <str.length(); i++) {
                char tmp = str.charAt(i);
                if (!stringBuilder.toString().contains(tmp+"")){
                    stringBuilder.append(tmp);
                }
            }
            System.out.println(stringBuilder.toString());
        }
    }
}
