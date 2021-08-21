public class test0821_1 {
    //1.插入排序(将无序区间的数往有序区间里面插入)
    //时间复杂度O(n^2)
    //空间复杂度O（1）
    public static void insertSort(int[] array) {
        int len = array.length;
    //已排序区间（0，i）
    //未排序区间（i，len）；
        for (int i = 1; i <len ; i++) {
            //获取到array[i]的值，让它与有序区间的数进行比较
            int num = array[i];
            //i-1就是有序区间
            int j=i-1;
            //如果他比有序区间最后一个数小，就将有序区间的数往后移动一位
            //只到找到比num小的数，并放到其后面
            for (; j>=0&&array[j]>num ; j--) {
                array[j+1]=array[j];
            }
            array[j+1]=num;
        }
    }
    //2.希尔排序
    //时间复杂度O(n^2),极端O(n^4/3)
    //空间复杂度O（1）
    public static void shellSort(int[] array) {
        //指定gap数列,二分取法;
        int gap = array.length/2;
        //根据gap分组执行对应排序
        while (gap>=1){
            _shellSort(array,gap);
            //实现gep的更新
            gap/=2;
        }
        //当gap等于1时进行希尔排序
        _shellSort(array,1);
    }

    private static void _shellSort(int[] array, int gap) {
        //当第一个时arr[0]时，跟他比较的下一个元素应该是arr[0+gap]，在下一个arr[0+gap+gap]
        int bound =gap;
        for(;bound<array.length;bound++){
            int val=array[bound];
            int j = bound-gap;
            //如果比val大就一直往前找，知道找到比val小的
            for (;j>=0&&array[j]>val;j-=gap){
                array[j+gap]=array[j];
            }
            //将val放到该组比他小的后面一位
            array[j+gap]=val;
        }
    }
    //3.选择排序
    //时间复杂度O(n^2)
    //空间复杂度O（1）
    //不稳定
    public static void selectSort(int[] array) {
        //bound为边界
        //有序区间（0，i）；
        //无序区间（i，array.length）
        for (int bound = 0; bound <array.length; bound++) {
            for (int j = bound+1; j <array.length ; j++) {
                if (array[j]<array[bound]){
                    swap(array,bound,j);
                }
            }
        }
    }

    private static void swap(int[] array, int bound, int j) {
                            int tmp=array[j];
                            array[j]=array[bound];
                            array[bound]=tmp;
    }
    //4.堆排序
    //时间复杂度O(n^2)
    //空间复杂度O（1）
    //不稳定
    public static void heapSort(int[] array) {
        //1。建立堆
        createHeap(array);
        //2.取出堆顶元素，和最后一个元素交换并删除
        //从0开始
        int len = array.length;
        for (int i = 0; i <array.length; i++) {
            //交换0号和堆的最后一个元素
            swap(array,0,len-1);
            //把最后元素进行删除
            len--;
            //从0号元素进行调整
            shiftDown(array,len,0);

        }
    }

    private static void createHeap(int[] array) {
        //找到最后一个节点的位置child=array.length-1；
        //找到他的父节点parent=(child-1)/2
        for (int i = (array.length-1-1)/2; i >=0 ; i--) {
            shiftDown(array,array.length,i);
        }
    }

    private static void shiftDown(int[] array, int size, int index) {
        int parent = index;
        int child = 2*parent+1;
        while (child<size){
            //先找出左右子树谁大
            if (child+1<size&&array[child+1]>array[child]){
                child=child+1;
            }
            //再比较child和parent;
            if (array[parent] < array[child]) {
                swap(array,child,parent);
            }else {
                break;
            }
            parent=child;
            child=2*parent+1;
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[]{10,1,8,5,9,6,7,2,4,3};
//        insertSort(arr);
//        shellSort(arr);
        selectSort(arr);
        for (int i = 0; i <arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}
