N, R = map(int, raw_input().split())
S = list(raw_input())

if S.count("o")==N:
  print 0
  exit(0)

for i in range(N)[::-1]:
  if S[i]==".":
    ans = max(0, i-R+1)
    break
for i in range(N)[::-1]:
  if S[i]==".":
    for j in range(R):
      if i-j>=0:
        S[i-j] = "o"
    ans += 1
print ans
