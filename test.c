void test(){

	TCanvas *c1 = new TCanvas();
	

	for(int i = 2; i < 5; i++){
		
		for(int j = 1; j < 33; j++){
			fstream file;
			file.open(Form("det_%d_dch%d.txt",i,j),ios::out);
			TFile *input = new TFile("RUN511.ch.root","read");
			
			TTree *tree = (TTree *)input -> Get("channels");

			TH2F *hist = new TH2F("hist","Histogram",160,-1,1,100,-1,1);
			Short_t adc;
			Short_t det;
			Short_t dch;
			




			tree -> SetBranchAddress("adc",&adc);		
			tree -> SetBranchAddress("det",&det);		
			tree -> SetBranchAddress("dch",&dch);
			
			


			double adc_value;
			double energy;
			while(1){
				file >> adc_value;
			        	

			}



			hist -> Draw();
		}	
	}




}
