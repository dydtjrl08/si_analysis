void te(){


	TFile *file = new TFile("RUN511.ch.root","read");
	TTree *tree = (TTree *)file -> Get("channels");
	

		

	for(auto det : {3}){
			
			double x1 = 1450;
			double x2 = 1600;
			if (det ==3 || det == 4){
				x1 = 2800;
				x2 = 3200;
			}
		
			TCanvas *c1 = new TCanvas(Form("Fitting_of_det%d_1", det),Form("det== %d",det),1200,700);	
			c1 -> Divide(4,4);
			
			TCanvas *c2 = new TCanvas(Form("Fitting_of_det%d_2", det),Form("det== %d_2",det),1200,700);	
			c2 -> Divide(4,4);

			for(auto dch = 16; dch <=32; dch++){
				
				
						
				if (det == 3 && (dch == 22|| dch == 23)){
					x1 = 2500;
					x2 = 3500;
				}


				if(dch <=16) c1 -> cd(dch);
				else c2 -> cd(dch-16);
				
				TCut cut_det = Form("det == %d",det);
				TCut cut_dch = Form("dch == %d",dch);	
					
				TCut cut = cut_det && cut_dch;	
				

				tree -> Draw("adc",cut,"");								
				if(tree -> GetEntries(cut) == 0 ) cout << dch << endl;
				TH1D *hist = (TH1D *)gPad -> GetPrimitive("htemp");	
				
				


			}	
	
	}



}
