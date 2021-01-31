package Java_210129;

import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
            String string = in.next();
            char[] chars=string.toCharArray();
            for (int i = 0; i < chars.length; i++) {
                int count = 0;
                for (int j =i; j>-1; j--) {
                    if (chars[i] == chars[j]) {
                        count++;
                    }
                }
                if (count==1) {
                    System.out.print(chars[i]);
                }
            }
        }
    }
}

