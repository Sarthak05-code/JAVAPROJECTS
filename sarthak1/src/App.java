import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class App {

    public static void main(String[] args) {
        String url      = "jdbc:mysql://localhost:3306/College";
        String user     = "root";
        String password = "123456";

        try (Connection con = DriverManager.getConnection(url, user, password)) {
            System.out.println("Connected Successfully");
        } catch (SQLException e) {
            System.out.println("Connection Failed: " + e.getMessage());
        }
    }
}