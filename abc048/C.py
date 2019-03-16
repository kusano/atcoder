N, x = map(int, raw_input().split())
a = map(int, raw_input().split())
ans = 0
for i in range(N-1):
  t = a[i]+a[i+1]-x
  if t>0:
    a[i] -= max(0, t-a[i+1])
    a[i+1] -= min(a[i+1], t)
    ans += t
print ans
