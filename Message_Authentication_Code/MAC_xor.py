#Basic_version() Message Authentication Code
import itertools
import random
import math
from itertools import product


""" MAC A random tag is generated based on a common seed(key). then this tag is shared. by bruteforce the generated message is obtained, 
only constraint is that len(msg) must be a constant we have to check if it matches the original message"""
#Person1-- sender
#Person2 -- receiver
def xor(m,k):
  s=""
  P=min(len(m),len(k))
  for i in range(P):
    if(m[i]==k[i]):
      s=s+'1'
    else:
      s=s+'2'
  s=s+m[P+1:]
  return s[:len(m)]

chars=[1,2]
# key_len=5
# m_len=2
# tag_len=2
# tags=list(product(chars, repeat = tag_len))
#Case 9 T=5 M=10bits
def Generate_Tag(msg,key):
  random.seed(int(xor(msg,key)))
  return tags[random.randint(0,len(tags)-1)]

def Verify_Tag(msg,tag):
  msg=list(msg)
  for i in range(0, len(msg)):
    msg[i] = str(msg[i])
  msg="".join(msg)
  return tag==Generate_Tag(msg,key)

def brute(tag):
  msg_comb=list(itertools.product(chars,repeat=m_len)) 
  poss_list=[]
  for m in msg_comb:
    if(Verify_Tag(m,tag)==1):
      poss_list.append(m)
  return poss_list

chars=[1,2]
key_len=10
m_len=10
tag_len=5
tags=list(product(chars, repeat = tag_len))


keys=list(itertools.product(chars,repeat=key_len))
keys = [str(i) for i in keys[random.randint(0,len(keys)-1)]] #stringify
key=''.join(keys)
msgs=list(itertools.product(chars,repeat=m_len))
msgs = [str(i) for i in msgs[random.randint(0,len(msgs)-1)]] #stringify
Person1_msg=''.join(msgs)

print("Original message",Person1_msg)
tag_from_person1=Generate_Tag(Person1_msg,key)
print("For a given tag{} the messages detected are: ".format(tag_from_person1))
Person2_messagerecvd=brute(tag_from_person1)
print(Person2_messagerecvd)

