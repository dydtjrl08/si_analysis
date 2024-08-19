void ClickEvent(Int_t event, Int_t x,Int_t y, TObject *selected){
	TCanvas *c = (TCanvas *) gPad;

	double xpixel = x;
	double ypixel = y;

	double xcoord = c -> AbsPixeltoX(xpixel);
	double ycoord = c -> AbsPixeltoY(ypixel);
	cout << "Clicked at (pixel): (" << xpixel << ", " << ypixel << ")" << endl;
    cout << "Clicked at (graph coordinates): (" << xcoord << ", " << ycoord << ")" << endl;
}

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
	
	TH2D *hist = new TH2D("hist","Histogram ;E+dE; dE" ,500,0,10000,800,0,8000);
	hist -> GetXaxis() -> SetRangeUser(0,8000);
	hist -> GetYaxis() -> SetRangeUser(0,7000);
	TCanvas *c1 = new TCanvas("pid","Energy",1200,800);	
	int entries = tree -> GetEntries();
	TCut cut = "det1 == 2 && det2 == 1";
	tree -> Draw("adc2:adc1+adc2 >> hist",cut,"COLZ");
//adc2 is dE
//adc1 is E
//adc1 + adc2 is total energy 
/*	for(int i = 1; i <= entries; i++){
		tree -> GetEntry(i);		
		if(det1 == 2 && det2 == 1){
			hist -> Fill(adc1+adc2,adc2);
		}
	}*/
//	hist -> Draw("COLZ");
	c1 -> Connect("ProcessedEvent(Int_t, Int_t, Int_t TObject*)",0,0,"ClickEvent(Int_t, Int_t, Int_t, TObject*)");
	
	c1 -> Update();
//	c1 -> SaveAs("det1_2_dch2_1.jpg");
//	TCutG *cutg = NEW TCutG("cutg",5);
//	cutg -> SetPoint(0,

}
