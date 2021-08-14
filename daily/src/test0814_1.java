public class test0814_1 {
    //冒泡排序
    public static void main(String[] args) {
        int[] arr = {2,5,7,3,6};
        Sort(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
        public static void Sort(int[] array) {
            for (int i = 0; i <array.length-1; i++)
                for (int j = i+1; j<array.length; j++) {
                    if (array[i]>array[j]) {
                        int tmp=array[i];
                        array[i]=array[j];
                        array[j]=tmp;
                    }
                }
            }
}
