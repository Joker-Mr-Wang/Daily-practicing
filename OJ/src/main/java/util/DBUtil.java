package util;

import com.mysql.jdbc.jdbc2.optional.MysqlDataSource;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

//方便其他的代码随时能够建立数据建立连接~
public class DBUtil {
    //DataSource 这个东西一般一个程序里面有一个实例就够了~~
    //单例模式
    private static final  String URL = "jdbc:mysql://localhost:3306/ojtest?characterEncoding=utf8&useSSL=true";
    private static final  String USERNAME = "root";
    private static final  String PASSWORD = "root";

    private static DataSource dataSource = null;

    // 目的是只创建出一个DataSource 实例
    private static DataSource getDataSource(){
        if (dataSource == null){
            //没有被实例化就创建一个实例
            dataSource = new MysqlDataSource();
            ((MysqlDataSource)dataSource).setUrl(URL);
            ((MysqlDataSource)dataSource).setUser(USERNAME);
            ((MysqlDataSource)dataSource).setPassword(PASSWORD);
        }
        //如果已经被实例化过了，就直接返回现有的实例
        return dataSource;
    }

    public static Connection getConnection(){
        try {
            return getDataSource().getConnection();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
        return null;
    }

    //回收资源
    public static void close(Connection connection, PreparedStatement statement, ResultSet resultSet){
        if (resultSet != null){
            try {
                resultSet.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        if (statement!=null){
            try {
                statement.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }

//        try {
//            if (resultSet!=null){
//                resultSet.close();
//            }
//            if (statement!=null){
//                statement.close();
//            }
//            if (connection!=null){
//                connection.close();
//            }
//        } catch (SQLException e) {
//            e.printStackTrace();
//        }

    }
}
