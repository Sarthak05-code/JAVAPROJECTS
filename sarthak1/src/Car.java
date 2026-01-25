public class Car {
    public static void main(String[] args) {
     Action act = new Action();
     act.brake();
     act.honk();



    }
}

class Action{
    void honk(){
        System.out.println("The Car used it's honk. ");
    }
    void brake(){
        System.out.println("The Car break was pressed. ");
    }
}
