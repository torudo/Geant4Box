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

from mpl_toolkits.axes_grid1.inset_locator import zoomed_inset_axes, mark_inset


#Für die Latexschrift
#matplotlib.rcParams['text.usetex'] = True #macht den plot erheblich langsamer!
matplotlib.rcParams['font.family'] = 'sans-serif'
matplotlib.rcParams['font.serif'] = 'Palatino'
matplotlib.rcParams['font.size'] = 16
#matplotlib.rcParams['text.latex.preamble'] = [r'\usepackage{siunitx}']

# linear function
def linea(x, b0, b1):
    return b0 + b1*x

###################################### Data Setup ############################
file = r"C:\Users\tobys\Documents\GitHub\Geant4Box\build\Dichte\dichte.txt"# takes first argument as filename

a1 = 12 #breite
b1 = 6 #höhe
fig=plt.figure(figsize=(a1,b1))
ax = plt.gca()

energie, MPV, ERR = np.genfromtxt(file,
            usecols=(0,1,2), comments="#",  unpack="True") # opens data ans extract values at lines

energie = np.array(energie)
MPV = np.array(MPV)
ERR = np.array(ERR)


#Linearer Fit to data
fitdata=[1,1]
fitdata, covlinea = curve_fit(linea, energie, MPV, p0=fitdata)
err_coef = np.sqrt(np.diag(covlinea))

X = np.linspace(0, np.max(energie), len(energie)+1000 , endpoint=True)


plt.plot(X, linea(X,*fitdata), label='Fit', color='#009E73', alpha = 0.5) # Fit plot

plt.errorbar(energie, MPV, yerr=ERR*100, marker= 'x', markersize=10,
        linewidth=0, elinewidth=1, capsize=2,
        label='Ar', color='red', ecolor='gray') # Messwerte

textstr = '\n'.join((
r"m: {0:1.1f} $\pm$ {1:0.1f}".format(fitdata[0], err_coef[0]), #, np.abs(100*(err_coef[0])/(fitdata[0]))),
r"n: {0:1.1f} $\pm$ {1:0.1f}".format(fitdata[1], err_coef[1])# np.abs(100*(err_coef[1])/(fitdata[1])))
))
# these are matplotlib.patch.Patch properties
props = dict(boxstyle='round', facecolor='white', alpha=0.5)

# place a text box in upper left in axes coords
ax.text(0.05, 0.95, textstr, transform=ax.transAxes, fontsize=14,
        verticalalignment='top', bbox=props)


plt.xlabel(r"$density$ / mg/cm$^3$",fontsize='16')
plt.ylabel(r"$MPV$",fontsize='16')
#plt.legend(fontsize='16')
#plt.yscale('log')
#plt.xscale('log')
locs, labels = xticks()
#plt.xticks((-20050,0,20050), ('-2e4', '0', '2e4'), size = 10 )
#plt.grid()

ax.yaxis.set_major_locator(MultipleLocator(5000))
ax.yaxis.set_minor_locator(MultipleLocator(1000))

ax.xaxis.set_major_locator(MultipleLocator(2))
ax.xaxis.set_minor_locator(MultipleLocator(0.5))

ax.grid(which='major', axis='both', linestyle='--',alpha=0.5)# lw = 0.5)
ax.tick_params(direction='in', length=6, width=2)
ax.tick_params(which='minor',direction='in', length=4)

x0, y0, width, height = 530, 75, 0, 0
axins = zoomed_inset_axes(ax, 7, loc="lower left", bbox_to_anchor=(x0, y0, width, height))


axins.plot(X, linea(X,*fitdata), label='Fit', color='#009E73', alpha = 0.5) # Fit plot

axins.errorbar(energie, MPV, yerr=ERR, marker= 'x', markersize=10,
        linewidth=0, elinewidth=1, capsize=2,
        label='Ar', color='red', ecolor='gray') # Messwerte

axins.yaxis.set_major_locator(MultipleLocator(1000))
axins.yaxis.set_minor_locator(MultipleLocator(500))

axins.xaxis.set_major_locator(MultipleLocator(0.5))
axins.xaxis.set_minor_locator(MultipleLocator(0.1))
axins.tick_params(direction='in', length=6, width=2)
axins.tick_params(which='minor',direction='in', length=4)

#axins.contour(X, Y, Z)
axins.set_xlim(0, 1.6)
axins.set_ylim(0, 2000)
mark_inset(ax, axins, loc1=2, loc2=3, fc='none')

mark_inset(ax, axins, loc1=2, loc2=3, fc="none", ec="0.5")

#plt.show()
plt.savefig("build\Dichte\densy.pdf",bbox_inches='tight')
plt.close()
