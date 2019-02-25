W, a, b = map(int, raw_input().split())
if b>a+W:
  print b-a-W
elif a>b+W:
  print a-b-W
else:
  print 0
