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
	TFile *calibration_file = new TFile("constants_all.root","READ");	
	
	TTree *cal = (TTree *) calibration_file -> Get("t1");

	Double_t a; // is calibration factors
	Short_t det;	
	Short_t dch;	
	cal -> SetBranchAddress("dch",&dch);
	cal -> SetBranchAddress("a",&a);
	cal -> SetBranchAddress("det",&det);



	Short_t det1;
	Short_t dch1;
	Short_t adc1;
	Short_t det2;
	Short_t dch2;
	Short_t adc2;
	
	TCanvas *c1 = new TCanvas("cvs1","dE : E+dE",1200,800);
//	cvs1 -> Divide(4,4);
//	TCanvas *cvs2 = new TCanvas("cvs2","dE : E+dE",1200,800);
//	cvs2 -> Divide(4,4);
	tree -> SetBranchAddress("det1",&det1);// E det1 == 2
	tree -> SetBranchAddress("det2",&det2);// dE det2 == 1
	tree -> SetBranchAddress("dch1",&dch1);
	tree -> SetBranchAddress("dch2",&dch2);
	tree -> SetBranchAddress("adc1",&adc1);
	tree -> SetBranchAddress("adc2",&adc2);
	
	double number = cal -> GetEntries();
	double a_arr[4][32];
	for(int i = 0; i < number; i++){
		cal -> GetEntry(i);
		
		a_arr[det-1][dch-1] = a;	
		

	}
	
	Double_t energy;
	Double_t d_energy;
	
	
	TH2D *hist = new TH2D("hist","Histogram ;E+dE; dE" ,500,0,25,800,0,100);

	double nentries = tree -> GetEntries();
	for(int i = 1 ; i <= nentries; i++){
		tree -> GetEntry(i);
	
	
		if(det1 == 1){
			energy = adc1*a_arr[det1+1][dch1-1];
			d_energy = adc2*a_arr[det2-1][dch2-1];
		}
		hist -> Fill(d_energy+energy,d_energy);	
	}	
	hist -> Draw("COLZ");
		
	c1 -> SaveAs("hist_cal.jpg");	
//	tree -> Draw("adc2:adc1+adc2 >> hist",cut,"COLZ");


//adc2 is dE
//adc1 is E
//adc1 + adc2 is total energy 
//	c1 -> Connect("ProcessedEvent(Int_t, Int_t, Int_t TObject*)",0,0,"ClickEvent(Int_t, Int_t, Int_t, TObject*)");
	
//	c1 -> Update();
//	c1 -> SaveAs("det1_2_dch2_1.jpg");
//	TCutG *cutg = NEW TCutG("cutg",5);
//	cutg -> SetPoint(0,

}
