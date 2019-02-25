N, M = map(int, raw_input().split())
a = [0]*N
b = [0]*N
for i in range(N):
  a[i], b[i] = map(int, raw_input().split())
c = [0]*M
d = [0]*M
for i in range(M):
  c[i], d[i] = map(int, raw_input().split())

for i in range(N):
  ans = -1
  for j in range(M):
    if ans==-1 or abs(a[i]-c[j])+abs(b[i]-d[j]) < abs(a[i]-c[ans])+abs(b[i]-d[ans]):
      ans = j
  print ans+1
