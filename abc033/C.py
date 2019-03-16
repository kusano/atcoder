S = raw_input()

ans = 0
for s in S.split("+"):
  if "0" not in s.split("*"):
    ans += 1
print ans
