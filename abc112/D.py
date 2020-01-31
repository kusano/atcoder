N, M = map(int, raw_input().split())

ans = 0
p = 1
while p*p<=M:
  if M%p==0:
    if M/p>=N:
      ans = max(ans, p)
    if p>=N:
      ans = max(ans, M/p)
  p += 1
print ans
