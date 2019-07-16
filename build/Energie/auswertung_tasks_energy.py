from datetime import datetime
from datetime import timedelta
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
file = "energy_eloss_Mu.txt" # takes first argument as filename
file2 = "energy_eloss.txt"
energie, MPV, ERR = np.genfromtxt(file,
            usecols=(0,1,2), comments="#",  unpack="True") # opens data ans extract values at lines
energie2, MPV2, ERR2 = np.genfromtxt(file2,
            usecols=(0,1,2), comments="#",  unpack="True") # opens data ans extract values at lines
energie = np.array(energie)
MPV = np.array(MPV)
ERR = np.array(ERR)

energie2 = np.array(energie2)
MPV2 = np.array(MPV2)
ERR2 = np.array(ERR2)

plt.errorbar(energie, MPV, yerr=ERR, marker= 'x', markersize=10,
        linewidth=0, elinewidth=1, capsize=2,
        label='Muon', color='red', ecolor='gray') # Messwerte

plt.errorbar(energie2, MPV2, yerr=ERR2, marker= 'x', markersize=10,
        linewidth=0, elinewidth=1, capsize=2,
        label='Proton', color='blue', ecolor='gray') # Messwerte

plt.xlabel(r"$Energy$ / MeV",fontsize='9')
plt.ylabel(r"MPV",fontsize='9')
plt.legend(fontsize='8')
#plt.yscale('log')
plt.xscale('log')
locs, labels = xticks()
#plt.xticks((-20050,0,20050), ('-2e4', '0', '2e4'), size = 10 )
plt.grid()
#plt.show()
plt.savefig("energy_both_ohneProton100.pdf",bbox_inches='tight')
plt.close()
