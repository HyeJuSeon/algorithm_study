package algorithms;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 보호 필름
public class swea2112 {
	static int D, W, K, ans;
	static int[][] mat, copy;
	
	public static void main(String[] args) throws IOException {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = null;
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			stk = new StringTokenizer(br.readLine(), " ");
			D = Integer.parseInt(stk.nextToken());
			W = Integer.parseInt(stk.nextToken());
			K = Integer.parseInt(stk.nextToken());
			mat = new int[D][W];
			copy = new int[D][W];
			ans = 1000;
			for (int i = 0; i < D; i++) {
				stk = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < W; j++) 
					mat[i][j] = copy[i][j] = Integer.parseInt(stk.nextToken());
			}
			dfs(0, 0);
			sb.append("#").append(t).append(" ").append(ans).append("\n");
		}
		System.out.println(sb);
	}
	
	private static void dfs(int cnt, int row) {
		if (cnt > ans)
			return;
		if (isPass()) {
			ans = cnt;
			return;
		}
		if (row == D)
			return;
		
		dfs(cnt, row + 1);
		// convert to A
		for (int i = 0; i < W; i++)
			mat[row][i] = 0;
		dfs(cnt + 1, row + 1);
		// convert to B
		for (int i = 0; i < W; i++)
			mat[row][i] = 1;
		dfs(cnt + 1, row + 1);
		// source
		for (int i = 0; i < W; i++)
			mat[row][i] = copy[row][i];
	}
	
	private static boolean isPass() {
		for (int j = 0; j < W; j++) {
			int cnt = 1;
			int prev = mat[0][j];
			boolean flag = false;
			
			for (int i = 1; i < D; i++) {
				if (mat[i][j] == prev) {
					cnt++;
				}
				else {
					cnt = 1;
					prev = mat[i][j];
				}
				if (cnt == K) {
					flag = true;
					break;
				}
			}
			if (!flag)
				return false;
		}
		return true;
	}
}
