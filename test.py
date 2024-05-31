N = int(input())
L = []

ans = 0
for _ in range(N):
    now = int(input())
    prevans = ans
    while L:
        if L[-1] < now:
            L.pop()
            ans += 1
        else:
            break
    if L:
        ans += 1
    L.append(now)
    print(f'nowans = {ans - prevans}')
print(ans)
# 112231

# 7
# 2
# 4
# 1
# 2
# 2
# 5
# 1