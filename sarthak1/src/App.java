
import java.util.HashSet;

public class App {
    public static void main(String[] args) {
        HashSet<String> cities = new HashSet<>();
        cities.add("London");
        cities.add("NewYork");
        cities.add("SanFrancisco");
        cities.add("Beijing");
        cities.add("NewYork");
        cities.add("Kathmandu"); // -> New element

        System.out.println("The size of the set is: " + cities.size()); // -> size

        System.out.println("We will remove Beijing"); // -> remove
        cities.remove("Beijing");
        System.out.println("The new set " + cities);

        System.out.println("Does the list contain Kathmandu?: "); // -> contains
        if (cities.contains("Kathmandu"))
            System.out.println("Yes , Kathmandu is present ");
        else
            System.out.println("No , kathmandu is not present");

        HashSet<String> newCities = new HashSet<>(); // add all
        newCities.add("New Mexico");
        cities.addAll(newCities);
        System.out.println("The new set is " + cities);

        newCities.removeAll(newCities); // remove all
        System.out.println("The set is " + newCities);

        HashSet<String> retain = new HashSet<>(); // retain all
        retain.add("Islambad");
        retain.add("Copenhagen");
        retain.add("NewYork");

        cities.retainAll(retain);

        System.out.println("The common value in the set is: " + cities);

    }
}
