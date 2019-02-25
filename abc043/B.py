s = raw_input()

ans = ""
for c in s:
  if c=="B":
    if ans != "":
      ans = ans[:-1]
  else:
    ans += c
print ans
