package algorithms;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

// 점심 식사 시간 
public class swea2383 {
	static int pNum, sNum, ans;
	static ArrayList<int[]> pPos, sPos;
	static ArrayList<Integer> sLen;
	
	public static void main(String[] args) throws IOException {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = null;

		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int N = Integer.parseInt(br.readLine());
			pPos = new ArrayList<>();
			sPos = new ArrayList<>();
			sLen = new ArrayList<>();
			int[][] mat = new int[N][N];
			for (int i = 0; i < N; i++) {
				stk = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < N; j++) {
					mat[i][j] = Integer.parseInt(stk.nextToken());
					if (mat[i][j] == 1)
						pPos.add(new int[] {i, j});
					else if (mat[i][j] != 0) {
						sPos.add(new int[] {i, j});
						sLen.add(mat[i][j]);
					}
				}
			}
			pNum = pPos.size();
			sNum = sPos.size();
			ans = Integer.MAX_VALUE;
			int[] visited = new int[pNum];
			solve(visited, 0);
			sb.append("#").append(t).append(" ").append(ans).append("\n");
		}
		System.out.println(sb);
	}
	
	private static void solve(int[] v, int cnt) {
		if (cnt == pNum) {
			int time = 0;
			for (int s = 0; s < sNum; s++) {
				ArrayList<Integer> dist = new ArrayList<>();
				for (int i = 0; i < pNum; i++) {
					if (v[i] == s) {
						dist.add(Math.abs(pPos.get(i)[0] - sPos.get(s)[0]) + Math.abs(pPos.get(i)[1] - sPos.get(s)[1]));
					}
				}
				Collections.sort(dist);
				int len = sLen.get(s);
				int size = dist.size();
				for (int i = 3; i < size; i++) {
					if (dist.get(i) - dist.get(i - 3) < len) {
						dist.set(i, len + dist.get(i - 3));
					}
				}
				time = (size > 0 && dist.get(size - 1) + len + 1 > time) ? dist.get(size - 1) + len + 1 : time;
			}
			ans = time < ans ? time : ans;
			return;
		}
		// v: [stair1/2] [stair1/2] [stair1/2] [stair1/2] ... -> 조합 
		for (int i = 0; i < sNum; i++) {
			v[cnt] = i;
			solve(v, cnt + 1);
		}
	}
}
