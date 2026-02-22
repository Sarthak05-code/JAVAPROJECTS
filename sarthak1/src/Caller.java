import java.util.*;

public class Caller {

    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("London");
        list.add("NewYork");
        list.add("SanFrancisco");
        list.add("Beijing");
        list.add("NewYork");

        System.out.println("The list is: " + list);

        System.out.println("The array size is: " + list.size());

        list.remove("Beijing");
        System.out.println("Beijing is removed, the new list is: " + list);

        System.out.println("Does list contain NewYork?: " + list.contains("NewYork"));

        List<String> newCity = new ArrayList<>();
        newCity.add("New Mexico");
        newCity.add("Kathmandu");
        newCity.add("NewYork");

        list.addAll(newCity);
        System.out.println("The new list is" + list);
        list.removeAll(newCity);
        System.out.println("The new city again is: " + list);
        list.retainAll(newCity);
        System.out.println("The common value is: " + list);


        


    }
}