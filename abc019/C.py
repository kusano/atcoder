N = input()
a = map(int, raw_input().split())

S = set()
for t in a:
  while t%2==0:
    t /= 2
  S.add(t)
print len(S)
