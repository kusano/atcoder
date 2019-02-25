N = input()
a = map(int, raw_input().split())

if sum(a)%N==0:
  t = sum(a)/N
  ans = 0
  x = 0
  y = 0
  for i in range(N-1):
    x += a[i]
    y += t
    if x==y:
      x = 0
      y = 0
    else:
      ans += 1
  print ans
else:
  print -1
