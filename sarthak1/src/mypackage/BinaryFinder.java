package mypackage;

public class BinaryFinder {

    int a;
    String binary;

    public BinaryFinder(int a) {
        this.a = a;
        this.binary = "";

        int temp = a;
        while (temp > 0) {
            int remainder = temp % 2;
            binary = remainder + binary;
            temp = temp / 2;
        }
    }

    public String getBinary() {
        return binary;
    }
}


class BinaryConverter {
    public BinaryConverter() {
        

    }
}