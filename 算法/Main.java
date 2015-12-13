// 正整数的最优分解
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.print("请输入数字进行最优分解:");
        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();

        int[] nums = new int[100];
        //从2开始的因子
        int s = 2;
        //数组计数
        int i = 0;
        while (true) {
            if (num >= s) {
                nums[i++] = s;
                num -= s;
                s++;
            } else if (num == 0) {
                break;
            } else {
                for (int j = i - 1;j >= 0;j--) {
                    nums[j]++;
                    num--;
                    if (num == 0) {
                        break;
                    }
                }
            }
        }

        int result = 1;
        for (int j = 0;j < i;j++) {
            System.out.print(nums[j] + " ");
            result *= nums[j];
        }
        System.out.println("\n" + result);
    }
}
