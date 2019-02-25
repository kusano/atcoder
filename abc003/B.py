S = raw_input()
T = raw_input()

ans = "You can win"
a = "atcoder"
for s,t in zip(S, T):
  if not (s==t or s=="@" and t in a or t=="@" and s in a):
    ans = "You will lose"
print ans
