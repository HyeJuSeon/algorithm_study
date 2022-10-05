package day1005.ws;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

// 낚시왕
public class boj17143 {
	static ArrayList<int[]> arr = new ArrayList<int[]>();
	static int R, C, M;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine(), " ");
		R = Integer.parseInt(stk.nextToken());
		C = Integer.parseInt(stk.nextToken());
		M = Integer.parseInt(stk.nextToken());
		int r, c, s, d, z;
		int[][][] visited = new int[R + 1][C + 1][5];
		for (int i = 0; i < M; i++) {
			stk = new StringTokenizer(br.readLine(), " ");
			r = Integer.parseInt(stk.nextToken());
			c = Integer.parseInt(stk.nextToken());
			s = Integer.parseInt(stk.nextToken());
			d = Integer.parseInt(stk.nextToken());
			z = Integer.parseInt(stk.nextToken());
			arr.add(new int[] {r, c, s, d, z});
		}
		if (arr.isEmpty()) {
			System.out.println(0);
			System.exit(0);
		}

		int ans = 0;
		for (int j = 1; j <= C; j++) {
			boolean flag = false;
			int idx = 0;
			int row = R + 1;
			for (int i = 0; i < arr.size(); i++) {
				if (arr.get(i)[1] == j && arr.get(i)[0] < row) {
					flag = true;
					row = arr.get(i)[0];
					idx = i;
				}
			}	
			if (flag) {
				ans += arr.get(idx)[4];
				arr.remove(idx);
			}
			
			int size = arr.size();
			for (int i = size - 1; i >= 0; i--) {
				r = arr.get(i)[0];
				c = arr.get(i)[1];
				s = arr.get(i)[2];
				d = arr.get(i)[3];
				z = arr.get(i)[4];
				
				if (d == 1) { // up
					if (r - s > 0) {
						r -= s;
					}
					else {
						int tmp = s - (r - 1);
						int div = tmp / (R - 1);
						int mod = tmp % (R - 1);
						if (div % 2 == 0) { // 경계 넘는 횟수가 홀수
							d = 2;
							r = mod + 1;
						}
						else {
							r = R - mod;
						}
					}
				} 
				else if (d == 2) { // down
					if (r + s <= R) {
						r += s;
					}
					else {
						int tmp = s - (R - r);
						int div = tmp / (R - 1);
						int mod = tmp % (R - 1);
						if (div % 2 == 0) {
							d = 1;
							r = R - mod;
						}
						else {
							r = mod + 1;
						}
					}
				}
				else if (d == 3) { // right
					if (c + s <= C) {
						c += s;
					}
					else {
						int tmp = s - (C - c);
						int div = tmp / (C - 1);
						int mod = tmp % (C - 1);
						if (div % 2 == 0) {
							d = 4;
							c = C - mod;
						}
						else {
							c = mod + 1;
						}
					}
				}
				else { // left
					if (c - s > 0) {
						c -= s;
					}
					else {
						int tmp = s - (c - 1);
						int div = tmp / (C - 1);
						int mod = tmp % (C - 1);
						if (div % 2 == 0) {
							d = 3;
							c = mod + 1;
						}
						else {
							c = C - mod;
						}
					}
				}
				arr.set(i, new int[] {r, c, s, d, z});
			}
			visited = new int[R + 1][C + 1][5];
			size = arr.size();
			for (int i = size - 1; i >= 0; i--) {
				r = arr.get(i)[0];
				c = arr.get(i)[1];
				z = arr.get(i)[4];
				if (visited[r][c][0] == 0) {
					visited[r][c] = arr.get(i);
				}
				else {
					if (visited[r][c][4] < z) {
						arr.remove(visited[r][c]);
						visited[r][c] = arr.get(i);
					}
					else {
						arr.remove(arr.get(i));
					}
				}
			}
		}
		System.out.println(ans);
	}
}
