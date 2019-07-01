//INCLUDES
//C++
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <fstream>

//ROOT
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TMultiGraph.h>
#include <TGraphErrors.h>
#include <TLegend.h>

//Misc
#include "rootstyle.cc"

using namespace std;

int main(int argc, char* argv[])
{
  // Prerequisites
  std::stringstream inputname;

  // First handle the arguments
  //int checkArguments = 0;
  //checkArguments = HandleArguments(argc, argv, inputname,  pdfBool, rootBool, dataBool);
  //if(checkArguments == 1){return 1;}

  // Now open the targetfile and the tree
  TFile *f = new TFile(inputname.str().c_str());
  TTree *MyTree;
  f->GetObject("t",MyTree); //The tree we want to access here is always called "t" in the root file
  // Get the branches
  // Declaration of leaves types
  Double_t        eloss;
  Double_t        edep;
  Double_t        slen;
  // Set branch addresses, connect the variables to the tree
  MyTree->SetBranchAddress("Eloss",&eloss);
  MyTree->SetBranchAddress("Edep",&edep);
  MyTree->SetBranchAddress("SLen",&slen);
  int nentries = MyTree->GetEntries();

  // Now that all the stations are stored in the stationvec, we will loop again and process the data:
  std::map<int, std::vector<double> > dataMap;
  std::map<int, std::vector<double> > errorMap;
  std::map<int, std::vector<double> > timeMap;
    double startingtime;

  for(int i = 0; i < nentries; i++)
    {
      MyTree->GetEntry(i);
      if ( i == 0){startingtime = eloss;} //start value
      else if ( eloss < startingtime ) {startingtime = eloss;}
    }


    for(int i = 0; i < nentries; i++)
        {
          MyTree->GetEntry(i); // get data from the tree and write it to the above declared variables
          ( dataMap[source] ).push_back(eloss);
          ( errorMap[source] ).push_back(eloss);
          ( timeMap[source] ).push_back(seconds - startingtime);
        }


        // in both cases we will need some graphs or multigraphs
        TMultiGraph *mg = new TMultiGraph();
        TGraphErrors *gr[ dataMap.size() ]; // note this is an array, not a vector, simply because the numbering is not important here anymore
        TLegend *legend = new TLegend(0.6, 0.65, 0.8, 0.87);
        legend->SetFillColor(kWhite);

        // Fill them by looping over the maps
        int graphcounter = 0;
        for (std::map<int, std::vector<double> >::iterator iter = dataMap.begin(); iter != dataMap.end(); iter++)
    {
      int size = (iter->second).size();
