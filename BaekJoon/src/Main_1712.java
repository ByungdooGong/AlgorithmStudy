import java.util.Scanner;

public class Main_1712 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		int c = s.nextInt();
		
		if(c-b<=0) {
			System.out.println(-1);
		}else {
			int tmp = a / (c-b);
			System.out.println(tmp+1);
		}
	}
}
