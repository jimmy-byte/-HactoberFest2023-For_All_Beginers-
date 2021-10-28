#Case 9 T=5 M=10bits
import * from MAC_xor.py
import matplotlib.pyplot as plt
from itertools import product
 
x  = []
y = []

tag_len=5
m_len=10
print("For tag len:: {}".format(tag_len))
print("For msg len:: {}".format(m_len))
tags=list(product(chars, repeat = tag_len)) 
for i in range(0,20):
  key_len=i
  keys=list(itertools.product(chars,repeat=key_len))
  keys = [str(i) for i in keys[random.randint(0,len(keys)-1)]] #stringify
  key=''.join(keys)
  msgs=list(itertools.product(chars,repeat=m_len))
  msgs = [str(i) for i in msgs[random.randint(0,len(msgs)-1)]] #stringify
  Person1_msg=''.join(msgs)
  tag_from_person1=Generate_Tag(Person1_msg,key)
  Person2_messagerecvd=brute(tag_from_person1)
  x.append(i)
  y.append(len(Person2_messagerecvd))
plt.figure(figsize=(10,10))
plt.plot(x, y, label="Variable Key_len")

plt.xlim(0, 20)
plt.yticks(list(range(24,50,2))) 
plt.xticks(list(range(0,20))) 
plt.xlabel("x axis")
plt.ylabel("y axis")
plt.legend()
plt.show()

""" 
Observation: 
  As key size increases approaches size of message the collisions reduce  
"""
