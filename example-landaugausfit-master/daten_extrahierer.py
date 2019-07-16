#Auswertung einer Aufgabe, wertet alle Root dokuemnte in einem Ordner mit Aus
#nimmt werde aus den Fits und packt sie in eine datei

import ROOT
from ROOT import gStyle
from langaus import LanGausFit
import sys
import os

def schreibeInDatei(datei_name, energie, MPV, STDV):
    #Wenn die Datei nicht existiert soll die erste Zeile geruckt werden, sonst nicht
    try:
        with open(datei_name) as f_obj:
            print()
    except FileNotFoundError:
        with open(datei_name, 'a') as f_obj:
            f_obj.write("#  Energie/ MeV\t MPV\t STDV\n" +"\t" +energie +"\t" +MPV +STDV +"\n")
    else:
        with open(datei_name, 'a') as f_obj:
            f_obj.write(energie +"\t" +MPV +STDV +"\n")

#newpath = r'Test'
path = sys.argv[1] #Ordner
dirs = os.listdir( path )

for dateien in dirs:
    if dateien[-5:]==".root":
        print(dateien)
        #macht aus DAteinamen Energie
        name_zerlegt = dateien.split("_")
        energie = name_zerlegt[6]
        print(energie)
        #reed a histogram
        myfile = ROOT.TFile(path+"/"+dateien)
        print("Eloss")
        c1 = ROOT.TCanvas('canvas', '', 1200, 800)
        hist = myfile.Eloss
        myfile.Close()
        hist.Draw()
        gStyle.SetTitleOffset(1.4,"y")
        gStyle.SetOptFit(111)
        gStyle.SetOptStat(1111)
        #hist.GetXaxis().SetRange(0,100);

        # fit the histogram
        fit = LanGausFit()
        func = fit.fit(hist)
        param = func.GetParameters()#gets the Fit parameter
        #print(param[1]) #prints out the MPV
        MPV = param[1]
        STDV = param[2]
        # The fitter return a ROOT TF1 (a 1D function).
        #func.Print()
        #schreibeInDatei(datei_name, energie, MPV, STDV)
        func.Draw("SAME")
        c1.Update()
        c1.Print(path+"/"+"Eloss_"+dateien+".pdf")

################################################################################
#Edep
#c2 = ROOT.TCanvas('canvas', '', 1200, 800)
#hist = myfile.Edep
#hist.GetXaxis().SetRange(0,100);
#hist.Draw()
#gStyle.SetTitleOffset(1.4,"y")
#gStyle.SetOptFit(111)
#gStyle.SetOptStat(1111)

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
#fit = LanGausFit()
#func = fit.fit(hist)
#func.SetLineColor(4)
#param = func.GetParameters()#gets the Fit parameter
#print(param[1]) #prints out the MPV

# The fitter return a ROOT TF1 (a 1D function).
#func.Print()
#func.Draw("SAME") # bei mehreren Plots muss SAME angegeben werden
#c2.Update()
#c2.Print(path+"Edep_"+dateiname+".pdf")

raw_input("Press anything to end.")
