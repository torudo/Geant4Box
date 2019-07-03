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

#int k = h->GetXaxis()->FindBin(x);
x=[]
for k in xrange(0,100):
    x.append(hist.GetBinContent(k))

print(x)
f.Close()
exit()
#bins = hist.GetArray()
#x=[]
#print(bins)
#for i in xrange(0,len(bins)):
#    x.append(bins[i])

x = ROOT.RooRealVar("x","x",-20,30);
mpv = ROOT.RooRealVar("mpv","mpv",1,0.1,4);
width = ROOT.RooRealVar("width","width",1,0.1,10);
landau = ROOT.RooLandau("ld","ld",x,mpv,width);
mean = ROOT.RooRealVar("mean","mean",0.1,0.1,4);
sigma = ROOT.RooRealVar("sigma","sigma",0.5,0.1,10);
gauss = ROOT.RooGaussian("gs","gs",x,mean,sigma);
lxg = ROOT.RooFFTConvPdf("lxg","lxg",x,landau,gauss);

#TestData
data = lxg.generate(ROOT.RooArgSet(x),10000)

result = gauss.fitTo(data,ROOT.RooFit.PrintLevel(-1))
resultL = landau.fitTo(data,ROOT.RooFit.PrintLevel(-1))
result_lxg = lxg.fitTo(data,ROOT.RooFit.PrintLevel(-1))

xframe = x.frame()
data.plotOn(xframe,ROOT.RooFit.Binning(25))
gauss.plotOn(xframe)
sigma.setVal(0.2)
landau.plotOn(xframe,ROOT.RooFit.LineColor(2))
lxg.plotOn(xframe,ROOT.RooFit.LineColor(3))

xframe.Draw()


#Getting the data in the Tree
# tree = ROOT.TTree("tree","tree")
# x = np.zeros(1,dtype=float)
# tree.Branch("x",x,'x/D')
# for i in range(10000):
#     x[0] = np.random.normal(0,3,1)
#     tree.Fill()
#data = ROOT.RooDataSet("data","dataset from tree",tree,ROOT.RooArgSet(x))
