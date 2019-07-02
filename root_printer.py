from ROOT import TF1, TH1F, TCanvas

from ROOT import TFile

# open the file
myfile = TFile('build/Edep.root')
myfile.ls()
myfile.Edep.Draw()
raw_input()
myfile.Eloss.Draw()
raw_input()
myfile.StepL.Draw()
raw_input()
# class Linear:
#     def __call__( self, x, par ):
#         return par[0] + x[0]*par[1]
#
# # create a linear function for fitting
# f = TF1('pyf3',Linear(),-1.,1.,2)
#
# # create and fill a histogram
# h = TH1F('h','test',100,-1.,1.)
# f2 = TF1('cf2','6.+x*4.5',-1.,1.)
# h.FillRandom('cf2',10000)
#
# # fit the histo with the python 'linear' function
# h.Fit(f)
#
# # print results
# par = f.GetParameters()
# print('fit results: const =', par[0], ',pitch =', par[1])
# raw_input()
