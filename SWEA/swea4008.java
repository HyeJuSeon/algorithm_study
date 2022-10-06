package algorithms;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 숫자 만들기 
public class swea4008 {
	static int N, min, max;
	static int[] ops, ops_, nums;
	static boolean[] visited;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = null;
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			min = Integer.MAX_VALUE;
			max = -Integer.MAX_VALUE;
			N = Integer.parseInt(br.readLine());
			ops = new int[N - 1]; // + - * /
			nums = new int[N];
			stk = new StringTokenizer(br.readLine(), " ");
			int idx = 0;
			for (int i = 0; i < 4; i++) {
				int tmp = Integer.parseInt(stk.nextToken());
				for (int j = 0; j < tmp; j++)
					ops[idx++] = i;
			}
			stk = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < N; i++) 
				nums[i] = Integer.parseInt(stk.nextToken());
			visited = new boolean[N - 1];
			ops_ = new int[N - 1];
			dfs(0);
			sb.append("#").append(t).append(" ").append(max - min).append("\n");
		}
		System.out.println(sb);
	}
	
	private static void dfs(int depth) {
		if (depth == N - 1) {
			int res = nums[0];
			for (int i = 0; i < ops_.length; i++) {
				if (ops_[i] == 0) 
					res += nums[i + 1];
				else if (ops_[i] == 1)
					res -= nums[i + 1];
				else if (ops_[i] == 2)
					res *= nums[i + 1];
				else
					res /= nums[i + 1];
			}
			min = res < min ? res : min;
			max = res > max ? res : max;
			return;
		}
		for (int i = 0; i < N - 1; i++) {
			if (visited[i]) continue;
			ops_[depth] = ops[i];
			visited[i] = true;
			dfs(depth + 1);
			visited[i] = false;
		}
	}
}
