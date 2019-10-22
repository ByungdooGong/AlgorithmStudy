import java.util.Scanner;

public class Main_8958 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		for(int i=0; i<n; i++) {
			String str = s.next();
			int cnt = 0;
			int hap =0;
			for(int j=0; j<str.length(); j++) {
				if(str.charAt(j)=='O') {
					hap += ++cnt;
				}else {
					cnt = 0;
				}
			}
			System.out.println(hap);
		}
	}
}
