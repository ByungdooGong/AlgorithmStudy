package acmic;

import java.util.Scanner;

public class Main_1065_ÇÑ¼ö {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int hap = 0;
		if(N<99) {
			System.out.println(N);
		}else if(N>=99 && N<111) {
			System.out.println(99);
		}else {
			for(int i=111; i<=N; i++) {
				String str = i + "";
				if(str.charAt(0)-str.charAt(1) == str.charAt(1)-str.charAt(2)) {
					hap++;
				}
			}
			System.out.println(99+hap);
		}
	}
}
