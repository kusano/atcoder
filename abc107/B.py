H, W = map(int, raw_input().split())
a = [raw_input() for _ in range(H)]

F = [False]*W
for y in range(H):
  for x in range(W):
    if a[y][x]=='#':
      F[x] = True
for y in range(H):
  if '#' in a[y]:
    l = ""
    for x in range(W):
      if F[x]:
        l += a[y][x]
    print l
