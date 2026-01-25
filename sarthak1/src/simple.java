import java.util.*;

public class simple {
    public static void main(String[] args) throws Exception{

         SI si = new SI();
         Scanner sc = new Scanner(System.in);

         System.out.println("Enter P: ");
         int p = sc.nextInt();

         System.out.println("Enter Time: ");
         int t = sc.nextInt();

         System.out.println("Enter R: ");
         int r = sc.nextInt();

         int ans = si.SimpleInterest(p , t , r);

         System.out.println("The simple interst is: " + ans);

         sc.close();
    }

}

class SI {
    public int SimpleInterest(int P , int T , int R ){
      return (P * T * R) / 100;

    }
}