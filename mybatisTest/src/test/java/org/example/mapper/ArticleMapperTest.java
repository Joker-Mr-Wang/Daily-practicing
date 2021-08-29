package org.example.mapper;

import org.example.Application;
import org.example.model.Article;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

@RunWith(SpringRunner.class)
@SpringBootTest(classes = Application.class)
//@Transactional
public class ArticleMapperTest {

    @Autowired
    private ArticleMapper articleMapper;

    @Test
    public void testSelectById(){
        Article a = articleMapper.selectById(1);
        System.out.println(a);
    }

    @Test
    public void testInsert(){
        Article a = new Article();
        a.setTitle("测试20210711");
        a.setContent("提前批冲刺");
        a.setUserId(1);
        articleMapper.insert(a);
    }
}
