H, W = map(int, raw_input().split())
N = input()
a = map(int, raw_input().split())

ans = [[0]*W for _ in range(H)]
c = 0
for i in range(N):
  for j in range(a[i]):
    ans[c/W][c%W if c/W%2==0 else -c%W-1] = i
    c += 1

for a in ans:
  for x in a:
    print x+1,
  print
