import java.util.Arrays;

public class ShellSort
{
    public static void shell(int[] a)
    {
        int n = a.length;
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                int temp = a[i];
                int j;
                for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                {
                    a[j] = a[j - gap];
                }
                a[j] = temp;
            }
        }
    }

    public static void main(String[] args)
    {
        ShellSort ob = new ShellSort();
        int nums[] = { 7, -5, 3, 2, 1, 0, 45 };
        System.out.println("ORIGINAL ARRAY :");
        System.out.println(Arrays.toString(nums));

        ob.shell(nums);
        System.out.println("\nSORTED ARRAY :");
        System.out.println(Arrays.toString(nums));
    }
}
