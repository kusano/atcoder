N = input()
s = raw_input()

for ans in ["SS", "SW", "WS", "WW"]:
  for i in range(2, N):
    if   ans[-2:]=="SS" and s[i-1]=="o": ans += "S"
    elif ans[-2:]=="SS" and s[i-1]=="x": ans += "W"
    elif ans[-2:]=="SW" and s[i-1]=="o": ans += "W"
    elif ans[-2:]=="SW" and s[i-1]=="x": ans += "S"
    elif ans[-2:]=="WS" and s[i-1]=="o": ans += "W"
    elif ans[-2:]=="WS" and s[i-1]=="x": ans += "S"
    elif ans[-2:]=="WW" and s[i-1]=="o": ans += "S"
    elif ans[-2:]=="WW" and s[i-1]=="x": ans += "W"
  if ((ans[0]=="S" and s[0]=="o" and ans[-1]==ans[1] or
       ans[0]=="S" and s[0]=="x" and ans[-1]!=ans[1] or
       ans[0]=="W" and s[0]=="o" and ans[-1]!=ans[1] or
       ans[0]=="W" and s[0]=="x" and ans[-1]==ans[1]) and
      (ans[-1]=="S" and s[-1]=="o" and ans[-2]==ans[0] or
       ans[-1]=="S" and s[-1]=="x" and ans[-2]!=ans[0] or
       ans[-1]=="W" and s[-1]=="o" and ans[-2]!=ans[0] or
       ans[-1]=="W" and s[-1]=="x" and ans[-2]==ans[0])):
    print ans
    exit(0)
print -1
