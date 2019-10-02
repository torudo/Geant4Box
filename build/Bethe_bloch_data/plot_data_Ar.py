"""
Calculation of Bethe-Bloch energy loss with:
- density correction
- cut off energy
MPV calculation with Landau theory
"""

from math import sqrt, log
sqr = lambda x: x*x
import matplotlib.pyplot as plt
import numpy as np

def sqrare(x):
	return x**2

""" Constants and formulas to be used for pion """
K = 0.307075 # constant K in MeV cm mol^-1
z = 1 # charge in e
Z = 18 # Atomic number Z
#u =1.661e-24
A = 39.948#28.09 # Atomic mass in g mol-1
Z_over_A = np.float(Z/A) # Silicon
M = 938.27#139.6 # Mass of heavy particle in MeV
m_e = 0.511 # Mass of electron in MeV
#rho = 1.784e-3#2.336 # Density of material in g cm^-3 (here: silicon density)
rho = 0.00166201  #0.784e-3#2.336 # Density of material in g cm^-3 (here: silicon density)
 #0.00166201  0.000838505        137
gamma = lambda p: sqrt(1 + sqr(p / M))
beta = lambda p: sqrt(1 - 1 / sqr(gamma(p)))
beta_gamma = lambda p: p / M
T_max = lambda p: 2 * m_e * sqr(beta_gamma(p)) / (1 + 2 * gamma(p) * m_e / M + sqr(m_e / M)) # Maximum energy transfer in one collision in MeV
h_omega_p = 0.00003105 # Plasma energy in MeV

T_kin_heavy = lambda p: sqrt( sqr(p) + sqr(M) ) - M

T_cut = 0.08 # Cut energy due to finite thickness of absorber in MeV
I = 137*1e-6 # Ionisation energy in MeV

""" Constants of density correction """
C = 4.44
a = 0.1492
m = 3.25
X1 = 2.87
X0 = 0.2014
delta0 = 0.14
X = lambda p: np.log10(beta_gamma(p))
#f1 = lambda x: delta0 * 10**(2*(x-X0)) # conductors pdg
f1 = lambda x: 0 # non conductors pdg
f2 = lambda x: 2 * x * np.log(10) - C + (a * ((X1 - x)**m))
f3 = lambda x: 2 * x * np.log(10) + C
delta_full = lambda x: np.piecewise(x, [x < X0 , x >= X0], [f1, f2])


""" Thickness of absorber """
thickness_um = 1e4
x = thickness_um/10000.0  # x in cm

epsilon = (K * rho * Z * x) / (2 * A) # Has to have units MeV
#print( 'epsilon = ', epsilon)
E_mean_delta_corr = lambda p:  epsilon * (log(2 * m_e * T_max(p) * sqr(beta_gamma(p)) / sqr(I)) - 2 * sqr(beta(p)) - delta_full( X(p) ) ) / sqr(beta(p)) #
E_mean = lambda p:  epsilon * (log(2 * m_e * T_max(p) * sqr(beta_gamma(p)) / sqr(I)) - 2 * sqr(beta(p)) ) / sqr(beta(p)) #
E_mean_delta_corr_Tcut = lambda p:  epsilon * (log(2 * m_e * T_cut * sqr(beta_gamma(p)) / sqr(I)) - 2 * sqr(beta(p)) * (1 + T_cut/T_max(p)) - delta_full( X(p) ) ) / sqr(beta(p)) #

E_MPV_LVB = lambda p:  epsilon * ( log( ( 2 * m_e * sqr( beta_gamma(p) ) ) / I ) + log( epsilon / ( I * sqr(beta(p)) ) ) +  0.2 - sqr( beta(p) ) - delta_full( X(p) ) )  / sqr(beta(p)) # pdg

E_MPV_limit = lambda p:  epsilon * ( log( ( 2 * m_e * epsilon ) / sqr(h_omega_p) )  +  0.2 )



"""  Simulated Data  """

#windwos
file = r'C:\Users\tobys\Documents\GitHub\Geant4Box\build\Bethe_Bloch\Ar\Ar_BB.txt' # takes first argument as filename

file2 = r'C:\Users\tobys\Documents\GitHub\Geant4Box\build\Bethe_bloch_data\bethe_arg_val.txt' # takes first argument as filename


energie, MPV, ERR = np.genfromtxt(file,
	usecols=(0,1,2), comments="#",  unpack="True") # opens data ans extract values at lines

energie = np.array(energie)
MPV = np.array(MPV)
ERR = np.array(ERR)


th_energie, th_MPV = np.genfromtxt(file2,
	usecols=(0,1), comments="#",  unpack="True") # opens data ans extract values at lines


""" Plot Bethe versus momentum """

fig, ax1 = plt.subplots()
fig.patch.set_facecolor('white')
fig.set_size_inches(8,6)
my_font = 16
plt.tick_params(axis='both', which='major', labelsize=my_font)

#ax1.plot(ps_GeV, E_means, label='Bethe no correction', marker='.', color='Black', linestyle='', linewidth=2)
#ax1.plot(ps_GeV, E_MPVs_Landau, label='MPV Landau Ar', marker='', color='gray', linestyle='-', linewidth=2)
#ax1.plot(ps_GeV, E_mean_density_corr_Tcut, label='Bethe Tcut = 60 keV', marker='', color='DarkGreen', linestyle=':', linewidth=2)
#ax1.plot(ps_GeV, E_MPVs_Landau_limit, label='MPV Landau Limit', marker='', color='Gray', linestyle='-', linewidth=2)
#ax1.plot(ps_GeV, E_mean_density_corr, label='Bethe density correction', marker='', color='Red', linestyle='--', linewidth=2)

plt.plot(th_energie,th_MPV,marker="x",label="theoretical")

plt.errorbar(energie, MPV, yerr=ERR, marker= 'x', markersize=10,
linewidth=0, elinewidth=1, capsize=2,
label='Ar', color='red', ecolor='gray') # Messwerte

plt.grid(True, which="both", ls="-", color='0.65')
#plt.axvline(120000, label = '120 GeV pions', color='Gray', linewidth=5)
ax1.set_xscale('log')
plt.ylabel('Energy loss in 1 cm Ar in keV / g/cm$^2$', fontsize = my_font)
plt.xlabel(r'$\beta \gamma$', fontsize = my_font)
plt.ylim(0,7)
plt.xlim(10,2e6)
plt.legend(loc='upper right')
#plt.xlim(0, 700)

#ax2 = ax1.twinx()
#energy_to_charge = 3.6
#s2 = np.divide(E_MPVs_Landau, energy_to_charge)
#ax2.plot(ps_GeV, s2, marker='', color='Blue', linestyle='-', linewidth=2)
#ax2.set_ylim(10/energy_to_charge, 45/energy_to_charge)
#ax2.set_ylabel('Signal in 1000 e/h pairs', fontsize = my_font)
#plt.tick_params(axis='both', which='major', labelsize=my_font)
#plt.tight_layout()
#plt.savefig('Bethe-for-thickness-'+str(thickness_um)+'um-heavy.png')
#plt.savefig('Bethe-for-thickness-'+str(thickness_um)+'um-heavy.svg')

#print(energie)


#plt.show()

plt.savefig(r'C:\Users\tobys\Documents\GitHub\Geant4Box\build\Bethe_bloch_data\Bethe_B_Ar_low_beta.pdf')
plt.clf()
plt.close()
