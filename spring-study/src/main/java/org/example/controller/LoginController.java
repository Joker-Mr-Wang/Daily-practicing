package org.example.controller;

import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Controller;

@Controller
//@Scope("singleton")//不设置默认是单例模式
//@Scope("prototype")//设置了这样每次调用都会创建一个bean对象
public class LoginController {
    /**
     * 当前类能被spring扫描到的情况下
     * 方法加@Bean注解可以注册Bean对象
     * 方法名作为Bean的名称/id，Bean对象作为返回值
     * @return
     */
    //通过@Bean注解来将Tmp类注册进去
    @Bean
    public Tmp tmp(){
        return new Tmp();
    }
    //创建一个tmp的静态类
    public static class Tmp{
    }
}
