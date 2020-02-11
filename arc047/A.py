N, L = map(int, raw_input().split())
S = raw_input()

a = 0
t = 1
for s in S:
  if s=="+":
    t += 1
    if t>L:
      t = 1
      a += 1
  else:
    t -= 1
print a
