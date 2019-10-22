import java.util.Scanner;

public class Main_2577 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		int c = s.nextInt();
		int hap = a*b*c;
		int arr[] = new int[10];
		while(hap>0) {
			arr[hap%10]++;
			hap/=10;
		}
		for(int i=0; i<10; i++) {
			System.out.println(arr[i]);
		}
	}
}
