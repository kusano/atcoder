s = raw_input()
K = input()

S = set()
for i in range(len(s)):
  for j in range(K):
    S.add(s[i:i+j+1])
print sorted(list(S))[K-1]
