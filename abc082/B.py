s = raw_input()
t = raw_input()

if sorted(s) < sorted(t)[::-1]:
  print "Yes"
else:
  print "No"
