package algorithms;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 숫자 만들기 
public class swea4008 {
	static int N, min, max;
	static int[] ops = new int[4]; // + - * /
	static int[] nums, permu;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = null;
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			min = Integer.MAX_VALUE;
			max = -Integer.MAX_VALUE;
			N = Integer.parseInt(br.readLine());
			
			nums = new int[N];
			permu = new int[N - 1];
			stk = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < 4; i++) {
				ops[i] = Integer.parseInt(stk.nextToken());
			}
			stk = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < N; i++) {
				nums[i] = Integer.parseInt(stk.nextToken());
			}
			dfs(0);
			sb.append("#").append(t).append(" ").append(max - min).append("\n");
		}
		System.out.println(sb);
	}
	
	private static void dfs(int depth) {
		if (depth == N - 1) {
			int res = nums[0];
			for (int i = 0; i < permu.length; i++) {
				if (permu[i] == 0) 
					res += nums[i + 1];
				else if (permu[i] == 1)
					res -= nums[i + 1];
				else if (permu[i] == 2)
					res *= nums[i + 1];
				else
					res /= nums[i + 1];
			}
			min = res < min ? res : min;
			max = res > max ? res : max;
			return;
		}
		for (int i = 0; i < 4; i++) {
			if (ops[i] > 0) {
				ops[i]--;
				permu[depth] = i;
				dfs(depth + 1);
				ops[i]++;
			}
		}
	}
}