N = input()
a = map(int, raw_input().split())

ans = []
if abs(min(a))<=max(a):
  ans += [(a.index(max(a)), 0)]
  ans += [(a.index(max(a)), 0)]
  for i in range(1, N):
    ans += [(i-1, i)]
    ans += [(i-1, i)]
else:
  ans += [(a.index(min(a)), N-1)]
  ans += [(a.index(min(a)), N-1)]
  for i in range(N-1)[::-1]:
    ans += [(i+1, i)]
    ans += [(i+1, i)]
print len(ans)
for t in ans:
  print t[0]+1, t[1]+1
