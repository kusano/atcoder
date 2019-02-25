N = input()
S = raw_input()

ans = 0
for i in range(N-1):
  ans = max(ans, len(set(S[:i+1]) & set(S[i+1:])))
print ans
