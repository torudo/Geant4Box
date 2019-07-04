import ROOT
from langaus import LanGausFit
# create a histogram
#histogram = ROOT.TH1D("hist", "hist", 100, 0.0, 10.)
#histogram.FillRandom("gaus", 1000)

#reed a histogram
myfile = TFile('build/Edep.root')
hist = myfile.Eloss

# fit the histogram
fit = LanGausFit()
func = fit.fit(hist)

# The fitter return a ROOT TF1 (a 1D function).
func.Print()

func.Draw()
raw_input()
