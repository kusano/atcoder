a = 0
for _ in range(3):
  s, e = map(int, raw_input().split())
  a += s*e/10
print a