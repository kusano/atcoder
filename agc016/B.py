N = input()
a = map(int, raw_input().split())

if max(a)-min(a)>=2:
  print "No"
elif max(a)-min(a)==0:
  if N>=2*a[0] or N==a[0]+1:
    print "Yes"
  else:
    print "No"
else:
  cn = max(a)-a.count(min(a))
  if a.count(max(a))>=2 and cn>0 and N>=a.count(min(a))+2*cn:
    print "Yes"
  else:
    print "No"
