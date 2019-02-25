N = input()
A = map(int, raw_input().split())

ans = 100
for a in A:
  c = 0
  while a%2==0:
    a /= 2
    c += 1
  ans = min(ans, c)
print ans
