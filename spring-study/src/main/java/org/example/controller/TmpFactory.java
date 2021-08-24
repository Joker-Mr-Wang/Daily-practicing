package org.example.controller;

import org.springframework.beans.factory.FactoryBean;
import org.springframework.stereotype.Component;
//通过@FactoryBean注解来将Tmp类注册进去
@Component
public class TmpFactory implements FactoryBean<LoginController.Tmp> {
    //返回值为对应接口的对象
    @Override
    public LoginController.Tmp getObject() throws Exception {
        return new LoginController.Tmp();
    }
//返回的类型
    @Override
    public Class<?> getObjectType() {
        return LoginController.Tmp.class;
    }
}
