package acmic;

import java.util.Arrays;
import java.util.Scanner;

public class Main_2108_Åë°èÇĞ {
	static int[] arr;
	static void swap(int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	static void quickSort(int st, int end) {
		if(st>=end) return;
		int pivot = (st+end)/2;
		int i = st;
		for(int j=st; j<=end; j++) {
			if(arr[j]<arr[pivot]) {
				swap(j, i);
				if(i==pivot) {
					pivot = j;
				}
				i++;
			}
		}
		swap(i, pivot);
		quickSort(st, i-1);
		quickSort(i+1, end);
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		arr= new int[N];
		for(int i=0; i<N; i++) {
			arr[i] = s.nextInt();
		}
		Arrays.sort(arr);
		//quickSort(0, N-1);
		double hap = 0 ;
		for(int i=0; i<N; i++) {
			hap += arr[i];
		}
		hap /= N;
		System.out.println(Math.round(hap));
		System.out.println(arr[N/2]);
		int freq[] = new int[8001];
		for(int i=0; i<N; i++) {
			freq[arr[i]+4000]++;
		}
		int max = -1;
		int index = -1;
		for(int i=0; i<freq.length; i++) {
			if(max<freq[i]) {
				max= freq[i];
				index = i;
			}
		}
		int cnt = 0;
		for(int i=0; i<freq.length; i++) {
			if(max==freq[i]) {
				cnt++;
				if(cnt==2) {
					index = i;
					break;
				}
			}
		}
		System.out.println(index-4000);
		System.out.println(arr[N-1]-arr[0]);
		
		
	}
}
