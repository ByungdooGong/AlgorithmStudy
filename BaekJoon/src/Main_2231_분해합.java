package acmic;

import java.util.Scanner;

public class Main_2231_ºÐÇØÇÕ {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int arr[] = new int[1000001];
		for(int i=1; i<arr.length; i++) {
			arr[i] = i;
			int tmp = i;
			while(tmp>0) {
				arr[i] += tmp%10;
				tmp = tmp/10;
			}
		}
		boolean flag = false;
		for(int i=1; i<arr.length; i++) {
			if(arr[i] == n) {
				System.out.println(i);
				flag = true;
				break;
			}
		}
		if(!flag) System.out.println(0);
	}
}
