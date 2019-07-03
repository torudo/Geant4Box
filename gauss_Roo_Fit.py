from ROOT import TF1, TH1F, TCanvas, gStyle, TH1D
from ROOT import TFile
import ROOT
from array import array
import numpy as np
#import rootnotes

#c1=rootnotes.default_canvas()

w = ROOT.RooWorkspace()
w.factory('Gaussian::g(x[-5,5],mu[-3,3],sigma[1])')
w.factory('Exponential::e(x,tau[-.5,-3,0])')
#w.factory('SUM::model(s[50,0,100]*g,b[100,0,1000]*e)')
w.factory("Landau::landau(t[-10,30],ml[5,-20,20],sl[1,0.1,10])")
w.factory("Gaussian::gauss(t,mg[0],sg[2,0.1,10])")
w.factory('SUM::model(s[50,0,100]*g,b[100,0,100]*g)')
w.factory('SUM::model(s[50,0,100]*g,b[100,0,1000]*g)')
w.Print()

c1 = TCanvas( 'c1', 'A Simple Graph Example', 200, 10, 700, 500 )
c1.SetGrid()


#Definitions of Stuff, Data and functions
x = ROOT.RooRealVar("x","x",-20,30);
mpv = ROOT.RooRealVar("mpv","mpv",1,0.1,4);
width = ROOT.RooRealVar("width","width",1,0.1,10);
landau = ROOT.RooLandau("ld","ld",x,mpv,width);
mean = ROOT.RooRealVar("mean","mean",0.1,0.1,4);
sigma = ROOT.RooRealVar("sigma","sigma",0.5,0.1,10);
gauss = ROOT.RooGaussian("gs","gs",x,mean,sigma);
lxg = ROOT.RooFFTConvPdf("lxg","lxg",x,landau,gauss);

# #Definitions of Stuff, Data and functions
# x = ROOT.RooRealVar("x","x",0,20)
# mean = ROOT.RooRealVar("mean","Mean of Gaussian",-10,10)
# sigma = ROOT.RooRealVar("sigma","Width of Gaussian",3,-10,10)
# meanL = ROOT.RooRealVar("meanL","Mean of Landau",-10,10)
# sigmaL = ROOT.RooRealVar("sigmaL","Width of Landau",3,-10,10)
# mean_lxg = ROOT.RooRealVar("mean_lxg","Mean of lxg",-10,10)
# sigma_lxg = ROOT.RooRealVar("sigma_lxg","Width of lxg",3,-10,10)
# gauss = ROOT.RooGaussian("gauss","gauss(x,mean,sigma)",x,mean,sigma)
# landau = ROOT.RooLandau("land","landau(x,mean,sigma)",x,meanL,sigmaL)
# #makes the convolution out of Gauss and Landau
# lxg = ROOT.RooFFTConvPdf("lxg","landau (X) gauss",x,landau,gauss)

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
c1.Update()
raw_input()
