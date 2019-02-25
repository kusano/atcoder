s = raw_input()

A = -1
Z = -1
for i in range(len(s)):
  if s[i]=="A" and A==-1:
    A = i
  if s[i]=="Z":
    Z = i
print Z-A+1
