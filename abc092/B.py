N = input()
D, X = map(int, raw_input().split())

ans = X
for i in range(N):
  A = input()
  ans += 1 + (D-1)/A
print ans
