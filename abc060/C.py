N, T = map(int, raw_input().split())
x = map(int, raw_input().split())

ans = 0
for i in range(N-1):
  ans += min(T, x[i+1]-x[i])
ans += T
print ans
