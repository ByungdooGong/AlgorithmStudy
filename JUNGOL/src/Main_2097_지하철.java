import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Main_2097_¡ˆ«œ√∂ {
    static int N;
    static int M;
    static int[][] arr;
    static int dp[];
    static int path[];
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N][N];
        path = new int[N];
        for(int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<N; j++) {
                int tmp = Integer.parseInt(st.nextToken());
                if(tmp==0)
                    arr[i][j] = 99999;
                else {
                    arr[i][j] = tmp;
                }
            }
        }
        int visited[] = new int[N];
        dp = new int[N];
        for(int i=0; i<N; i++) {
            dp[i] = arr[0][i];
        }
        visited[0] = 1;
        for(int i=1; i<N; i++) {
            int min = 99999;
            int minIndex = -1;
            for(int j=0; j<N; j++) {
                if(visited[j]==0 && min>dp[j]) {
                    min = dp[j];
                    minIndex = j;
                }
            }
            visited[minIndex] = 1;
            for(int j=0; j<N; j++) {
                if(dp[j]>dp[minIndex] + arr[minIndex][j]) {
                    dp[j] = dp[minIndex] + arr[minIndex][j];
                    path[j] = minIndex;
                }
            }
        }
        System.out.println(dp[M-1]);
        String pat =M + "";
        int t= path[M-1];
        while(true) {
            if(t!=0) {
                pat = (t+1) + " " + pat;
                t = path[t];
            }
            else {
                pat = 1 + " " + pat;
                break;
            }
        }
        System.out.println(pat);
    }
}