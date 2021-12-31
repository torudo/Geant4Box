import numpy as np
import ROOT
y = np.array([2., 2., 11., 0., 5., 7., 18., 12., 19., 20., 36., 11., 21., 8., 13., 14., 8., 3., 21., 0., 24., 0., 12., 0., 8., 11., 18., 0., 9., 21., 17., 21., 28., 36., 51., 36., 47., 69., 78., 73., 52., 81., 96., 71., 92., 70., 84.,72., 88., 82., 106., 101., 88., 74., 94., 80., 83., 70., 78., 85., 85., 56., 59., 56., 73., 33., 49., 50., 40., 22., 37., 26., 6., 11., 7., 26., 0., 3., 0., 0., 0., 0., 0., 3., 9., 0., 31., 0., 11., 0., 8., 0., 9., 18.,9., 14., 0., 0., 6., 0.])
x = np.arange(0,len(y),1)
#yerr= np.array([0.1,0.2,0.1,0.2,0.2])
graph = ROOT.TGraphErrors()
for i in range(len(y)):
    graph.SetPoint(i, x[i], y[i])
    #graph.SetPointError(i, yerr[i], yerr[i])
func = ROOT.TF1("Name", "gaus")
graph.Fit(func)
canvas = ROOT.TCanvas("name", "title", 1024, 768)
graph.GetXaxis().SetTitle("x") # set x-axis title
graph.GetYaxis().SetTitle("y") # set y-axis title
graph.Draw("AP")
raw_input()
