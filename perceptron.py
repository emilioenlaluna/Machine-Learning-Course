

import numpy as np
import matplotlib.pyplot as plt

personas=np.array([[0.3,0.4],[0.4,0.3],
                   [0.3,0.2],[0.4,0.1],
                   [0.5,0.4],[0.4,0.8],
                   [0.6,0.8],[0.5,0.6],
                   [0.7,0.6],[0.8,0.5]])

clases=np.array([0,0,0,0,0,1,1,1,1,1])

def activacion (pesos,x,b):
  z=pesos*x
  if z.sum()+b>0:
    return 1
  else:
    return 0

pesos=np.random.uniform(-1,1,size=2)
b=np.random.uniform(-1,1)
pesos,b,activacion(pesos,[0.5,0.5],b)

pesos=np.random.uniform(-1,1,size=2)
b=np.random.uniform(-1,1)
taza_de_aprendizaje=0.01
epocas=100

for epoca in range(epocas):
  error_total=0
  for i in range(len(personas)):
    prediccion=activacion(pesos,personas[i],b)
    error=clases[i]-prediccion
    error_total+=error**2
    pesos[0]+=taza_de_aprendizaje*personas[i][0]*error
    pesos[1]+=taza_de_aprendizaje*personas[i][1]*error
    b+=taza_de_aprendizaje*error
  print(error_total,end=" ")

