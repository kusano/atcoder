N, K = map(int, raw_input().split())
S = raw_input()

x = 0
for i in range(N):
  if (S[i]=="L" and 0<i and S[i-1]=="L" or
      S[i]=="R" and i<N-1 and S[i+1]=="R"):
    x += 1
print min(x+2*K, N-1)
