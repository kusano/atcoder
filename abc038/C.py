N = input()
a = map(int, raw_input().split())

ans = 1
l = 0
for r in range(1,N):
  if a[r-1]>=a[r]:
    l = r
  ans += r-l+1
print ans
