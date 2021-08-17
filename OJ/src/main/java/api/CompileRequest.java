package api;
import lombok.Getter;
import lombok.Setter;

@Setter
@Getter
// 这个类表示进行编译运行操作的请求对象
public class CompileRequest {
    private int id;
    private String code;


}
