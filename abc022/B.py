N = input()
A = [input() for _ in range(N)]

print len(A)-len(set(A))
