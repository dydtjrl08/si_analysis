




void regression(){
	double derivative_1;
	double derivative_2;
	double constant;


	

	for(int i = 2; i < 5; i++){
		
		


		double x1 = 1450;
		double x2 = 1600;
		if(i == 3 || i ==4){
			x1 = 2800;
			x2 = 3200;
		}
			
		TCanvas *c1 = new TCanvas(Form("alpha_det%d_1",i),"c1",1200,700);
/*		c1 -> Divide(4,4);
		TCanvas *c2 = new TCanvas(Form("alpha_det%d_2",i),"c2",1200,700);
		c1 -> Divide(4,4);
*/
		for(int j = 1; j < 33 ; j++){
			
			if(i ==3 && (j ==22 || j == 23)){
					x1 = 2500;
					x2 = 3500;
			}
			
		/*	TVirtualPad *pad;
			if(j <=16)
				pad = c1 -> cd(j);
			else
				pad = c2 -> cd(j - 16);
			pad -> SetMargin(0.1,0.05,0.1,0.1);
*/
			TString namehist = Form("det_%d_dch%d",i,j);
					
// allocating amp1 m1 s1 amp2 m2 s2 
			
			fstream file;
			file.open(Form("parameter_of_det%d_dch%d.txt",i,j),ios::in);

			double par[6];
			for(int k = 0;  k < 6 ; k++){
				file >> par[k];

			
			}
			
			file.close();
			derivative_1 = 5.486/ par[1];
			derivative_2 =  5.443/ par[4];
			
			
			fstream file_data;	
			
			file_data.open(namehist+TString(".txt"),ios::in);
			TH2D *hist = new TH2D(namehist,namehist,1000,x1,x2,1000,5.0,6.0);	
			
		        cout << derivative_1 << endl;		

			Double_t adc;
			Double_t energy;
			while(1){
				file_data >> adc;
				if(file_data.eof()) break; 	
				if((adc > par[1]-par[2]) && adc < (par[1]+ 3*par[2])){	
					energy = derivative_1 * adc;
					
					hist -> Fill(adc, energy);
				}			
				else if((adc > par[4] - par[5]) && (adc < (par[4]+par[5]))){
					energy = derivative_2 * adc;

					hist -> Fill(adc, energy);
					}
				
			
			}
			hist -> GetXaxis() -> SetTitle("adc");
			hist -> GetYaxis() -> SetTitle("energy [MeV]");
			c1 -> cd();
			hist -> Draw();   // 2d histogram's option is default by the circle shape.
			double low_alpha_x = par[4];		
			double low_alpha_y = 5.443;		
			double high_alpha_x = par[1];		
			double high_alpha_y = 5.486;		
			
			
			TMarker *marker1 = new TMarker(low_alpha_x, low_alpha_y, 2);
			marker1 -> SetMarkerStyle(20);
			marker1 -> SetMarkerSize(2);
			marker1 -> SetMarkerColor(kRed);
			marker1 -> Draw("same");

			
			TMarker *marker2 = new TMarker(high_alpha_x, high_alpha_y, 2);
			marker2 -> SetMarkerStyle(20);
			marker2 -> SetMarkerSize(2);
			marker2 -> SetMarkerColor(kRed);
			marker2 -> Draw("same");

			TLine *line = new TLine(low_alpha_x,low_alpha_y,high_alpha_x,high_alpha_y);
			line -> SetLineColor(kBlack);
			line -> SetLineWidth(5);
			line -> Draw("same");

			c1 -> SaveAs(Form("figures_2D/figure2d_%d_%d.pdf",i,j));
		}

	}




}






