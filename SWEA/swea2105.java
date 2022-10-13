package algorithms;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

// 디저트 카페
public class swea2105 {
	static int N, ans;
	static int[][] mat;
	static HashSet<Integer> set;
	
	public static void main(String[] args) throws IOException {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = null;
		
		int T = Integer.parseInt(br.readLine());
		int[] dr = new int[] {1, 1, -1, -1};
		int[] dc = new int[] {-1, 1, 1, -1};
		int l, nr, nc, cnt;
		boolean flag;
		int[] curr;
		for (int t = 1; t <= T; t++) {
			ans = -1;
			N = Integer.parseInt(br.readLine());
			mat = new int[N][N];
			for (int i = 0; i < N; i++) {
				stk = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < N; j++) 
					mat[i][j] = Integer.parseInt(stk.nextToken());
			}
			for (int l1 = 1; l1 < N - 1; l1++) {
				for (int l2 = 1; l2 < N - 1; l2++) {
					flag = false;
					for (int i = 0; i < N - 2; i++) {
						for (int j = 1; j < N - 1; j++) {
							curr = new int[] {i, j};
							set = new HashSet<>();
							flag = false;
							for (int d = 0; d < 4; d++) {
								if (d % 2 == 0)
									l = l1;
								else
									l = l2;
								for (int k = 0; k < l; k++) {
									nr = curr[0] + dr[d];
									nc = curr[1] + dc[d];
									if (!check(nr, nc) || set.contains(mat[nr][nc])) {
										flag = true;
										break;
									}
									set.add(mat[nr][nc]);
									curr[0] = nr;
									curr[1] = nc;
								}
								if (flag)
									break;
							}
							if (!flag) {
								if (l1 == 1 || l2 == 1)
									cnt = (l1 + 1) * (l2 + 1);
								else
									cnt = (l1 + 1) * (l2 + 1) - ((l1 - 1) * (l2 - 1));
								ans = ans < cnt ? cnt : ans;
								break;
							}
						}
						if (!flag) 
							break;
					}
				}
			}
			sb.append("#").append(t).append(" ").append(ans).append("\n");
		}
		System.out.println(sb);
	}
	
	private static boolean check(int i, int j) {
		if (i < 0 || i >= N || j < 0 || j >= N)
			return false;
		return true;
	}
}
