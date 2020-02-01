S = raw_input()

ans = "Yes"
for i in range(len(S)):
  if not (i%2==0 and S[i] in "RUD" or i%2!=0 and S[i] in "LUD"):
    ans = "No"
print ans
