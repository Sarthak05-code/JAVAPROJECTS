import java.util.Scanner;
import mypackage.BinaryFinder;

public class Persona {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of values: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        // Input
        for (int i = 0; i < n; i++) {
            System.out.printf("Enter %c: ", (char)(65 + i));
            arr[i] = sc.nextInt();
        }

        // Output
        System.out.println("\nBinary values:");
        for (int i = 0; i < n; i++) {
            BinaryFinder my = new BinaryFinder(arr[i]);   // 👈 important
            System.out.printf(
                "The binary of %d is %s%n",
                arr[i],
                my.getBinary()
            );
        }

        sc.close();
    }
}
