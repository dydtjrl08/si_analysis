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
		
		TString namehist = Form("det1 == 2 && dch2 == %d",i);
		TH2D *hist = new TH2D(namehist,Form("dch2 == %d",i),1000,0,8000,1000,0,3200);
		tree -> Draw("adc2:adc1",namehist);
		c1 -> SaveAs(Form("det1_1_dch2_%d.jpg",i));
	}

}
