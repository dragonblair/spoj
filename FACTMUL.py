n = int(input())
p = 109546051211
ans = 1
prev = 1
for x in range(1,n+1):
	ans *= x
	if ans > p:
		ans = ans % p
	prev *= ans
	if prev > p:
		prev = prev % p
print(prev) 