import java.util.*;

public class Cars {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter X: ");
        int a = sc.nextInt();

        System.out.println("Enter Y: ");
        int b = sc.nextInt();

        Utilities obj = new Utilities(a, b);
        
        obj.Add();
        sc.close();
    }
}

class Utilities {
    //Instance Variable
    int a;
    int b;

    public Utilities(int a, int b) {
        this.a = a;
        this.b = b;

    }

    public void Add() {
        System.out.println(a + b);
    }
}

