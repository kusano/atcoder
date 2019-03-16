N,M = map(int, raw_input().split())

if abs(N-M)>=2:
  print 0
else:
  mod = 10**9+7
  ans = 1
  for i in range(1, N+1):
    ans *= i
    ans %= mod
  for i in range(1, M+1):
    ans *= i
    ans %= mod
  if N==M:
    ans *= 2
    ans %= mod
  print ans
