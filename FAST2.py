#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Krishna Kalubandi
# @Date:   2015-06-29 12:22:37
# @Last Modified by:   Krishna Kalubandi
# @Last Modified time: 2015-06-29 13:18:06
def modexp(e,p):
	c = 1
	b = 2
	while e != 0:
		if e % 2 == 1:
			c = (c * b)
			if c > p:
				c = c % p
		b = b * b
		e //= 2
		if b > p:
			b = b % p
	return c
sol = []
def precompute():
	s = 0
	for x in range(0,501):
		s += modexp(x,1298074214633706835075030044377087)
		if
		sol.append(s)
precompute()
t = input()
for x in xrange(t):
	n = input()
	print(sol[n])



