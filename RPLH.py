import math
g = 9.806
t = int(input())
count = 1
for i in range(t):
	d,v = map(int,input().split())
	ans = (d*g)/(v*v)
	if ans > 1:
		print('Scenario #'+repr(count)+': -1')
	else:
		print('Scenario #'+repr(count)+': {0:.2f}'.format(math.asin(ans)*180/(4*math.acos(0.0))))
	count += 1
