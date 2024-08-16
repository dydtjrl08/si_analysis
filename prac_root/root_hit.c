void root_hit(){
	

	TFile *file = new TFile("RUN528.hit.root","READ");

	TTree *tree = (TTree *)file -> Get("hit");
	
	Short_t det1;
	Short_t dch1;
	Short_t adc1;
	Short_t det2;
	Short_t dch2;
	Short_t adc2;
	

	tree -> SetBranchAddress("det1",&det1);
	tree -> SetBranchAddress("det2",&det2);
	tree -> SetBranchAddress("dch1",&dch1);
	tree -> SetBranchAddress("dch2",&dch2);
	tree -> SetBranchAddress("adc1",&adc1);
	tree -> SetBranchAddress("adc2",&adc2);

	TCanvas *c1 = new TCanvas("test","2d",1200,800);	
	
	for(int i = 1; i < 17 ; i++){		
//		cout << tree -> GetEntries("det1 == 1") << endl;	
//		cout << tree -> GetEntries("det1 == 2") << endl;	
//		cout << tree -> GetEntries("det2 == 1") << endl;	
//		cout << tree -> GetEntries("det2 == 2") << endl;	
//		cout << tree -> GetEntries("det1 == 2") << endl;	
		TString namehist = Form("det1 == %d",2);
		TH2I *hist = new TH2I(namehist,"q",8000,0,8000,8000,0,8000);
		tree -> Draw("adc2:adc1",namehist);
		c1 -> SaveAs(Form("det1_2_dch2_%d.jpg",i));
	}

}
