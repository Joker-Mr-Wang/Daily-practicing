package org.example.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.example.model.Article;
import org.springframework.stereotype.Component;

@Mapper
@Component
public interface ArticleMapper {
    Article selectById(Integer id);
}
