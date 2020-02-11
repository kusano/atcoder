b = map(int, raw_input().split())
N = input()
a = [raw_input() for _ in range(N)]

for i in range(N):
  a[i] = int("".join(chr(ord("0")+b.index(ord(c)-ord("0"))) for c in a[i]))
a.sort()
for i in range(N):
  print "".join(chr(ord("0")+b[ord(c)-ord("0")]) for c in str(a[i]))
