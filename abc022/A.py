N,S,T = map(int, raw_input().split())
W = input()
a = int(S<=W<=T)
for _ in range(N-1):
  W += input()
  a += S<=W<=T
print a
