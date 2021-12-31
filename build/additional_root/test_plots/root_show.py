import ROOT
import sys

dateiname = sys.argv[1]

f = ROOT.TFile(dateiname)
hist = f.Eloss
#hist.SetAxisRange(0., 50.,"X")
#hist.SetAxisRange(0., 1000.,"Y")
#hist.SetAxisRange(0., 100.,"X")
#hist.GetYaxis().SetRange(0,400)
#hist.GetXaxis().SetRange(0,500)
hist.Draw()
raw_input()
