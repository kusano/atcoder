N = input()
a = map(int, raw_input().split())

c1 = 0
c2 = 0
c4 = 0
for x in a:
  if x%4==0:
    c4 += 1
  elif x%2==0:
    c2 += 1
  else:
    c1 += 1

if c1>0:
  p = 1
  c1 -= 1
elif c2>0:
  p = 2
  c2 -= 1
else:
  p = 4
  c4 -= 1

while c1+c2+c4>0:
  if p==1:
    if c4>0:
      c4 -= 1
      p = 4
    else:
      print "No"
      break
  elif p==2:
    if c2>0:
      c2 -= 1
      p = 2
    elif c4>0:
      c4 -= 1
      p = 4
    else:
      print "No"
      break
  else:
    if c1>0:
      c1 -= 1
      p = 1
    elif c2>0:
      c2 -= 1
      p = 2
    else:
      c4 -= 1
      p = 4
else:
  print "Yes"
