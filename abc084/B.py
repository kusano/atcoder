import re

A, B = map(int, raw_input().split())
S = raw_input()

if re.match("^"+"\\d"*A+"-"+"\\d"*B+"$", S):
  print "Yes"
else:
  print "No"
