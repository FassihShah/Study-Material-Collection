def myMSE(X,Y,m,c):                      # receives dataset with m and c => returns its cost
  dataSize = len(X)
  pY = []
  for i in range(dataSize):
    pY.append((m*X[i] + c))
  total = 0
  for i in range(dataSize):
    total += pow((pY[i]-Y[i]),2)
  cost = total/(2*dataSize)
  return cost

def myMSE1(X,Y,M,c):                    # receives m[] and c => returns costs of that c with combination of all m's
  costs = []
  l = len(M)
  for i in range(l):
    costs.append(myMSE(X,Y,M[i],c))
  print(costs)
  return costs

def getMin1(X,Y,M,c):                   # receives m[] and c => returns m having minimum cost with given c
  costs = myMSE1(X,Y,M,c)
  min = costs[0] 
  index = 0
  for i in range(len(costs)):
    if(min > costs[i]):
      min = costs[i]
      index = i
  return M[index]

def myMSE2(X,Y,m,C):                    # receives m and c[] => returns costs of that m with combination of all c's
  costs = []
  l = len(C)
  for i in range(l):
    costs.append(myMSE(X,Y,m,C[i]))
  print(costs)
  return costs

def getMin2(X,Y,m,C):                   # receives m and c[] => returns c having minimum cost with given m
  costs = myMSE2(X,Y,m,C)
  min = costs[0] 
  index = 0
  for i in range(len(costs)):
    if(min > costs[i]):
      min = costs[i]
      index = i
  return C[index]

def myMSE3(X,Y,M,C):                     # receives m[] and c[] => returns costs of all combinations of m and c
  costs = [[0 for _ in range(len(M))] for _ in range(len(C))]
  for i in range(len(M)):
    for j in range(len(C)):
      costs[i][j] = myMSE(X,Y,M[i],C[j])
  return costs

def getMin3(X,Y,M,C):                   # receives m[] and c[] => returns m and c combination having minimum cost
  costs = myMSE3(X,Y,M,C)
  mins = [0,0]
  min = costs[0][0]
  for i in range(len(M)):
    for j in range(len(C)):
      if(min > costs[i][j]):
        min = costs[i][j]
        mins = [M[i],C[j]]
  return mins

X = [5,10,15]
Y = [21,36,51]
c = [0,1,2,3,4,5,6]
m = [0,1,2,3,4,5,6]
print(getMin3(X,Y,m,c))
