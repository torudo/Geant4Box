from random import randint
import random
import numpy as np
import matplotlib.pyplot as plt
import matplotlib


#zufällige zahlen die in einem Textdokument weggespeichert werden sollen.
#dabei sollen Energie und MPV eingespeichert werden
#Außerdem soll das Medium/Teilchenart gespeichert werden

test_string = "Neutron_130_MeV"
energie = test_string.split("_")
print(energie[1])
filename = 'Cprogramming.txt'
# w for write and a for append

#Wenn die Datei nicht existiert soll die erste Zeile geruckt werden, sonst nicht
try:
    with open(filename) as f_obj:
        print()
except FileNotFoundError:
    with open(filename, 'a') as f_obj:
        f_obj.write("##MPV\tenergy\n"+str(randint(-10,10))+"\t"+energie[1]+"\n")
else:
    with open(filename, 'a') as f_obj:
        f_obj.write(str(random.randint(-10,10))+"\t"+energie[1]+"\n")

value, energy = np.genfromtxt(filename, usecols=(0,1), comments="#", unpack="True")
plt.plot(energy,value,'.')
plt.show()
