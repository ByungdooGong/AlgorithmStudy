import java.util.Scanner;

public class Main_4344 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int c = s.nextInt();
		for(int i=0; i<c; i++) {
			int n = s.nextInt();
			double hap = 0;
			int arr[] = new int[n];
			for(int j=0; j<n; j++) {
				int tmp = s.nextInt();
				arr[j] = tmp;
				hap += tmp;
			}
			hap /= n;
			int cnt = 0;
			for(int j=0; j<n; j++) {
				if(hap<arr[j]) {
					cnt++;
				}
			}
			double res = cnt*100.0/n;
			System.out.println(String.format("%.3f", Math.round(res*1000)/1000.0)+"%");
		}
	}
}
