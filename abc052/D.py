N,A,B=map(int,raw_input().split())
X=map(int,raw_input().split())
print sum(min(B,A*(X[i+1]-X[i]))for i in range(N-1))