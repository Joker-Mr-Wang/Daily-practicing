package org.example.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.example.model.Article;

@Mapper
//@Component
public interface ArticleMapper {

    Article selectById(Integer id);

    int insert(Article a);
}
