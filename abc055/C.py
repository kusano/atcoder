N, M = map(int, raw_input().split())
ans = min(N, M/2)
M -= ans*2
if M>0:
  ans += M/4
print ans
