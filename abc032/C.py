N, K = map(int, raw_input().split())
s = [input() for _ in range(N)]

if 0 in s:
  print N
elif K==0:
  print 0
else:
  ans = 0
  l = 0
  p = 1
  for r in range(N):
    p *= s[r]
    while p>K:
      p /= s[l]
      l += 1
    ans = max(ans, r-l+1)
  print ans
