package problem;

import util.DBUtil;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

//DAO 数据访问对象
//主要是包括一些增删改查的方法，用来操作数据库
//进而进行题目的相关操作。
public class ProblemDAO {
    //往数据库插入一条信息
    public void insert(Problem problem){
        //和数据库建立连接
        Connection connection = DBUtil.getConnection();
        //拼装sql语句
        PreparedStatement statement =null;
        String sql = "insert into oj_table values(null,?,?,?,?,?)";
        try {
            statement = connection.prepareStatement(sql);
            statement.setString(1,problem.getTitle());
            statement.setString(2,problem.getLevel());
            statement.setString(3,problem.getDescription());
            statement.setString(4,problem.getTemplateCode());
            statement.setString(5,problem.getTestCode());
            //3.执行sql
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }finally {
            DBUtil.close(connection,statement,null);
        }

    }
    //从数据库删除一条记录（根据id）
    public void delete(int problemId){
        //1.建立连接
        Connection connection = DBUtil.getConnection();
        //2.拼装sql语句
        PreparedStatement statement =null;
        String sql = "delete from oj_table where id=?";
        try {
            statement = connection.prepareStatement(sql);
            statement.setInt(1,problemId);
            //3.执行sql
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }finally {
            DBUtil.close(connection,statement,null);
        }
    }

    //查找全部题目（用来实现题目到表页）
    //只需要查找Problem的一部分字段即可
    //id title level
    //正常来说，一个系统的“查找全部操作”一般都支持分页查询
    //不分页的话，数据量可能比较大，影响程序的效率。
    //当前并不考虑实现分页查询，后端实现分页是十分容易的
    //SQL中本来就有limit offset 这样的基础支持
    //前端实现分页不好写
    public List<Problem> selectAll(){
        //存放结果集
        List<Problem> problems = new ArrayList<>();
        //1.建立连接
        Connection connection = DBUtil.getConnection();
        //2.拼装sql语句
        String sql = "select id,title,level from oj_table ";
        PreparedStatement statement =null;
        ResultSet resultSet=null;
        try {
            statement = connection.prepareStatement(sql);
            //3.执行sql
            resultSet =statement.executeQuery();
            //4.遍历结果集
            while (resultSet.next()){
                Problem problem = new Problem();
                problem.setId(resultSet.getInt("id"));
                problem.setTitle(resultSet.getString("title"));
                problem.setLevel(resultSet.getString("level"));
//                problem.setDescription(resultSet.getString("description"));
//                problem.setTemplateCode(resultSet.getString("templateCode"));
//                problem.setTestCode(resultSet.getString("testCode"));
                problems.add(problem);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }finally {
            DBUtil.close(connection,statement,resultSet);
        }
        return problems;
    }


    //查找制定题目（用来实现题目详情页）
    //需要把Problem每个字段都查询出来
    public Problem selectOne(int problemId){
        //1.建立连接
        Connection connection = DBUtil.getConnection();
        //2.拼装sql语句
        String sql = "select * from oj_table where id=?";
        PreparedStatement statement =null;
        ResultSet resultSet=null;
        Problem problem = new Problem();
        try {
            statement = connection.prepareStatement(sql);
            statement.setInt(1,problemId);
            //3.执行sql
            resultSet =statement.executeQuery();
            //4.遍历结果集
            if (resultSet.next()){
                problem.setId(resultSet.getInt("id"));
                problem.setTitle(resultSet.getString("title"));
                problem.setLevel(resultSet.getString("level"));
                problem.setDescription(resultSet.getString("description"));
                problem.setTemplateCode(resultSet.getString("templateCode"));
                problem.setTestCode(resultSet.getString("testCode"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }finally {
            DBUtil.close(connection,statement,resultSet);
        }
        return problem;
    }

    public static void testInsert(){
        Problem problem = new Problem();
        problem.setDescription("两数之和");
        problem.setLevel("简单");
        problem.setDescription("1111111描述信息");
        problem.setTemplateCode("代码模板");
        problem.setTestCode("public static void main(String[] args) {\n" +
                "        Solution solution = new Solution();\n" +
                "        int[] arr = {2,7,11,15};\n" +
                "        int target = 9;\n" +
                "        int[] result=solution.twoSum(arr,target);\n" +
                "        if (result.length==2 && result[0]==1 && result[1]==2){\n" +
                "            System.out.println(\"testCase OK\");\n" +
                "        }else {\n" +
                "            System.out.println(\"testCase Falsed:arr:{2,7,11,15},target=9\");\n" +
                "        }\n" +
                "\n" +
                "        int[] arr2={3,2,4};\n" +
                "        int target2 = 6;\n" +
                "        int[] result2=solution.twoSum(arr2,target2);\n" +
                "        if (result2.length==2 && result2[0]==1 && result2[1]==2){\n" +
                "            System.out.println(\"testCase OK\");\n" +
                "        }else {\n" +
                "            System.out.println(\"testCase Falsed:arr:{3,2,4},target=6\");\n" +
                "        }\n" +
                "    }");
        ProblemDAO problemDAO = new ProblemDAO();
        problemDAO.insert(problem);
    }

    public static void testDelete(){
        ProblemDAO problemDAO = new ProblemDAO();
        problemDAO.delete(1);
    }

    protected static void  testSelectAll(){
        ProblemDAO problemDAO = new ProblemDAO();
        List<Problem> problems=problemDAO.selectAll();
        System.out.println(problems);
    }

    protected static void  testSelectOne(){
        ProblemDAO problemDAO = new ProblemDAO();
        Problem problem=problemDAO.selectOne(1);
        System.out.println(problem);
    }
    public static void main(String[] args) {
        //1.先测试一下插入逻辑
        testInsert();
    }
}
