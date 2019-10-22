import java.util.Scanner;

public class Main_3052 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int arr[] = new int[10];
		for(int i=0; i<10; i++) {
			arr[i] = s.nextInt();
		}
		int rep[] = new int[42];
		for(int i=0; i<10; i++) {
			rep[arr[i]%42]++;
		}
		int cnt = 0;
		for(int i=0; i<42; i++) {
			if(rep[i]!=0) {
				cnt++;
			}
		}
		System.out.println(cnt);
	}
}
