//Defines the root style for the pdf output
#include <TStyle.h>
#include <TROOT.h>

void SetROOTStyle()
{
  gStyle->SetOptStat(1111);
  gStyle->SetOptFit(111);
  gStyle->SetLabelOffset(1.,"y");
  //gStyle->SetOptStat(0);
  gStyle->SetLabelSize(0.045,"xyz");
  gStyle->SetTitleSize(0.055,"xyz");
  gStyle->SetTitleOffset(0.85,"x");
  gStyle->SetTitleOffset(1.6,"y");
  gStyle->SetTitleOffset(1.,"z");
  gStyle->SetOptFit(0101);
  gStyle->SetStatX(0.54);
  gStyle->SetStatY(0.88);
  gStyle->SetStatW(0.22);
  gStyle->SetStatH(0.12);
  gStyle->SetPadLeftMargin(0.125);
  gStyle->SetPadRightMargin(0.15);
  gStyle->SetPadBottomMargin(0.1);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gROOT->ForceStyle();
}
