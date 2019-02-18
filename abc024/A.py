A,B,C,K=map(int,raw_input().split())
S,T=map(int,raw_input().split())
print S*A+T*B-[0,C*(S+T)][S+T>=K]