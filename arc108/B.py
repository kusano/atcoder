N = int(input())
s = input()

t = []
for x in s:
  if x=="x" and len(t)>=2 and t[-1]=="o" and t[-2]=="f":
    t.pop()
    t.pop()
  else:
    t += [x]
print(len(t))
