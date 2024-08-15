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

	
		
	TH2D *hist = new TH2D("hist","total",1000,0,8000,1000,0,3200);
	for(int i = 0; i < tree -> GetEntries(); i++){	
		tree -> GetEntry(i);
		hist -> Fill(adc1,adc2);

	}
	c1 -> cd();
	hist -> Draw();
	c1 -> SaveAs("hist2d.jpg");

}
