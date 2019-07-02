from ROOT import TCanvas, TF1

c1 = TCanvas( 'c1', 'Example with Formula', 200, 10, 700, 500 )

# Create a one dimensional function and draw it
fun1 = TF1( 'fun1', 'abs(sin(x)/x)', 0, 10 )
c1.SetGrid()
fun1.Draw()
raw_input()


# import ROOT
# f = ROOT.TFile.Open("blah.root")
# for event in f.treename :
#       print event.branchName.<do something with it>
