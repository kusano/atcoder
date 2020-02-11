N = input()
ans = 0
for _ in range(N):
  a, b = map(int, raw_input().split())
  ans += a*b
print ans*105/100
