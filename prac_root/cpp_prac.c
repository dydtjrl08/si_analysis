


void cpp_prac(){

	TFile *file1 = new TFile("test1.root","RECREATE");
	TFile *file2 = new TFile("test2.root","RECREATE");
	
	file1 -> cd();
	TH1F *h1 = new TH1F("h1","hist1",100,-10,10);
	h1 -> FillRandom("gaus",100);
	
	file1 -> Write();	

	TH1F *h2 = new TH1F("h2","hist2",100,-10,10);

	h2 -> FillRandom("gaus",200);

	file2 -> cd();
	file2 -> Write();
	

}
