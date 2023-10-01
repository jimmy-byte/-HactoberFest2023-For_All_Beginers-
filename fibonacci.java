import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t1 = 0, t2 = 1;
    System.out.print("Enter the number of terms: ");
    int n = sc.nextInt();
    System.out.print("First " + n + " terms of Fibonacci series: ");

    for (int i = 1; i <= n; ++i) {
      System.out.print(t1 + ", ");

      int sum = t1 + t2;
      t1 = t2;
      t2 = sum;
    }
  }
}
