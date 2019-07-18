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

#Für die Latexschrift
#matplotlib.rcParams['text.usetex'] = True #macht den plot erheblich langsamer!
matplotlib.rcParams['font.family'] = 'sans-serif'
matplotlib.rcParams['font.serif'] = 'Palatino'
matplotlib.rcParams['font.size'] = 16
#matplotlib.rcParams['text.latex.preamble'] = [r'\usepackage{siunitx}']

# linear function
def linea(x, b0, b1):
    return b0 + b1*x
# Plotbereiche
###################################### Data Setup ############################
#file = sys.argv[1] # takes first argument as filename
file = "/home/rudolph/Geant4Box/build/rightZ/Z_eloss.txt" # takes first argument as filename

a1 = 12 #breite
b1 = 6 #höhe
fig=plt.figure(figsize=(a1,b1))
ax = plt.gca()
energie, MPV, ERR = np.genfromtxt(file,
            usecols=(0,1,2), comments="#",  unpack="True") # opens data ans extract values at lines

energie = np.array(energie)
MPV = np.array(MPV)
ERR = np.array(ERR)

X = np.linspace(0, max(energie), len(MPV)+1000 , endpoint=True)

#Linearer Fit to data
fitdata = [1,1]
fitdata, covlinea = curve_fit(linea, energie, MPV, p0=fitdata, sigma=ERR)
err_coef = np.sqrt(np.diag(covlinea))

plt.plot(X, linea(X,*fitdata), label='Fit', color='#009E73') # Fit plot
plt.errorbar(energie, MPV, yerr=ERR*100, marker= 'x', markersize=6,
        linewidth=0, elinewidth=1, capsize=2,
        label='Ar', color='red', ecolor='gray') # Messwerte

# Labeling, transform fixes label on figure
# textstr = '\n'.join((
#     r'$\mu=%.2f$' % (mu, ),
#     r'$\mathrm{median}=%.2f$' % (median, ),
#     r'$\sigma=%.2f$' % (sigma, )))
textstr = '\n'.join((
r"m: {0:1.1f} $\pm$ {1:0.1f}".format(fitdata[0], err_coef[0]), #, np.abs(100*(err_coef[0])/(fitdata[0]))),
r"n: {0:1.1f} $\pm$ {1:0.1f}".format(fitdata[1], err_coef[1])# np.abs(100*(err_coef[1])/(fitdata[1])))
))
# these are matplotlib.patch.Patch properties
props = dict(boxstyle='round', facecolor='white', alpha=0.5)

# place a text box in upper left in axes coords
ax.text(0.05, 0.95, textstr, transform=ax.transAxes, fontsize=14,
        verticalalignment='top', bbox=props)

#plt.text(0.63, 0.21, "a"+str(0)+": {0:1.2e} +/- {1:1.2e} ({2:1.1f})".format(fitdata[0], np.sqrt(error_coeffizienten[0]**2), np.abs(100*(error_coeffizienten[0])/(fitdata[0]+fitdata[0]))), transform=fig.transFigure,fontsize='12')
#plt.text(0.63, 0.18, "a"+str(1)+": {0:1.2e} +/- {1:1.2e} ({2:1.1f})".format(fitdata[1], np.sqrt(error_coeffizienten[1]**2), np.abs(100*(error_coeffizienten[1])/(fitdata[1]+fitdata[1]))), transform=fig.transFigure,fontsize='12')


plt.xlabel(r"$Z$",fontsize='16')
plt.ylabel(r"MPV",fontsize='16')
#plt.legend(fontsize='8')
#plt.yscale('log')
#plt.xscale('log')
locs, labels = xticks()
#plt.xticks((-20050,0,20050), ('-2e4', '0', '2e4'), size = 10 )
#ax.grid(axis="x")
ax.grid(which='major', axis='both', linestyle='--',alpha=0.5)# lw = 0.5)
plt.show()
#plt.savefig("Z.pdf",bbox_inches='tight')
#plt.close()
