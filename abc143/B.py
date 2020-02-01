N = input()
d = map(int, raw_input().split())
ans = 0
for i in range(N):
  for j in range(i):
    ans += d[i]*d[j]
print ans
