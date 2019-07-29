# -*- coding: utf-8 -*-
# Toby Rudolph 20.05.19
#Programm to Calibrate PAMs up to two of them
#!/usr/bin/env python
# coding: utf8
from datetime import datetime
from datetime import timedelta
import matplotlib.dates as mdates
import numpy as np
import matplotlib.pyplot as plt
import matplotlib
import argparse
import glob, os
import matplotlib.ticker as ticker
import matplotlib.gridspec as gridspec
from pylab import *
from scipy.optimize import leastsq
from random import *
 # Modul sys wird importiert:
import sys
from scipy.optimize import curve_fit
from scipy import stats


file = r"C:\Users\tobys\Documents\GitHub\Geant4Box\build\materials.txt" # takes first argument as filename

z, material, density   = np.genfromtxt(file, usecols=(0,1,2), dtype='unicode', comments="#",  unpack="True")

element_symbols = []
for value in material:
    a = value.split("_")
    element_symbols.append(a[1])

print(element_symbols)
# for i in range(0,len(z)):
#     print("//  G4Material* box_mat = new G4Material(\"{0} \", {1}*g/cm3, 1); \n //  box_mat->AddElement({0}, 1.0);".format(element_symbols[i],density[i]))

for i in range(0,len(z)):
    print("// G4String fileName = \"Edep_ZN_{0}_{1}_Proton_20_GeV_1_cm\";".format(z[i],element_symbols[i]))


#print("test nr. %.2f und nr. %.2f" %(1.,2.))
#print("test nr. {0} und nr. {1}".format("HAllo",2.12))
