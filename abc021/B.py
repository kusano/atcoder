N = input()
a, b = map(int, raw_input().split())
K = input()
P = map(int, raw_input().split())

T = [a, b] + P
if len(set(T))==len(T):
  print "YES"
else:
  print "NO"
