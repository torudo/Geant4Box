from ROOT import TF1, TH1F, TCanvas, gStyle
from ROOT import TFile
import ROOT
from array import array


#open the file
myfile = TFile('build/Edep.root')
hist = myfile.Edep
myfile.ls()
myfile.Edep.Draw()
raw_input()
myfile.Eloss.Draw()
raw_input()
myfile.StepL.Draw()
raw_input()
print(myfile)
print(hist)
myCanvas = TCanvas("c1")
myCanvas.SetGrid()
hist.Draw()

hist.Fit("gaus")
#hist = f.Get(hn)
# nbins = hist.GetSize()-2
# # Get mean and standard deviation for Gauss - Landau initial parameterization
# mean   = hist.GetMean()
# sigma  = hist.GetStdDev()
#
# # Construct observable
# minX,maxX = hist.GetXaxis().GetBinLowEdge(1), hist.GetXaxis().GetBinUpEdge(nbins)
# t = ROOT.RooRealVar("t","t", minX, maxX)
#
# # Construct gauss(t,mg,sg)
# mg = ROOT.RooRealVar("Gauss - mean","mg",0)
# sg = ROOT.RooRealVar("Gauss - sigma","sg",sigma,0.1*sigma,5.*sigma)
# gauss = ROOT.RooGaussian("gauss","gauss",t,mg,sg)
#
# # Construct landau(t,ml,sl)
# ml = ROOT.RooRealVar ("Landau - mean","mean landau",mean,mean-sigma,mean+sigma)
# sl = ROOT.RooRealVar ("Landau - sigma","sigma landau",0.04,0.,0.2)
# landau = ROOT.RooLandau ("lx","lx",t,ml,sl)
#
# # C o n s t r u c t   c o n v o l u t i o n   p d f
#     # ---------------------------------------
#
# # Set #bins to be used for FFT sampling
# t.setBins(5000,"cache")
#
# # Construct landau (x) gauss
# lxg = ROOT.RooFFTConvPdf("lxg","landau (X) gauss",t,landau,gauss)
# landau.Draw()
# S a m p l e ,   f i t   a n d   p l o t   c o n v o l u t e d   p d f
# ----------------------------------------------------------------------

#tofit = ROOT.RooDataHist("dh", "dh", ROOT.RooArgList(t),hist)
#tofit = lxg.asTF(ROOT.RooArgList(t), ROOT.RooArgList(), ROOT.RooArgSet(t))

# Fit lxg to data
#lxg.fitTo(tofit);

# Plot data, landau pdf, landau (X) gauss pdf
#xframe = t.frame()
#tofit.Draw()
#lxg.plotOn(xframe)
#xframe.GetYaxis().SetTitle('au')
#xframe.GetXaxis().SetTitle('#DeltaE/#Deltax [MeV/mm]')
#xframe.GetYaxis().SetTitleOffset(1.4)

# Calculate chi2
#chi2 = xframe.chiSquare(3)
#print 'chi2 =', chi2

myCanvas.Update()
#myCanvas.Write()
#myCanvas.Print("Eloss.pdf");





"""__Main__"""
raw_input('Press  <ret> to end -> ')
