public class test0813_1 {
    //插入排序
    public static void insertSort(int[] array) {
        for (int i = 1; i <array.length; i++) {
            //此时有序区间[0，1）
            //需要排列的是（1，array.length）
            //将每一次需要排列的值取出
            int val = array[i];
            int j = i-1;
            for (; j>=0&&array[j]>val; j--) {
                array[j+1]=array[j];
            }
            //循环结束后，j的位置就是比i大的数，所以我们把i放到j+1的位置上
            array[j+1]=val;
        }
    }
}
