//============================================================================
// Name        : LocalAlignmentTMScore.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstring>
#include <iostream>

#include "Protein.h"
#include "GroundTruthRoot.h"
#include "HitProtein.h"
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "not enough arguments" << endl;
		cout << "<executable> <type> <proteinName>" << endl;

	}


	if (strcmp(argv[1], "-blaPDB") == 0) {

		HitProtein protein("2JRB_A");
		protein.loadProteinInfo("/home/lihongb/DATABASE/DBInfo/");
		protein.dispProteinInfo();
		int queryStart=38;
		int queryEnd=46;
		string queryPart="E-------EISVKGPN";

		int subjectStart=42;
		int subjectEnd=54;
		string subjectPart="RLLYPAKLSITI---D";
		Point* fetchPart=protein.fetchSubjectAlignedPart3DPointsForQuery( queryStart,  queryEnd,  queryPart,
				 subjectStart,  subjectEnd,  subjectPart);
		//protein.freeProtein();



		GroundTruthRoot groundTruthRoot("T0759");
		groundTruthRoot.setRealSequenceLength(96);
		groundTruthRoot.loadProteinInfo("/home/cf797/test/DATABASE/PDB/");

		cout<<"RMSD is:"<<Protein::calculateRMSD(fetchPart,groundTruthRoot.getCAlpha_XYZ(),queryStart,queryEnd);
	}

	return 0;
}
