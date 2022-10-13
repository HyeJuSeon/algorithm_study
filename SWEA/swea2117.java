package algorithms;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 홈 방범 서비스	
public class swea2117 {
	static int N, M;
	static int[][] mat;
	static boolean[][] visited;
	static Queue<int[]> q;
	
	public static void main(String[] args) throws IOException {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = null;
		int T = Integer.parseInt(br.readLine());
		int[] dr = {1, -1, 0, 0};
		int[] dc = {0, 0, 1, -1};
		int[] curr;
		int nr, nc, cnt, cost, ans;
		for (int t = 1; t <= T; t++) {
			stk = new StringTokenizer(br.readLine(), " ");
			N = Integer.parseInt(stk.nextToken());
			M = Integer.parseInt(stk.nextToken());
			mat = new int[N][N];
			for (int i = 0; i < N; i++) {
				stk = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < N; j++) 
					mat[i][j] = Integer.parseInt(stk.nextToken());
			}
			
			ans = 1;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					for (int k = 1; k < N + 1; k++) {
						visited = new boolean[N][N];
						q = new LinkedList<>();
						q.add(new int[] {i, j});
						cnt = 0;
						while (!q.isEmpty()) {
							curr = q.poll();
							if (visited[curr[0]][curr[1]]) 
								continue;
							visited[curr[0]][curr[1]] = true;
							if (mat[curr[0]][curr[1]] == 1)
								cnt++;
							for (int d = 0; d < 4; d++) {
								nr = curr[0] + dr[d];
								nc = curr[1] + dc[d];
								if (check(nr, nc, i, j, k))
									q.add(new int[] {nr, nc});
							}
						}
						cost = (k + 1) * (k + 1) + k * k;
						if (cnt * M - cost >= 0)
							ans = ans < cnt ? cnt : ans;
					}
				}
			}
			sb.append("#").append(t).append(" ").append(ans).append("\n");
		}
		System.out.println(sb);
	}
	
	private static boolean check(int i, int j, int r, int c, int k) {
		if (i < 0 || i >= N || j < 0 || j >= N || visited[i][j] || Math.abs(r - i) + Math.abs(c - j) > k)
			return false;
		return true;
	}
}
