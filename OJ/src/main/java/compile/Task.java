package compile;

import util.FileUtil;

import java.io.File;
import java.io.IOException;
import java.util.UUID;

//用这个类表示一个完整的编译运行过程
public class Task {
    //此处罗列出需要的临时文件（主要用于进程间通信）文件名约定
    //所有的临时文件都要放到这个目录中
    private  String WORK_DIR ;
    //要编译执行的类的名字
    private  String CLASS = "Solution";
    //要编译执行的文件名
    private  String CODE ;
    //程序标准输出放置的文件
    private  String STDOUT ;
    //程序标准错误放置的文件
    private  String STDERR ;
    //程序编译出错的详细放置文件
    private  String COMPILE_ERROR ;

    public Task(){
        //先生成唯一的id，根据这个id来拼装出目录的名字
        WORK_DIR = "./tmp/"+ UUID.randomUUID().toString()+"/";
        //然后在生成后续的这些文件名
        CODE = WORK_DIR+CLASS+".java";
        //程序标准输出放置的文件
        STDOUT = WORK_DIR+"stdout.txt";
        //程序标准错误放置的文件
        STDERR = WORK_DIR+"stderr.txt";
        //程序编译出错的详细放置文件
        COMPILE_ERROR = WORK_DIR+"compile_error.text";
    }
    //Question表示用户提交的代码
    //Answer表示代码运行的结果
    public Answer compileAndRun (Question question) throws IOException, InterruptedException {
        Answer answer=new Answer();
        //0.给这些临时文件准备一个目录
        //判断work-dir是否存在，如果存在就跳过，不存在就创建目录
        File file = new File(WORK_DIR);
        if (!file.exists()){
            //创建对应的目录
            file.mkdirs();
        }
        //1.先要准备好需要用的的临时文件
        //  要编译源代码的文件
        //  编译出错的文件
        //  最终运行的标准输出，标准错误也要分别放入文件中
        FileUtil.writeFile(CODE,question.getCode());
        //2.构造编译指令（javac），并进行执行，与其得到的结果
        //  就是一个对应的.class文件，以及编译出错的文件
        // javac -encoding utf-8 ./tmp/Solution.java -d ./tmp/
        //-d 表示指定放置生成的文件位置
        //        String compileCmd = "javac -encoding utf-8"+CODE+" -d" + WORK_DIR;
        //        String.format 类似于c中的sprintf
        String compileCmd = String.format("javac -encoding utf-8 %s -d %s",CODE,WORK_DIR);
        System.out.println("编译命令"+compileCmd);
        //此处不关心javac的标准输出，只关心标准错误
        CommandUtil.run(compileCmd,null,COMPILE_ERROR);
        //判断一下COMPILE_ERROR是否为空，为空说明不出错
        String compileError = FileUtil.readFile(COMPILE_ERROR);
        if (!compileError.equals("")){
            //编译文件不为空，说明编译出错了
            answer.setErrno(1);
            answer.setReason(compileError);
            return answer;
        }
        //3.构造运行指令（java），并进行执行，预期的到的结果
        //就是为了这个代码的标准输出的文件和标准错误的文件
        //为了让java命令找到.class文件的位置，还需要加上一个
        //-classpath 通过这个选项来执行.class文件那个目录里面
        String runCmd = String.format("java -classpath %s %s",WORK_DIR,CLASS);
        System.out.println("runCmd: "+runCmd);
        CommandUtil.run(runCmd,STDOUT,STDERR);
        //尝试读取运行出错的信息，如果抛出异常就从调用栈的信息
        String runError = FileUtil.readFile(STDERR);
        if (!runError.equals("")){
            //编译文件不为空，说明编译出错了
            answer.setErrno(2);
            answer.setReason(runError);
            return answer;
        }
        //  就是这个代码的标准输出的文件和标准错误的文件
        //4.把最终结果构造Answer对象,并返回
        answer.setErrno(0);
        String runStdout = FileUtil.readFile(STDOUT);
        answer.setStdout(runStdout);
        return answer;
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        Task task = new Task();
        Question question = new Question();
        question.setCode("public class Solution {\n" +
                "    public static void main(String[] args) {\n" +
                "        System.out.println(\"hello world\");\n" +
                "    }\n" +
                "}");
        Answer answer =task.compileAndRun(question);
        System.out.println(answer);
    }
}
