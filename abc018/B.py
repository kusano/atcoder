S = list(raw_input())
N = input()
for _ in range(N):
  l, r = map(int, raw_input().split())
  S[l-1:r] = S[l-1:r][::-1]
print "".join(S)
