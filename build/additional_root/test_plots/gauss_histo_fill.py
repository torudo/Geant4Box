from ROOT import gRandom,TCanvas,TH1F,gStyle
from array import array

def langaus_data(hpx):
    data = array('f', (0,0,0,0,0,0,2,6,11,18,18,55,90,141,255,323,454,563,681,
            737,821,796,832,720,637,558,519,460,357,291,279,241,212,
            153,164,139,106,95,91,76,80,80,59,58,51,30,49,23,35,28,23,
            22,27,27,24,20,16,17,14,20,12,12,13,10,17,7,6,12,6,12,4,
            9,9,10,3,4,5,2,4,1,5,5,1,7,1,6,3,3,3,4,5,4,4,2,2,7,2,4) )
    for i in xrange(len(data)):
        px = data[i]
        hpx.Fill(px)
    return data

c1 = TCanvas('c1','Example',200,10,700,500)
c1.SetGrid()
hpx = TH1F('hpx','px',400,0,400)
langaus_data(hpx)
hpx.Draw()
gStyle.SetOptStat(1111)
gStyle.SetOptFit(111)
c1.Update()
raw_input('Press  <ret> to end -> ')
