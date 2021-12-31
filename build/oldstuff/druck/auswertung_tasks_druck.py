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
file = sys.argv[1] # takes first argument as filename

energie, MPV, ERR = np.genfromtxt(file,
            usecols=(0,1,2), comments="#",  unpack="True") # opens data ans extract values at lines

energie = np.array(energie)
MPV = np.array(MPV)
ERR = np.array(ERR)

plt.errorbar(energie, MPV, yerr=ERR, marker= 'x', markersize=10,
        linewidth=0, elinewidth=1, capsize=2,
        label='Ar', color='red', ecolor='gray') # Messwerte

plt.xlabel(r"$p$ / pascal",fontsize='9')
plt.ylabel(r"MPV",fontsize='9')
#plt.legend(fontsize='8')
plt.yscale('log')
plt.xscale('log')
locs, labels = xticks()
#plt.xticks((-20050,0,20050), ('-2e4', '0', '2e4'), size = 10 )
plt.grid()
#plt.show()
plt.savefig("temp_doppel_log.pdf",bbox_inches='tight')
plt.close()
