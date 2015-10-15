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

		HitProtein protein("2YIN_B");
		protein.loadProteinInfo("/home/lihongb/DATABASE/DBInfo/");
		protein.dispProteinInfo();
		int queryStart=79;
		int queryEnd=234;
		string queryPart="NRASLYTELGETEKALNDYNTLLIEN---PEHQEALYCRGLLYIQLQNYMWAEQDFDKILEVNEKSVRARLGHAILEKMR--------GNYDESERIFNYLISEMPRDWILYEGRADLYFMMGKNARAMADIEKVFTESEPT-ANLYVLRG-------KIKLAQYEKERAALDFK";
		int subjectStart=20;
		int subjectEnd=189;
		string subjectPart="NLLNFYKDNNREEMYIRYLYKLRDLHLDCDNYTEAAYTL-LLHTWLLKWSD-EQCASQVMQTGQQHPQTHRQLKETLYETIIGYFDKGKMWEEAISLCKELAEQYEMEIFDYELLSQNLIQQAKFYESI---MKILRPKPDYFAVGYYGQGFPSFLRNKVFIYRGKEYERREDFQ";
		Point* fetchPart=protein.fetchSubjectAlignedPart3DPointsForQuery( queryStart,  queryEnd,  queryPart,
				 subjectStart,  subjectEnd,  subjectPart);
		//protein.freeProtein();



		GroundTruthRoot groundTruthRoot("T0821");
		groundTruthRoot.setRealSequenceLength(255);
		groundTruthRoot.loadProteinInfo("/home/cf797/test/DATABASE/PDB/");

		cout<<"RMSD is:"<<Protein::calculateRMSD(fetchPart,groundTruthRoot.getCAlpha_XYZ(),queryStart,queryEnd);
	}

	return 0;
}
