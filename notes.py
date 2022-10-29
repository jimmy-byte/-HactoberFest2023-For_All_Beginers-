"""
author: thund3rstorm
---------------------
Given an amount, write a code to find the minimum number of notes of different
denominations that sum upto the given amount.

Example: 
	Input: 3980

	Output: {2000: 1, 500: 3, 200: 2, 50: 1, 20: 1, 10: 1} 
"""
amt=int(input("Enter the amount \n"))
notes=[2000,500,200,100,50,20,10,5,2,1]
denom={}
for i in notes:
    if i>amt:
        continue
    count=0
    while (amt-i)>=0:
        amt=amt-i
        denom.update({i:count+1})
        count=count+1  
print(denom)