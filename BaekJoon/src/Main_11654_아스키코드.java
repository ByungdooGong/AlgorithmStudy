package acmic;

import java.util.Scanner;

public class Main_11654_아스키코드 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		char c = s.next().charAt(0);
		System.out.println(c-'\0');
	}
}
