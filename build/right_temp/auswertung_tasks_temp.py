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

matplotlib.rcParams['font.family'] = 'sans-serif'
matplotlib.rcParams['font.serif'] = 'Palatino'
matplotlib.rcParams['font.size'] = 16

###################################### Data Setup ############################
#file = sys.argv[1] # takes first argument as filename
file = r"C:\Users\tobys\Documents\GitHub\Geant4Box\build\right_temp\temp_neu.txt" # takes first argument as filename

energie, MPV, ERR = np.genfromtxt(file,
            usecols=(0,1,2), comments="#",  unpack="True") # opens data ans extract values at lines

energie = np.array(energie)
MPV = np.array(MPV)
ERR = np.array(ERR)

a1 = 12 #breite
b1 = 6 #höhe
fig=plt.figure(figsize=(a1,b1))
ax = plt.gca()
#0 K = -273,15 C

plt.errorbar(energie, MPV, yerr=ERR*100, marker= 'x', markersize=5,
        linewidth=0, elinewidth=1, capsize=2,
        label='Ar', color='red', ecolor='gray') # Messwerte

#plt.xlabel(r"$T$ / °C",fontsize='16')
plt.xlabel(r"$T$ / K",fontsize='16')
plt.ylabel(r"MPV")
#plt.xlim(0,1400)
#plt.ylim(0,3.8)
#plt.legend(fontsize='8')
#plt.yscale('log')
#plt.xscale('log')
locs, labels = xticks()
#plt.xticks((-20050,0,20050), ('-2e4', '0', '2e4'), size = 10 )
plt.grid()
#plt.show()
plt.savefig("temp_K.pdf",bbox_inches='tight')
plt.close()
