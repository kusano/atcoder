m, n, N = map(int, raw_input().split())

ans = N
while N>=m:
  ans += N/m*n
  N = N/m*n+N%m
print ans
