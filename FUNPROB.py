while True:
	f = input()
	s = f.split()
	n = int(s[0])
	m = int(s[1])
	if n == 0 and m == 0:
		break
	if n > m:
		print('{0:6f}'.format(0))
	else:
		ans = float((m-n+1.0)/(m+1.0))
		print('{0:6f}'.format(ans))