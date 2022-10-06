# 특이한 자석
def dfs(n, d):
    visited[n] = 1
    if n > 0 and mags[n][6] != mags[n - 1][2] and not visited[n - 1]:
        dfs(n - 1, d * -1)
    if n < 3 and mags[n][2] != mags[n + 1][6] and not visited[n + 1]:
        dfs(n + 1, d * -1)

    if d == 1: # 시계
        mags[n] = [mags[n][-1]] + mags[n][:-1]
    else: # 반시계
        mags[n] = mags[n][1:] + [mags[n][0]]

T = int(input())
for t in range(1, T + 1):
    ans = 0
    K = int(input())
    mags = [list(map(int, input().split())) for _ in range(4)]
    visited = [0] * 4
    for _ in range(K):
        n, d = map(int, input().split())
        visited = [0] * 4
        dfs(n - 1, d)
    # print(mags)
    for i in range(4):
        if mags[i][0]:
            ans += 2 ** i
    print(f'#{t} {ans}')