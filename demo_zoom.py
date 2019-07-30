import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.axes_grid1.inset_locator import zoomed_inset_axes, mark_inset

ax = plt.subplot(111)
ax.set_xlim(0,30)
ax.set_ylim(-1,1)

x = np.arange(0, 100, 0.1)
y = x
X, Y = np.meshgrid(x, y)

Z = X*Y +X +Y

#ax.contour(X, Y, Z)
ax.plot(x,np.sin(x))

axins = zoomed_inset_axes(ax, 5, loc="center")
axins.plot(x,np.sin(x),marker="x")
#axins.contour(X, Y, Z)
axins.set_xlim(13, 15)
axins.set_ylim(0.8, 1)
mark_inset(ax, axins, loc1=2, loc2=4, fc='none')
#plt.xticks(visible=False)
#plt.yticks(visible=False)

plt.show()
