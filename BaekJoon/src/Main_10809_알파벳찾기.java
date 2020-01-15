package acmic;

import java.util.Scanner;

public class Main_10809_¾ËÆÄºªÃ£±â {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String str = s.next();
		int arr[] = new int[26];
		for(int i=0; i<arr.length; i++) {
			arr[i] = -1;
		}
		for(int i=0; i<str.length(); i++) {
			if(arr[str.charAt(i)-'a']==-1) {
				arr[str.charAt(i)-'a'] = i;
			}
		}
		for(int i=0; i<arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
	}
}
