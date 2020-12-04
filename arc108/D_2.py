S = set()

def f(N, c, s, S):
  if len(s)==N:
    S.add(s)
    return
  for i in range(len(s)-1):
    if s[i:i+2]=="AA":
      f(N, c, s[:i+1]+c[0]+s[i+1:], S)
    if s[i:i+2]=="AB":
      f(N, c, s[:i+1]+c[1]+s[i+1:], S)
    if s[i:i+2]=="BA":
      f(N, c, s[:i+1]+c[2]+s[i+1:], S)
    if s[i:i+2]=="BB":
      f(N, c, s[:i+1]+c[3]+s[i+1:], S)

for N in range(2, 16):
  a = []
  for c in ("AAAA", "AAAB", "AABA", "AABB", "ABAA", "ABAB", "ABBA", "ABBB",
            "BAAA", "BAAB", "BABA", "BABB", "BBAA", "BBAB", "BBBA", "BBBB"):
    S = set()
    f(N, c, "AB", S)
    a += [len(S)]
  print(a)
