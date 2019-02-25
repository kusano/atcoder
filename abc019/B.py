s = raw_input()

ans = ""
c = 0
for i in range(len(s)):
  c += 1
  if i==len(s)-1 or s[i]!=s[i+1]:
    ans += s[i] + str(c)
    c = 0
print ans
