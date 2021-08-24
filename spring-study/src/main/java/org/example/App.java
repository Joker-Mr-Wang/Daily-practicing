package org.example;

import org.example.config.AppConfig;
import org.example.controller.LoginController;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class App {
    public static void main(String[] args) {
//根据Spring配置文件路径创建容器：应用上下文对象
        //启动容器，加载xml配置文件，扫描org.example包
        //该包及下边子包中的带有Spring注解的类都会注册到容器中，成为bean对象
        //容器可以简单理解为一个Map结构，key为bean的id或者名称，value为bean对象
        ApplicationContext context = new
                ClassPathXmlApplicationContext("beans.xml");
//        //1.获取bean对象。类型获取context.getBean
//        LoginController loginController=context.getBean(LoginController.class);
//        System.out.println(loginController);
//        //2.获取bean对象方式二：bean的名称或者id获取
//        LoginController loginController1= (LoginController) context.getBean("loginController");
//        System.out.println(loginController1);
        //通过类对象注册bean
        LoginController.Tmp tmp= (LoginController.Tmp) context.getBean("tmp");
        System.out.println(tmp);

        AppConfig appConfig = context.getBean(AppConfig.class);
        //关闭容器
        ((ClassPathXmlApplicationContext) context).close();
    }
}
