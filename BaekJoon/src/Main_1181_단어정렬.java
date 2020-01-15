package acmic;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main_1181_�ܾ����� {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		String arr[] = new String[N];
		for(int i=0; i<N; i++) {
			arr[i] = s.next();
		}
		Arrays.sort(arr, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				if(o1.length()==o2.length()) {
					return o1.compareTo(o2);
				}
				return o1.length()-o2.length();
			}
		});
		for(int i=0; i<N; i++) {
			if(i>=1 && arr[i].equals(arr[i-1])) continue;
			System.out.println(arr[i]);
		}
	}
}
