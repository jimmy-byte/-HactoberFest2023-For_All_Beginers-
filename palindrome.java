import java.util.*;
class palindrome
{
    public static void main(String[] args)
    {
      Scanner sc = new Scanner(System.in);
      System.out.println("Enter the string");
      String s = sc.next();
      StringBuffer sb = new StringBuffer(s);
      sb.reverse();
      String s1 = sb.toString();
      if(s.equals(s1))
      System.out.println("It is palindrome");
      else
      System.out.println("It is not palindrome");   
    }
}