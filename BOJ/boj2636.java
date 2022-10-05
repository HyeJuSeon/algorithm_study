package algorithms;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 치즈 
public class boj2636 {
	static int N, M;
	static int[][] mat;
	static boolean[][] visited;
	static int[] dx = new int[] {1, -1, 0, 0};
	static int[] dy = new int[] {0, 0, 1, -1};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(stk.nextToken());
		M = Integer.parseInt(stk.nextToken());
		mat = new int[N][M];
		for (int i = 0; i < N; i++) {
			stk = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < M; j++) {
				mat[i][j] = Integer.parseInt(stk.nextToken());
			}
		}
		int ans = -1, cnt = 1, remain = 0;
		Queue<int[]> q = new LinkedList<>();
		
		int[] curr = null;
		while (cnt > 0) {
			visited = new boolean[N][M];
			remain = cnt;
			cnt = 0;
			q.add(new int[] {0, 0});
			visited[0][0] = true;
			while (!q.isEmpty()) {
				curr = q.poll();
				for (int i = 0; i < 4; i++) {
					int nx = curr[1] + dx[i];
					int ny = curr[0] + dy[i];
					if (check(ny, nx)) {
						if (mat[ny][nx] == 1) {
							cnt++;
							mat[ny][nx] = 2;
						}
						else if (mat[ny][nx] == 2) {
							mat[ny][nx] = 0;
							q.add(new int[] {ny, nx});
						}
						else {
							q.add(new int[] {ny, nx});
						}
						visited[ny][nx] = true;
					}
				}
			}
			ans++;
		}
		System.out.println(ans);
		System.out.println(remain);
	}
	
	private static boolean check(int i, int j) {
		if (i < 0 || i >= N || j < 0 || j >= M || visited[i][j])
			return false;
		return true;
	}
}
