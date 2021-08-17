package api;

import lombok.Getter;
import lombok.Setter;

@Setter
@Getter
// 表示编译结果的响应类
public class CompileResponse {
    private int errno;
    private String reason;
    private String stdout;


}
