from __future__ import print_function
import ROOT
from ROOT import TCanvas, TGraph
from ROOT import gROOT
from math import sin
from array import array


c1 = TCanvas( 'c1', 'A Simple Graph Example', 200, 10, 700, 500 )
c1.SetGrid()

n = 100
x, y = array( 'd' ), array( 'd' )
for i in range( n ):
   x.append( i )
   y.append( sin( x[i] ) )
   print(' i %i %f %f ' % (i,x[i],y[i]))

gr = TGraph( n, x, y )

gr.SetTitle( 'a simple graph' )
gr.GetXaxis().SetTitle( 'X title' )
gr.GetYaxis().SetTitle( 'Y title' )
gr.Draw( 'ACP' )
# TCanvas.Update() draws the frame, after which one can change it
c1.Update()
c1.Modified()
c1.Update()
raw_input()
