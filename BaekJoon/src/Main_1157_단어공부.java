package acmic;

import java.util.Scanner;

public class Main_1157_단어공부 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String str = s.next();
		str = str.toLowerCase();
		
		int arr[] = new int[26];
		for(int i=0; i<str.length(); i++) {
			arr[str.charAt(i)-'a']++;
		}
		int max = 0;
		int index = 0;
		for(int i=0; i<arr.length; i++) {
			if(max<arr[i]) {
				max = arr[i];
				index = i;
			}
		}
		char ans = 'a';
		for(int i=0; i<arr.length; i++) {
			if(i==index) continue;
			if(max==arr[i]) {
				ans = '?';
				break;
			}
		}
		if(ans != '?') {
			ans = (char)(index + 'A');
		}
		System.out.println(ans);
	}
}
