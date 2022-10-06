# 요리사
def dfs(depth, s):
    global ans
    if depth == N // 2:
        # print(selected)
        a = 0
        b = 0
        for i in range(N):
            if selected[i]:
                for j in range(i + 1, N):
                    if selected[j]:
                        a += mat[i][j] + mat[j][i]
            else:
                for j in range(i + 1, N):
                    if not selected[j]:
                        b += mat[i][j] + mat[j][i]
        res = abs(a - b)
        ans = res if res < ans else ans
        return

    for i in range(s, N):
        if selected[i]:
            continue
        selected[i] = 1
        dfs(depth + 1, i + 1)
        selected[i] = 0

T = int(input())
for t in range(1, T + 1):
    N = int(input())
    ans = 10**8
    mat = [list(map(int, input().split())) for _ in range(N)]
    selected = [0] * N
    dfs(0, 0)
    print(f'#{t} {ans}')