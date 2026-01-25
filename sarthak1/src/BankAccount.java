public class BankAccount {
    public static void main(String[] args) {
        BankAccounts myAccount = new BankAccounts();
        myAccount.deposit(10000);
        myAccount.withdraw(1200);
        
    }
}

class BankAccounts{
    double balance;
    void deposit(double amount){
        balance += amount;
    
System.out.println(balance + " Has been deposited successfully.");
    }

    void withdraw(double amount){
        if(amount <= balance){
            balance -= amount;
System.out.println("Sucessfully withdrawn amount: " + amount);
        } else {
System.out.println("Error! Insufficient amount detected: ");
        }
    }
}