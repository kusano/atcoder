N = input()
s = [input() for _ in range(N)]

s.sort()
ans = sum(s)
if ans%10!=0:
  print ans
else:
  for x in s:
    if x%10!=0:
      print ans-x
      break
  else:
    print 0
