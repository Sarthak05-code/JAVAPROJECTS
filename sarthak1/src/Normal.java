public class Normal {
    
    public static void main(String[] args) {
        Person man  = new Person("Sarthak",19);
        man.display();

        Person woman = new Person(man);
        woman.display();

        woman = new Person("Jane", 20);
        woman.display();



        
    }
}

class Person{
    String name;
    int age;

    public Person(String name , int age){
        this.name = name;
        this.age = age;
    }

    //Copy

    public Person(Person other){
        this.name = other.name;
        this.age = other.age;
    }

    public void display(){
        System.out.println("Name: " + name + " Age: " + age);
    }
}

