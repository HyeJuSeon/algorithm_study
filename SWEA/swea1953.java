package algorithms;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 탈주범 검거
public class swea1953 {
	static int N, M, R, C, L;
	static Queue<int[]> q;
	static int[][] mat;
	static boolean[][] visited;
	static int[] dr = {1, -1, 0, 0};
	static int[] dc = {0, 0, 1, -1};
	
	public static void main(String[] args) throws IOException {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = null;
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			stk = new StringTokenizer(br.readLine(), " ");
			N = Integer.parseInt(stk.nextToken());
			M = Integer.parseInt(stk.nextToken());
			R = Integer.parseInt(stk.nextToken());
			C = Integer.parseInt(stk.nextToken());
			L = Integer.parseInt(stk.nextToken());
			q = new LinkedList<>();
			mat = new int[N][M];
			visited = new boolean[N][M];
			for (int i = 0; i < N; i++) {
				stk = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < M; j++)
					mat[i][j] = Integer.parseInt(stk.nextToken());
			}
			int ans = 0, r, c, l, nr, nc;
			int[] curr;
			q.add(new int[] {R, C, 1});
			while (!q.isEmpty()) {
				curr = q.poll();
				r = curr[0];
				c = curr[1];
				l = curr[2];
				if (l == L + 1)
					break;
				if (visited[r][c])
					continue;
				visited[r][c] = true;
				ans += 1;
				if (mat[r][c] == 1) {
					for (int i = 0; i < 4; i++) {
						nr = r + dr[i];
						nc = c + dc[i];
						if (check(nr, nc, i))
							q.add(new int[] {nr, nc, l + 1});
					}
				}
				else if (mat[r][c] == 2) {
					for (int i = 0; i < 2; i++) {
						nr = r + dr[i];
						nc = c + dc[i];
						if (check(nr, nc, i))
							q.add(new int[] {nr, nc, l + 1});
					}
				}
				else if (mat[r][c] == 3) {
					for (int i = 2; i < 4; i++) {
						nr = r + dr[i];
						nc = c + dc[i];
						if (check(nr, nc, i))
							q.add(new int[] {nr, nc, l + 1});
					}
				}
				else if (mat[r][c] == 4) {
					for (int i = 1; i < 3; i++) {
						nr = r + dr[i];
						nc = c + dc[i];
						if (check(nr, nc, i))
							q.add(new int[] {nr, nc, l + 1});
					}
				}
				else if (mat[r][c] == 5) {
					for (int i = 0; i < 3; i += 2) {
						nr = r + dr[i];
						nc = c + dc[i];
						if (check(nr, nc, i))
							q.add(new int[] {nr, nc, l + 1});
					}
				}
				else if (mat[r][c] == 6) {
					for (int i = 0; i < 4; i += 3) {
						nr = r + dr[i];
						nc = c + dc[i];
						if (check(nr, nc, i))
							q.add(new int[] {nr, nc, l + 1});
					}
				}
				else if (mat[r][c] == 7) {
					for (int i = 1; i < 4; i += 2) {
						nr = r + dr[i];
						nc = c + dc[i];
						if (check(nr, nc, i))
							q.add(new int[] {nr, nc, l + 1});
					}
				}
			}
			sb.append("#").append(t).append(" ").append(ans).append("\n");
		}
		System.out.println(sb);
	}
	
	private static boolean check(int i, int j, int d) {
		if (i < 0 || i >= N || j < 0 || j >= M || visited[i][j] || mat[i][j] == 0)
			return false;
		if (d == 0) { // bottom
			if (mat[i][j] == 3 || mat[i][j] == 5 || mat[i][j] == 6)
				return false;
		}
		else if (d == 1) { // top
			if (mat[i][j] == 3 || mat[i][j] == 4 || mat[i][j] == 7) 
				return false;
		}
		else if (d == 2) { // right
			if (mat[i][j] == 2 || mat[i][j] == 4 || mat[i][j] == 5)
				return false;
		}
		else { // left
			if (mat[i][j] == 2 || mat[i][j] == 6 || mat[i][j] == 7)
				return false;
		}
		return true;
	}
}
