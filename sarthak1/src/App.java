public class App {

    public static void main(String[] args) {
        int array[][] = new int[][]
        {
            {1,2,3,4},
            {2,33,44},
            {10,50,40},
            {11,99,77},
            {12,24,36}
        };
        for(int i = 0 ; i < array.length ; ++i)
        {
            int sum = 0;
            for(int j = 0 ; j < array[i].length ; ++j)
            {
                sum += array[i][j];
            }
            System.out.printf("The sum of row %d is : %d\n" , i+1 , sum);
        }
    }


}