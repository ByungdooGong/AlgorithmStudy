import java.util.Scanner;

public class Main_11022 {
	public static void main(String[] args) {
		Scanner s= new Scanner(System.in);
		int tc = s.nextInt();
		for(int i=1; i<=tc; i++) {
			int a = s.nextInt();
			int b = s.nextInt();
			System.out.println("Case #"+i+ ": " + a + " + "+ b +" = " + (a+b));
		}
	}
}
