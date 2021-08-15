package compile;

import lombok.Getter;
import lombok.Setter;
@Getter
@Setter
//编译运行的结果
public class Answer {
    //运行结果是否正确
    //0表示编译运行ok，1表示编译出错 2表示出现异常
    private int errno;
    //若果出错了，原因是什么
    //errno1，reason包换了编译的错误信息
    //errno2，reason包括了异常调用栈的信息
    private String reason;
    //程序的标准输出
    private String stdout;
    //程序的标准输入
    private String stderr;


    @Override
    public String toString() {
        return "Answer{" +
                "errno=" + errno +
                ", reason='" + reason + '\'' +
                ", stdout='" + stdout + '\'' +
                ", stderr='" + stderr + '\'' +
                '}';
    }
}
