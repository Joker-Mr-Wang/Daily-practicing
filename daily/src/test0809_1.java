import java.util.*;
public class test0809_1 {
        public static void main(String[] args)
        {
            Scanner scan = new Scanner(System.in);
            int n = scan.nextInt();
//长度给n+1防止越界
            int[] array = new int[n+1];
            for(int i = 0;i<n;i++)
            {
                array[i] = scan.nextInt();
            }
            int i = 0;
            int count = 0;
        while(i<n)
            {
        //进入非递减子序列
                        if(array[i] < array[i+1])
                {
                    while(i<n && array[i] <=array[i+1])
                    {
                        i++;
                    }
                    count++;
                    i++;
                }else
                if(array[i]
                        ==
                        array[i+1])
                {
                    i++;
                }else
                {
                    while(i < n && array[i] >= array[i+1])
                    {
                        i++;
                    }
                    count++;
                    i++;
                }
            }
        System.out.println(count);
        }
}

