package acmic;

import java.util.Scanner;

public class Main_2675_문자열반복 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		for(int i=0; i<N; i++) {
			int num = s.nextInt();
			String str = s.next();
			for(int j=0; j<str.length(); j++) {
				for(int k=0; k<num; k++) {
					System.out.print(str.charAt(j));
				}
			}
			System.out.println();
		}
	}
}
