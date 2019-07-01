import ROOT
f1 = ROOT.TF1("f2","[0]*sin([1]*x)/x",0.,10.)
f1.SetParameter(0,1)
f1.SetParameter(1,1)
f1.Draw();
raw_input()
