import java.util.Scanner;

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
