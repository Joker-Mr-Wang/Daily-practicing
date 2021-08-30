import java.util.ArrayList;
import java.util.List;

public class Test0830_2 {
    public static void main(String[] args) {
        System.out.println(generate(5));
    }

    public static List<List<Integer>> generate(int numRows) {
            if (numRows<=0){
                //如果输入的值<=0,则直接返回一个空集合
                return new ArrayList<>();
            }
            List<List<Integer>> result = new ArrayList<>();
            List<Integer> first = new ArrayList<>();
            first.add(1);
            result.add(first);
            //如果是第一行则输出第一行结果
            if (numRows==1){
                return result;
            }
            List<Integer> second =new ArrayList<>();
            second.add(1);
            second.add(1);
            result.add(second);
            //  //如果是第二行则输出第二行结果
            if (numRows==2){
                return result;
            }
            for (int row = 3; row <=numRows; row++) {
                List<Integer> listLine =result.get(row-1-1);
                //创建当前行
                List<Integer> line =new ArrayList<>();
                //第一个元素
                line.add(1);
                //除去首尾的元素
                for (int col = 2; col <=row-1 ; col++) {
                    //第i行,j列元素由第i-1行,j-1列和第i-1行,j列相加
                    //row-1是上一行,再-1,是因为数组下标是从0开始计算的
                    int num1=listLine.get(col-1);
                    int num2=listLine.get(col-1-1);
                    line.add(num1+num2);
                }
                //最后一个元素
                line.add(1);

                //把每一行结果放入最终结果里面
                result.add(line);
            }

            return result;
        }
    }
