N = input()

ans = []
for i in range(1, min(200, N)):
  if sum(map(int, str(N-i)))==i:
    ans += [N-i]
print len(ans)
for a in sorted(ans):
  print a
