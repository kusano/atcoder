A, B = map(int, raw_input().split())

ans = 0
for x in range(A, B+1):
  if x==int(str(x)[::-1]):
    ans += 1
print ans
