package acmic;

import java.util.Scanner;

public class Main_11720_숫자의합 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		String str = s.next();
		int hap = 0;
		for(int i=0; i<str.length(); i++) {
			hap += (str.charAt(i)-'0');
		}
		System.out.println(hap);
	}
}
