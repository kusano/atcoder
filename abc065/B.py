N = input()
a = [input()-1 for _ in range(N)]
p = 0
for i in range(N):
  if p==1:
    print i
    break
  p = a[p]
else:
  print -1
