


void constant_merging(){

//	TFile *file1 = new TFile("test1.root","RECREATE");
//	TFile *file2 = new TFile("test2.root","RECREATE");

	TFile *file1 = TFile::Open("constant_test.root","UPDATE");	

	TFile *root_file_det1 = new TFile("constant_of_det1.root","READ");	
	
	TTree *tree1 = (TTree *)file1 -> Get("t1");
//	Short_t oldBranchValue;	
	TTree *tree2 = (TTree *)root_file_det1 -> Get("tree");
	
	Double_t a;
	Short_t det;	
	Short_t dch;	
	
	tree2 -> SetBranchAddress("a",&a);
	tree2 -> SetBranchAddress("det",&det);
	tree2 -> SetBranchAddress("dch",&dch);
		
	Double_t a1;
	Short_t det1;	
	Short_t dch1;	
	tree1 -> SetBranchAddress("a",&a1);
	tree1 -> SetBranchAddress("det",&det1);
	tree1 -> SetBranchAddress("dch",&dch1);


	Double_t nentries = tree2 -> GetEntries();
	for(int i = 1; i <= nentries;i++){
		tree2 -> GetEntry(i);
		a1 = a;
		det1 = det;
		dch1 = dch;

		tree1 -> Fill();

	}
	tree1 -> Scan();	
	
	file1 -> Write();

//	tree1 -> CopyEntries(tree2);

//	file1 -> Write();
	
/*	Double_t a;
	Short_t det;
	Short_t dch;




	TH1F *h1 = new TH1F("h1","hist1",100,-10,10);
	h1 -> FillRandom("gaus",100);
	
	file1 -> Write();	

*/

}





//	TH1F *h2 = new TH1F("h2","hist2",100,-10,10);

//	h2 -> FillRandom("gaus",200);

//	file2 -> cd();
//	file2 -> Write();
	

//}
