N = input()
S = [""]*N
P = [0]*N
for i in range(N):
  S[i], P[i] = raw_input().split()
  P[i] = int(P[i])

t = sum(P)
for i in range(N):
  if P[i]*2>t:
    print S[i]
    exit(0)
print "atcoder"
