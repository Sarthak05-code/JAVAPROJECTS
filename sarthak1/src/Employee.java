public class Employee {
    public static void main(String[] args) {
        Lists el = new Lists();

        el.id = 50026;
        el.name = "Sarthak";
        el.salary = 23000;

        Lists el2 = new Lists();
        el2.id = 40026;
        el2.name = "Anaxa";
        el2.salary = 45000;

        el.display();
        el2.display();
    }
}

class Lists{
    int id;
    String name;
    double salary;
    void display(){
        System.out.println("ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Salary: " + salary);
        System.out.println();

    }
}
