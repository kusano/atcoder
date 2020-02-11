N = input()
A = [map(int, raw_input().split()) for _ in range(N)]

print "%.8f"%max(sum(a[:-1])+a[-1]*110/900. for a in A)
