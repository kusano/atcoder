N = input()
A = map(int, raw_input().split())

A = [a for a in A if a>0]
print (sum(A)+len(A)-1)/len(A)
