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

def linea(x, b0, b1):
    return b0 + b1*x

###################################### Data Setup ############################
#file = sys.argv[1] # takes first argument as filename
file = r"C:\Users\tobys\Documents\GitHub\Geant4Box\build\right_pres\pres_eloss.txt"
file2 = r"C:\Users\tobys\Documents\GitHub\Geant4Box\build\right_pres\fit_data_short.txt"

energie, MPV, ERR = np.genfromtxt(file,
            usecols=(0,1,2), comments="#",  unpack="True") # opens data ans extract values at lines

short_energie, short_MPV, short_ERR = np.genfromtxt(file2,
            usecols=(0,1,2), comments="#",  unpack="True") # opens data ans extract values at lines


energie = np.array(energie)
MPV = np.array(MPV)
ERR = np.array(ERR)

a1 = 12 #breite
b1 = 6 #höhe
fig=plt.figure(figsize=(a1,b1))
ax = plt.gca()
#0 K = -273,15 C

#
# ax.yaxis.set_major_locator(MultipleLocator(500))
# ax.yaxis.set_minor_locator(MultipleLocator(100))
#
# ax.xaxis.set_major_locator(MultipleLocator(10))
# ax.xaxis.set_minor_locator(MultipleLocator(5))
#short_energie = energie[energie > 5]
#short_MPV = MPV[]
#print(energie)
#print(MPV)
X = np.linspace(9, max(energie)+2, len(MPV)+1000 , endpoint=True)

#Linearer Fit to data
fitdata = [1,1]
fitdata, covlinea = curve_fit(linea, short_energie, short_MPV, p0=fitdata)#, sigma=short_ERR)
err_coef = np.sqrt(np.diag(covlinea))

plt.plot(X, linea(X,*fitdata), label='Fit', color='#009E73') # Fit plot

print(short_energie)
print(energie)

ax.grid(which='major', axis='both', linestyle='--',alpha=0.5)# lw = 0.5)
ax.tick_params(direction='in', length=6, width=2)
ax.tick_params(which='minor',direction='in', length=4)


#plt.errorbar(energie-273.15, MPV, yerr=ERR*10, marker= 'x', markersize=5,
plt.errorbar(energie, MPV, yerr=ERR*10, marker= 'x', markersize=5,
       linewidth=0, elinewidth=1, capsize=2,
       label='Ar', color='red', ecolor='gray') # Messwerte

plt.errorbar(short_energie, short_MPV, yerr=short_ERR*10, marker= 'x', markersize=5,
        linewidth=0, elinewidth=1, capsize=2,
        label='Ar', color='red', ecolor='gray') # Messwerte

#plt.xlim(0,7)
#plt.ylim(0,75)


plt.xlabel(r"$p$ / bar",fontsize='16')
plt.ylabel(r"MPV")
#plt.legend(fontsize='8')
#plt.yscale('log')
#plt.xscale('log')
locs, labels = xticks()
#plt.xticks((-20050,0,20050), ('-2e4', '0', '2e4'), size = 10 )
ax.grid(which='major', axis='both', linestyle='--',alpha=0.5)# lw = 0.5)
#plt.show()
plt.savefig(r"presures.pdf",bbox_inches='tight')
plt.close()
