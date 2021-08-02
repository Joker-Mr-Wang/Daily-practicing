package util;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

//使用这个类封装一下Java的文件操作。
//让后面的代码能够更方便的读写整个文件
public class FileUtil {
    //从指定的文件中一次把所有的内容读出来
    public static String readFile(String filePath){
        StringBuilder stringBuilder = new StringBuilder();
        try(FileInputStream fileInputStream= new FileInputStream(filePath)) {
            while (true){
                int ch = fileInputStream.read();
                if (ch==-1){
                    break;
                }
                //read方法只是读到一个字节，我们在读出是还需要将int类型转换成byte类型
              stringBuilder.append((char) ch);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return stringBuilder.toString();
    }


    //把content中的内容一次写入到filePath对应的文件中
    public static void writeFile(String filePath,String content){
        try(FileOutputStream fileOutputStream = new FileOutputStream(filePath)) {
            //进行写文件的操作
            fileOutputStream.write(content.getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
