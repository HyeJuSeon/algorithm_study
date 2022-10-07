# 수영장
def dfs(depth):
    global ans
    if depth >= cnt:
        # print('depth: ', depth, ' case: ', case)
        sum = 0
        c = 0
        flag = 0
        for i in range(12):
            if flag: # 3month => pass
                flag -= 1
                if plans[i]:
                    c += 1
                continue
            if plans[i]:
                idx = case[c]
                c += 1
                if idx == 0: # 1d
                    sum += costs[idx] * plans[i]
                elif idx == 1: # 1m
                    sum += costs[idx]
                else: # 3m
                    flag = 2
                    sum += costs[idx]
                # print('costs[idx]: ', costs[idx], ' i: ', i, ' plans[i]', plans[i], ' sum: ', sum)
        ans = sum if sum < ans else ans
        # print('ans: ', ans)
        # print('=' * 80)
        return

    for i in range(3):
        case[depth] = i
        if i < 2: # 1d || 1m
            dfs(depth + 1)
        else: # 3m
            dfs(depth + 3)

T = int(input())
for t in range(1, T + 1):
    ans = 10 ** 9
    costs = list(map(int, input().split()))
    plans = list(map(int, input().split()))
    cnt = 0
    for p in plans:
        if p:
            cnt += 1
    case = [0] * cnt # repetition permutation
    dfs(0)
    ans = costs[-1] if costs[-1] < ans else ans
    print(f'#{t} {ans}')
