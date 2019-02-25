X = input()

ans = 1
for b in range(2,X):
  t = b*b
  while True:
    if t>X:
      break
    ans = max(ans, t)
    t *= b
print ans
