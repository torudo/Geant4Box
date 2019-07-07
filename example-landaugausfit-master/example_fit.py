import ROOT
from ROOT import gStyle
from langaus import LanGausFit
import sys
import os

dateiname = sys.argv[1]

#newpath = r'Test'
newpath = sys.argv[1]
if not os.path.exists(newpath):
    os.makedirs(newpath)

path = newpath+"/"

#path= sys.argv[1]

#reed a histogram
myfile = ROOT.TFile('../build/Edep.root')
myfile.ls()

print("Eloss")
c1 = ROOT.TCanvas('canvas', '', 1200, 800)
hist = myfile.Eloss
hist.Draw()
gStyle.SetTitleOffset(1.4,"y")
gStyle.SetOptFit(111)
gStyle.SetOptStat(1111)
#hist.GetXaxis().SetRange(0,100);

# fit the histogram
fit = LanGausFit()
#func = fit.fit(hist)

# The fitter return a ROOT TF1 (a 1D function).
#func.Print()
#func.Draw("SAME")

c1.Update()
c1.Print(path+"Eloss_"+dateiname+".pdf")

################################################################################
c2 = ROOT.TCanvas('canvas', '', 1200, 800)
hist = myfile.Edep
#hist.GetXaxis().SetRange(0,100);
hist.Draw()
gStyle.SetTitleOffset(1.4,"y")
gStyle.SetOptFit(111)
gStyle.SetOptStat(1111)

#Landau udn Gaus fit, visualisierung
# fitfunc = ROOT.TF1("fitfunc", "landau(0)",0,1000)
# hist.Fit(fitfunc)
# fitfunc.Draw("SAME")
#
# fitfunc2 = ROOT.TF1("fitfunc_gaus", "gaus(0)",0,1000)
# hist.Fit(fitfunc2)
# fitfunc2.Draw("SAME")
# fitfunc2.SetLineColor(1)

# fit the histogram
fit = LanGausFit()
#func = fit.fit(hist)
#func.SetLineColor(4)
#param = func.GetParameters()#gets the Fit parameter
#print(param[1]) #prints out the MPV

# The fitter return a ROOT TF1 (a 1D function).
#func.Print()
#func.Draw("SAME") # bei mehreren Plots muss SAME angegeben werden
c2.Update()
c2.Print(path+"Edep_"+dateiname+".pdf")


################################################################################
c3 = ROOT.TCanvas('canvas', '', 1200, 800)
hist_Step = myfile.StepL

hist_Step.Draw("B")

c3.Update()
c3.Print(path+"StepL_"+dateiname+".pdf")

myfile.Close()
# copies the Root File into the Folder
os.system("cp ../build/Edep.root "+path)
raw_input()
