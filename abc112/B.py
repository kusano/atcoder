N, T = map(int, raw_input().split())
ans = 9999
for _ in range(N):
  c, t = map(int, raw_input().split())
  if t<=T:
    ans = min(ans, c)
if ans<9999:
  print ans
else:
  print "TLE"
