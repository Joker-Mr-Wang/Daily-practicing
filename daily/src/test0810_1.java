public class test0810_1 {
//    һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨��(nΪ������)�ܹ��ж�����������
//    ���룺     3

//    ����ֵ��    4
public class Solution {
    public int jumpFloorII(int target) {
//        if(target==0){
//            return 0;
//        }
//        return 1 <<(target-1);
        int res=1;
        for (int i = 2; i <=target; i++) {
            res*=2;
        }
        return res;
    }
}
}
