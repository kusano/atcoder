N = int(input())
S = [list(input()) for _ in range(N)]

ans = 0
for y in range(N):
  for x in range(N)[::-1]:
    if S[y][x]==".":
      for x2 in range(x+1):
        S[y][x2] = "o"
      if y+1<N:
        for x2 in range(x, N):
          S[y+1][x2] = "o"
      ans += 1
      break
print(ans)
