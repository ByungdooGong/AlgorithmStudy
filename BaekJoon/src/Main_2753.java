import java.util.Scanner;

public class Main_2753 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int y = s.nextInt();
		int flag = 0;
		if(y%4==0) {
			if(y%100!=0 || y%400==0) {
				flag = 1;
			}
		}
		System.out.println(flag);
	}
}
