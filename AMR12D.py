n = int(input())
for x in range(n):
	s = input()
	if s == s[::-1]:
		print("YES")
	else:
		print("NO")