#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov 28 22:43:53 2019

@author: gmbll
"""
import re
from keras.models import load_model
import numpy as np 
model = load_model("mnist.h5")
layer1 = model.layers[0].get_config()['name']
fcn = "FCN"
cnn ="CNN"
f = 0
b = 0
c = 0
for layer in model.layers:
     conf = layer.get_config()['name']
     #Dense yazimi
     if(re.findall("dense",conf)!=[]):
         weight = layer.get_weights()[0]#weights
         bias = layer.get_weights()[1]#bias
         w,h = weight.shape
         path = fcn + str(f) +".txt"
         f=f+1
         file = open(path,"w+")
         file.write(str(w)+" "+str(h)+"\n")
         for i in range(h):
             for j in range(w):
                 file.write(str(weight[j][i])+"\n")
             file.write(str(bias[i])+"\n")
             #file.write("\n")
         file.close()
         
     if(re.findall("conv2d",conf)!=[]):
         w = layer.get_weights()[0]
         
         #bias = layer.get_weights()[1]
         #print(bias.shape) 
         shape =w.shape
         #shape = shape[::-1]
         path = cnn+str(c)+".txt"
         c =c+1
         w = np.reshape(w,(shape[0]*shape[1],shape[2],shape[3]))
         file = open(path,"w+")
         file.write(str(shape[1])+" "+str(shape[2])+" "+str(shape[3])+"\n")
         for i in range(shape[0]*shape[1]):
             for k in range(shape[2]):
                 for j in range(shape[3]):
                     file.write(str(w[i][k][j])+"\n")
         #for j in range(shape[3]):
          #  b =b +1;
           # file.write(str(bias[j])+"\n")
         #   print(bias[j])
             #   file.write("\n")
         file.close()

                 