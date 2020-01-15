package acmic;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_11399_ATM {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int arr[] = new int[N];
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		for(int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);
		int hap = 0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<=i; j++) {
				hap += arr[j];
			}
		}
		System.out.println(hap);
	}
}
