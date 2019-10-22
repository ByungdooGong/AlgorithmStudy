import java.util.Scanner;

public class Main_2562 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int arr[] = new int[10];
		for(int i=1; i<=9; i++) {
			arr[i] = s.nextInt();
		}
		int max = -1;
		int maxIndex = -1;
		for(int i=1; i<=9; i++) {
			if(max<arr[i]) {
				max = arr[i];
				maxIndex = i;
			}
		}
		System.out.println(max+"\n"+maxIndex);
		
	}
}
