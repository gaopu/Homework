import java.util.Scanner;

// 先计算子问题,然后往上计算
// mkp[x][y] 表示 i 的前 x 位组成的数分成 y 个整数，这 y 个整数的最大乘积
// num[a][b] 表示取 i 的第 a 到 b 位（包括 a, b 位且第一位为 num[1][1]）
// 结论:mkp[x][y] = mkp[z][y-1] * num[z+1][x]
//本代码横向表示数字位数,竖向表示数字分成几段
public class MaxK {
    //数组的边长
    private static int arrLength = 10;
    //保存中间的计算结果
    private static int arr[][] = new int[arrLength][arrLength];
    private static String inputStr;
    //输入的数字的位数
    private static int length;
    //希望分成的段数
    private static int k;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while (true) {
            System.out.println("请输入数字和分成几段:");
            inputStr = scan.next();
            length = inputStr.length();
            k = scan.nextInt();
            System.out.println("结果是:" + maxK());
        }
    }

    private static int maxK() {
        //每行第一列赋值
        for (int i = 1;i <= length;i++) {
            arr[i][1] = Integer.valueOf(inputStr.substring(0,i));
        }

        //按列计算,先计算分成两个数的情况,在计算分成3个数的情况,以此类推
        for (int j = 2;j <= k;j++) {
            //每一列都从上往下计算
            for (int i = 1;i <= length;i++) {
                //如果一个i位的数字不够分成j段,直接不用计算
                if (i < j) {
                    continue;
                }

                //已经证明有如下结论
                //mkp[x][y] = mkp[z][y-1] * num[z+1][x]
                //mkp[i][j] = mkp[z][j-1] * num[z+1][i]
                //z是去除最后一个数字前面的数字位数
                //z可以从1开始遍历到i - 1
                //这里面哪个值大就是当前情况的最优解
                int max = 0;
                for (int z = 1;z < i;z++) {
                    int tmp = arr[z][j - 1] * Integer.valueOf(inputStr.substring(z,i));
                    if (tmp > max) {
                        max = tmp;
                    }
                }
                arr[i][j] = max;
            }
        }

        return arr[length][k];
    }
}
