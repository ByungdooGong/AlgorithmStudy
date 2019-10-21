import java.util.Scanner;

public class Main_1110 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int tmp = n;
		int cnt = 0;
		while(true) {
			cnt++;
			int a = tmp/10;
			int b = tmp%10;
			int hap = a+b;
			hap %= 10;
			tmp = hap + b*10;
			if(tmp==n) {
				System.out.println(cnt);
				break;
			}
		}
	}
}
