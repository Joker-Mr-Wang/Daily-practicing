package org.example.config;

import org.example.exception.AppException;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.ResponseBody;
//统一的异常处理
//响应需要返回统一的数据格式（ok=false,message）
//自定义异常，封装为统一为中文信息

@ControllerAdvice
public class ExceptionAdvice {
    @ExceptionHandler(AppException.class)
    @ResponseBody
    public Object handleAppException(){
        
    }
}
