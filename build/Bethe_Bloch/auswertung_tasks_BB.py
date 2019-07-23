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


###################################### Data Setup ############################
# file = "Ar/Ar_BB.txt" # takes first argument as filename
# file2 = "Ar_CO2/Ar_CO2_BB.txt" # takes first argument as filename
# file3 = "Ne/Ne_BB.txt" # takes first argument as filename

#windwos
file = r'C:\Users\tobys\Documents\GitHub\Geant4Box\build\Bethe_Bloch\Ar\Ar_BB.txt' # takes first argument as filename
file2 = r'C:\Users\tobys\Documents\GitHub\Geant4Box\build\Bethe_Bloch\Ar_CO2\Ar_CO2_BB.txt' # takes first argument as filename
file3 = r'C:\Users\tobys\Documents\GitHub\Geant4Box\build\Bethe_Bloch\Ne\Ne_BB.txt' # takes first argument as filename


a1 = 12 #breite
b1 = 6 #höhe
fig=plt.figure(figsize=(a1,b1))
energie, MPV, ERR = np.genfromtxt(file,
            usecols=(0,1,2), comments="#",  unpack="True") # opens data ans extract values at lines

energie = np.array(energie)
MPV = np.array(MPV)
ERR = np.array(ERR)

energie2, MPV2, ERR2 = np.genfromtxt(file2,
            usecols=(0,1,2), comments="#",  unpack="True") # opens data ans extract values at lines

energie2 = np.array(energie2)
MPV2 = np.array(MPV2)
ERR2 = np.array(ERR2)


energie3, MPV3, ERR3 = np.genfromtxt(file3,
            usecols=(0,1,2), comments="#",  unpack="True") # opens data ans extract values at lines

energie3 = np.array(energie3)
MPV3 = np.array(MPV3)
ERR3 = np.array(ERR3)

plt.errorbar(energie, MPV, yerr=ERR, marker= 'x', markersize=10,
        linewidth=0, elinewidth=1, capsize=2,
        label='Ar', color='blue', ecolor='gray') # Messwerte

plt.errorbar(energie2, MPV2, yerr=ERR2, marker= 'x', markersize=10,
        linewidth=0, elinewidth=1, capsize=2,
        label='Ar_CO2', color='green', ecolor='gray') # Messwerte

plt.errorbar(energie3, MPV3, yerr=ERR3, marker= 'x', markersize=10,
        linewidth=0, elinewidth=1, capsize=2,
        label='Ne', color='red', ecolor='gray') # Messwerte

plt.xlabel(r"$energy$ / MeV",fontsize='9')
plt.ylabel(r"$MPV$",fontsize='9')
plt.legend(fontsize='16')
plt.yscale('log')
plt.xscale('log')
locs, labels = xticks()
#plt.xticks((-20050,0,20050), ('-2e4', '0', '2e4'), size = 10 )
plt.grid()
plt.show()
#plt.savefig("BetheBloch.pdf",bbox_inches='tight')
#plt.close()
