s = raw_input()

ans = len(s)
for c in range(26):
  c = chr(ord("a")+c)
  t = s
  n = 0
  while True:
    if t==c*len(t):
      break
    x = ""
    for i in range(len(t)-1):
      if t[i+1]==c:
        x += t[i+1]
      else:
        x += t[i]
    t = x
    n += 1
  ans = min(ans, n)
print ans
