from ROOT import TF1, TH1F, TCanvas, gStyle, TH1D, TTree
from ROOT import TFile
import ROOT
from array import array
import numpy as np
#import rootnotes

f = ROOT.TFile.Open('build/Edep.root', 'read')
# Setup a canvas for plotting. The arguments are a name, an optional title, and the width and height in pixels.
canvas = ROOT.TCanvas('canvas', '', 500, 500)
hist = f.Get('Edep')
length = hist.GetEntries()
#canvas.SaveAs('plot.pdf')
#bins = [hist.GetSize()]
#for i in xrange(len(bins)):#
#    print(bins[i])
bins = hist.GetArray()
x=[]
print(bins)
for i in xrange(0,len(bins)):
    x.append(bins[i])
print(x)

f.Close()


#Getting the data in the Tree
# tree = ROOT.TTree("tree","tree")
# x = np.zeros(1,dtype=float)
# tree.Branch("x",x,'x/D')
# for i in range(10000):
#     x[0] = np.random.normal(0,3,1)
#     tree.Fill()
#data = ROOT.RooDataSet("data","dataset from tree",tree,ROOT.RooArgSet(x))
