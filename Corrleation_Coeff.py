## This Python will help you to quickly find out the Correlation Coefficient between any two required attributes whose dataset is given to you.
## :::::Important:::::
## Kindly just update the x as per the given values to you, here I had used an example for x with values such as 17.1,14.7,12.8 for one attribute\
## and 10.6,11.5,13.2 for the another attribute.


import numpy as np
np.random.seed(0)

import matplotlib.pyplot as plt

x=np.array([[17.1,14.7,12.8],[10.6,11.5,13.2]])
r=np.corrcoef(x[0,:],x[1,:])
plt.scatter(x[0,:],x[1,:])
x=np.random.rand(3)
print(r)

