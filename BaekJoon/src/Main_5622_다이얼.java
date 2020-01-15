package acmic;

import java.util.Scanner;

public class Main_5622_´ÙÀÌ¾ó {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String str = s.next();
		int arr[] = new int[11];
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == 'A' || str.charAt(i) == 'B' || str.charAt(i) == 'C') {
				arr[2]++;
			} else if (str.charAt(i) == 'D' || str.charAt(i) == 'E' || str.charAt(i) == 'F') {
				arr[3]++;
			} else if (str.charAt(i) == 'G' || str.charAt(i) == 'H' || str.charAt(i) == 'I') {
				arr[4]++;
			} else if (str.charAt(i) == 'J' || str.charAt(i) == 'K' || str.charAt(i) == 'L') {
				arr[5]++;
			} else if (str.charAt(i) == 'M' || str.charAt(i) == 'N' || str.charAt(i) == 'O') {
				arr[6]++;
			} else if (str.charAt(i) == 'P' || str.charAt(i) == 'Q' || str.charAt(i) == 'R' || str.charAt(i) == 'S') {
				arr[7]++;
			} else if (str.charAt(i) == 'T' || str.charAt(i) == 'U' || str.charAt(i) == 'V') {
				arr[8]++;
			} else if (str.charAt(i) == 'W' || str.charAt(i) == 'X' || str.charAt(i) == 'Y' || str.charAt(i) == 'Z') {
				arr[9]++;
			}
		}
		int hap = 0;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] != 0) {
				hap += (i + 1) * arr[i];
			}
		}
		System.out.println(hap);

	}
}
