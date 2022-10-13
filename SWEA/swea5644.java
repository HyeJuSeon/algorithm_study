package algorithms;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 무선 충전
public class swea5644 {
	static int M, A, ans;
	static ArrayList<Integer>[][] mat;
	static boolean[][] visited;
	static int[] moveA, moveB;
	static Queue<int[]> q;
	static int[] BC; // BC의 p값
	static int[][] maxBC; // p가 가장 큰 BC 번호
	
	public static void main(String[] args) throws IOException {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = null;
		int T = Integer.parseInt(br.readLine());
		int x, y, c, p, nr, nc;
		int[] curr;
		int[] dr = {1, -1, 0, 0};
		int[] dc = {0, 0, 1, -1};
		
		for (int t = 1; t <= T; t++) {
			mat = new ArrayList[10][10];
			maxBC = new int[10][10];
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					mat[i][j] = new ArrayList<>();
					mat[i][j].add(0);
				}
			}
			stk = new StringTokenizer(br.readLine(), " ");
			M = Integer.parseInt(stk.nextToken());
			A = Integer.parseInt(stk.nextToken());
			moveA = new int[M];
			moveB = new int[M];
			BC = new int[A + 1];
			
			stk = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < M; i++)
				moveA[i] = Integer.parseInt(stk.nextToken());
			stk = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < M; i++)
				moveB[i] = Integer.parseInt(stk.nextToken());
			
			for (int i = 0; i < A; i++) {
				visited = new boolean[10][10];
				stk = new StringTokenizer(br.readLine(), " ");
				x = Integer.parseInt(stk.nextToken()) - 1;
				y = Integer.parseInt(stk.nextToken()) - 1;				
				c = Integer.parseInt(stk.nextToken());
				p = Integer.parseInt(stk.nextToken());
				BC[i + 1] = p;
				q = new LinkedList<>();
				q.add(new int[] {y, x});
				while (!q.isEmpty()) {
					curr = q.poll();
					if (visited[curr[0]][curr[1]])
						continue;
					visited[curr[0]][curr[1]] = true;
					mat[curr[0]][curr[1]].add(p);
					maxBC[curr[0]][curr[1]] = BC[maxBC[curr[0]][curr[1]]] < p ? i + 1 : maxBC[curr[0]][curr[1]];
					for (int d = 0; d < 4; d++) {
						nr = curr[0] + dr[d];
						nc = curr[1] + dc[d];
						if (check(nr, nc, y, x, c))
							q.add(new int[] {nr, nc});
					}
				}
			}
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					Collections.sort(mat[i][j], Collections.reverseOrder());
				}
			}
			
			int[] posA = new int[] {0, 0}, posB = new int[] {9, 9};
			int ans = mat[posA[0]][posA[1]].get(0) + mat[posB[0]][posB[1]].get(0);
			for (int i = 0; i < M; i++) {
				move(posA, moveA[i]);
				move(posB, moveB[i]);
				ans += mat[posA[0]][posA[1]].get(0);
				if (maxBC[posA[0]][posA[1]] == maxBC[posB[0]][posB[1]] && maxBC[posB[0]][posB[1]] != 0) 
					ans += Math.max(mat[posA[0]][posA[1]].get(1), mat[posB[0]][posB[1]].get(1));
				else
					ans += mat[posB[0]][posB[1]].get(0);
			}
			sb.append("#").append(t).append(" ").append(ans).append("\n");
		}
		System.out.println(sb);
	}
	
	private static boolean check(int i, int j, int y, int x, int c) {
		if (i < 0 || i > 9 || j < 0 || j > 9 || visited[i][j] || Math.abs(y - i) + Math.abs(x - j) > c)
			return false;
		return true;
	}
	
	private static void move(int[] pos, int d) {
		if (d == 1)
			pos[0]--;
		else if (d == 2)
			pos[1]++;
		else if (d == 3)
			pos[0]++;
		else if (d == 4)
			pos[1]--;
	}
}
