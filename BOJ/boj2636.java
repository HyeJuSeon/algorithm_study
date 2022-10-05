package day1005.hw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

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
		visited = new boolean[N][M];
		int ans = 0;
		int remain = 0;
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {0, 0});
		int[] curr = null;
		while (q.isEmpty()) {
			curr = q.poll();
			for (int i = 0; i < 4; i++) {
				int nx = curr[1] + dx[i];
				int ny = curr[0] + dy[i];
				if (check(nx, ny)) {
					q.add(new int[] {nx, ny});
					visited[nx][ny] = true;
				}
			}
		}
	}
	
	private static boolean check(int i, int j) {
		if (i < 0 || i >= N || j < 0 || j >= M || visited[i][j])
			return false;
		return true;
	}
}
