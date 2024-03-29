package api;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import compile.Answer;
import compile.Question;
import compile.Task;
import problem.Problem;
import problem.ProblemDAO;
import util.HttpUtil;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/compile")
public class CompileServlet extends HttpServlet {
    private Gson gson = new GsonBuilder().create();

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 1. 先从 req 对象中读取 body 的数据
        String body = HttpUtil.readBody(req);
        // 2. 把这个 json 数据给转换成请求对象
        CompileRequest compileRequest = gson.fromJson(body, CompileRequest.class);
        // 3. 根据请求中的题目 id , 查询数据库, 获取到测试用例代码
        ProblemDAO problemDAO = new ProblemDAO();
        Problem problem = problemDAO.selectOne(compileRequest.getId());
        // testCode 就是当前这个题目的测试代码
        String testCode = problem.getTestCode();
        // 4. 把用户提交的代码和测试用例代码拼接在一起, 拼接成一个完整的可执行的代码.
        //    requestCode 就表示用户提交的代码
        //    finalCode 就表示用户代码和测试代码拼接好的最终结果代码
        String requestCode = compileRequest.getCode();
        String finalCode = mergeCode(requestCode, testCode);
        // 5. 创建 Task 对象, 借助 Task 对象来编译运行这个代码
        Task task = new Task();
        Question question = new Question();
        question.setCode(finalCode);
        Answer answer = null;
        try {
            answer = task.compileAndRun(question);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        // 6. 把运行结果包装成响应数据, 把数据返回给页面即可
        CompileResponse compileResponse = new CompileResponse();
        compileResponse.setErrno(answer.getErrno());
        compileResponse.setReason(answer.getReason());
        compileResponse.setStdout(answer.getStdout());
        String respString = gson.toJson(compileResponse);
        resp.setStatus(200);
        resp.setContentType("application/json; charset=utf-8");
        resp.getWriter().write(respString);
    }

    private String mergeCode(String requestCode, String testCode) {
        // 1. 先从 requestCode 中找到末尾的 } , 并且截取出前面的代码
        int pos = requestCode.lastIndexOf("}");
        if (pos == -1) {
            return null;
        }
        // 2. 把 testCode 拼接到后面, 并再拼接上一个 } 就好了
        return requestCode.substring(0, pos) + testCode + "}";
    }
}
