package problem;

import lombok.Getter;
import lombok.Setter;

//实体类,这个类的每个实例就对应数据库中的一条记录
//这个类包含的字段，就和数据库表的字段是相匹配的
@Getter
@Setter
public class Problem {
    //题目的编号
    private int id;
    //题目的标题
    private String title;
    //题目的难度级别
    private String level;
    //题目的详细描述
    private String description;
    //题目的模板代码
    private String templateCode;
    //题目的测试用例代码
    private String testCode;

    @Override
    public String toString() {
        return "Problem{" +
                "id=" + id +
                ", title='" + title + '\'' +
                ", level='" + level + '\'' +
                ", description='" + description + '\'' +
                ", templateCode='" + templateCode + '\'' +
                ", testCode='" + testCode + '\'' +
                '}';
    }
}
