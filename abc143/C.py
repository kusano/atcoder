N = input()
S = raw_input()

ans = N
for i in range(N-1):
  if S[i]==S[i+1]:
    ans -= 1
print ans
