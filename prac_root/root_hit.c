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
	
	TH2D *hist = new TH2D("hist","Histogram title;E+dE; dE" ,500,0,10000,800,0,8000);
	hist -> GetXaxis() -> SetRangeUser(0,8000);
	hist -> GetYaxis() -> SetRangeUser(0,7000);
	TCanvas *c1 = new TCanvas("test","2d",1200,800);	
	int entries = tree -> GetEntries();
//adc2 is dE
//adc1 is E
//adc1 + adc2 is total energy 
	for(int i = 1; i <= entries; i++){
		tree -> GetEntry(i);		
		if(det1 == 2 && det2 == 1){
			hist -> Fill(adc1+adc2,adc2);
		}
//		c1 -> SaveAs(Form("det1_2_dch2_%d.jpg",i));
	}
	hist -> Draw("COLZ");
}
