package org.example.base;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 定义统一的响应数据格式
 */
@Getter
@Setter
@ToString
public class ResponseResult {
    //业务操作是否成功：前端统一在成功的回调处理
    private  boolean ok;

    //业务操作成功时，可能需要返回业务数据
    private Object data;

    //业务操作失败，返回错误信息
    private String message;

}
