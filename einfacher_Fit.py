from ROOT import TF1, TH1F, TCanvas, gStyle, TH1D, TTree
from ROOT import TFile
import ROOT
from array import array
import numpy as np
#import rootnotes

c1 = TCanvas( 'c1', 'A Simple Graph Example', 200, 10, 700, 500 )
c1.SetGrid()


myfile = TFile('build/Edep.root')
hist = myfile.Eloss
fitfunc = TF1("fitfunc", "landau(0)",0,1000)
fitfunc.SetParameter(0,5)
fitfunc.SetParameter(0,5)
hist.Fit("fitfunc")
hist.Draw()

fitfunc2 = TF1("fitfunc2", "gaus(0)",0,1000)
hist.Fit("fitfunc2")
fitfunc2.Draw("SAME")

gStyle.SetOptFit()



c1.Update()
raw_input()



#Getting the data in the Tree
# tree = ROOT.TTree("tree","tree")
# x = np.zeros(1,dtype=float)
# tree.Branch("x",x,'x/D')
# for i in range(10000):
#     x[0] = np.random.normal(0,3,1)
#     tree.Fill()
#data = ROOT.RooDataSet("data","dataset from tree",tree,ROOT.RooArgSet(x))
