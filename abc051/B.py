K, S = map(int, raw_input().split())

ans = 0
for X in range(K+1):
  ans += max(0, min(K, S-X) - max(0, S-X-K) + 1)
print ans
