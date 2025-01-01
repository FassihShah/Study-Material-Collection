import numpy as np
def calculateCost(X,Y,m,c):
  dataSize = len(X)
  pY = []
  for i in range(dataSize):
    pY.append((m*X[i] + c))
  total = 0
  for i in range(dataSize):
    total += pow((pY[i]-Y[i]),2)
  cost = total/(2*dataSize)
  return cost

def getGrowthWithTheta0(X,Y,m,c):
  dataSize = len(X)
  total = 0
  for i in range(dataSize):
    total += (c + m*X[i] - Y[i])*X[i]
  growth = total/dataSize
  return growth

def getGrowthWithTheta1(X,Y,m,c):
  dataSize = len(X)
  total = 0
  for i in range(dataSize):
    total += c + m*X[i] - Y[i]
  growth = total/dataSize
  return growth

def getOptimalThetas(X,Y):
  m = 0
  c = 0
  alpha = 0.01
  i = 0
  while(i < 10000 and calculateCost(X,Y,m,c) > 0.000001):
    m = m - (alpha*getGrowthWithTheta0(X,Y,m,c))
    c = c - (alpha*getGrowthWithTheta1(X,Y,m,c))
    i=i+1
  print(calculateCost(X,Y,m,c))
  return m,c

X = [8.3,14.4,6.05]
Y = [20.99,32.89,17.08]

x = [5,10,15]
y = [15,25,35]
print(getOptimalThetas(X,Y))
