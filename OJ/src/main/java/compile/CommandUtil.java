package compile;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class CommandUtil {
    //run方法就用于进行创建进程并执行命令
    //cmd 表示要执行的名领，比如javac
    //stdoutFile制定标准输出写道哪个文件
    //stderrFile表示标准错误写到那个文件
    public static int run(String cmd,String stdoutFile,
                          String stderrFile) throws IOException, InterruptedException {
        //使用runtime这样的类完成进程的创建
        //runtime在使用是不需要创建新实例，而是使用线程有的实例就可以了
        //runtime的实例只有唯一一个，是单例模式
        //这个process对象其实就是用来表示你新创建出来的这个进程
        Process process=Runtime.getRuntime().exec(cmd);
        //通过exec这个方法生成的进程就是新进程
        //正在执行exec这个方法的进程就是旧进程
        //当新的进程跑起来之后，就需要获取新的进程的输出结果
        if (stdoutFile !=null) {
            //getInputStream 得到的是标准输出
            InputStream stdoutFrom = process.getInputStream();
            //通过这个对象就可以去读取到当前新进程的标准输出的内容
            FileOutputStream stdoutTo=new FileOutputStream(stdoutFile);
            //接下来就从新进程这边一次读取每个字节,把stdoutFrom放入stdoutTo
            while (true){
                int ch= stdoutFrom.read();
                if (ch==-1){
                    break;
                }
                stdoutTo.write(ch);
            }
            //文件读写完毕
            stdoutFrom.close();
            stdoutTo.close();
        }
        //针对标准错误进行重定向
        if (stderrFile!=null){
            //得到的是标准错误
            InputStream stderrFrom = process.getErrorStream();
            FileOutputStream stderrTo = new FileOutputStream(stderrFile);
            //写入
            while (true){
                int ch= stderrFrom.read();
                if (ch==-1){
                    break;
                }
                stderrTo.write(ch);
            }
            //文件读写完毕
            stderrFrom.close();
            stderrTo.close();
        }
        //等待新进程结束，并获取到新进程的退出码
        int exitCode=process.waitFor();
        return exitCode;
    }

    public static void main(String[] args) {
        try {
            int ret=CommandUtil.run("javac","./stdout.txt","./stderr.txt");
            System.out.println(ret);
        } catch (IOException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
