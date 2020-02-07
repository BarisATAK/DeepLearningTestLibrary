from keras.datasets import cifar10
import cv2
import numpy as np
(X_train, y_train), (_, _) = cifar10.load_data() #x_train->giriş (x,y) ,y_train-->cıkış(etiket)

# normalize inputs from 0-255 to 0.0-1.0

#X_train = X_train / 255.0

r,c,dept = X_train[0].shape

path = 'samples/'

for x in range(100):
	new_path = path+str(y_train[x][0])+'.jpg'
	cv2.imwrite(new_path,np.array(X_train[x]))	
	file = open(new_path,"w+")
	
	file.write(str(r)+" "+str(c)+"\n")
	for w in range(r):
		for y in range(c):
			for d in range(dept):
				file.write(str(X_train[x][w][y][d])+"\n")
	file.close()
			