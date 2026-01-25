public class Measurement {
    public static void main(String[] args) {
        Measure take = new Measure();
        take.height = 5.10;
        take.weight = 70;

        Measure take2 = new Measure();
        take2.height = 6.2;
        take2.weight = 65;
        
        take.showInfo();
        take2.showInfo();



    }
}

class Measure{
    double height; // in feet and inches
    double weight; // in kg

    void showInfo(){
        System.out.println("Height (feet & inches): " + height);
        System.out.println("Weight (in kg): " + weight);
        System.out.println();
    }
}
