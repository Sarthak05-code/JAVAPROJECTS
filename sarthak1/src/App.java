import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class App {

    public static void main(String[] args) {
        FileOutputStream out = null;
        FileInputStream in = null;
        Scanner scanner = null;
        
        try {
            // Write to output.txt
            out = new FileOutputStream("output.txt", true);
            scanner = new Scanner(System.in);
            
            System.out.print("Enter text to write to output.txt: ");
            String userInput = scanner.nextLine();
            
            out.write(userInput.getBytes());
            out.write(System.lineSeparator().getBytes());
            
            System.out.println("Text appended to output.txt successfully!");
            
            // Close output stream before reading
            out.close();
            
            // Read from output.txt and count vowels
            in = new FileInputStream("output.txt");
            int byteData;
            int vowelCount = 0;
            
            while ((byteData = in.read()) != -1) {
                char ch = (char) byteData;
                ch = Character.toLowerCase(ch);
                
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowelCount++;
                }
            }
            
            System.out.println("Total vowels in output.txt: " + vowelCount);
            
        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
            e.printStackTrace();
        } finally {
            try {
                if (in != null) {
                    in.close();
                }
                if (out != null) {
                    out.close();
                }
                if (scanner != null) {
                    scanner.close();
                }
            } catch (IOException e) {
                System.err.println("Error closing streams: " + e.getMessage());
            }
        }
    }
}
