public class Private {
    public static void main(String[] args) {
        
        Info obj = Info.getInfo();
        
       
        obj.displayMessage();
    }
}

class Info {
    // Private constructor
    private Info() {
        System.out.println("Private! Object created.");
    }

    
    public static Info getInfo() {
        return new Info();
    }

    
    public void displayMessage() {
        System.out.println("Hello from Info object!");
    }
}
