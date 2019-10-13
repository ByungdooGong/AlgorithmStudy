
public class Solution_Å¸°Ù³Ñ¹ö {
    public static int solution(int[] numbers, int target) {
        int answer = 0;
        dfs(numbers, 0, target, 0);
        answer = tmp;
        System.out.println(answer);
        return answer;
    }
    static int tmp = 0;
    static void dfs(int[] numbers, int cnt, int target, int hap) {
    	if(cnt==numbers.length) {
    		if(target==hap) {
    			tmp++;
    		}
    		return;
    	}
    	dfs(numbers, cnt+1, target, hap+numbers[cnt]);
    	dfs(numbers, cnt+1, target, hap-numbers[cnt]);
    }
    
    public static void main(String[] args) {
		int[] numbers = {1, 1, 1, 1, 1};
		int target = 3;
		solution(numbers, target);
	}
  
}
