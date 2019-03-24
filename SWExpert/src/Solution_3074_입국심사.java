import java.util.Scanner;

public class Solution_3074_입국심사 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int tc = s.nextInt();
		for(int k=1; k<=tc; k++) {
			int N = s.nextInt();
			int M = s.nextInt();
			int[] arr = new int[N];
			int max = 0;
			for(int i=0; i<N; i++) {
				arr[i] = s.nextInt();
				if(max<arr[i]) {
					max = arr[i];
				}
			}
			long init = (long)max*M;
			long left = 0;
			long right = init;
			while(left<=right) {
				long mid = (left+right)/2;
				long sum = 0;
				for(int i=0; i<arr.length; i++) {
					sum+= mid/arr[i];
				}
				if(sum<M) {
					left = mid+1;
				}else if(sum>=M) {
					if(init>mid) {
						init = mid;
					}
					right = mid-1;
				}
			}
			System.out.println("#" + k + " " + init);
		}
	}
}
