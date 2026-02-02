import java.util.ArrayList;
import java.util.Scanner;

public class Normal {

    public static void main(String[] args) {
        ArrayList<Integer> array = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of values in this list: ");
        int n  = sc.nextInt();

        for(int i = 0 ; i < n ; ++i)
        {
            System.out.printf("Enter a[%d]: " , i + 1);
            int a = sc.nextInt();
            array.add(a);
        }
        System.out.println("The array is: " + array);

        sc.close();
    }
}