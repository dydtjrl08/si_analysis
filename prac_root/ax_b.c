





double Henergy = 5.486; //[MeV]
double Lenergy = 5.443; //[MeV]

void ax_b(){

	
	TFile *file = new TFile("fit_params.root","READ");
	
	fstream write;
	write.open("ax_b.txt",ios::out);
	for(auto det : {2,3,4}){
		
		TCanvas *c1 = new TCanvas(Form("det == %d dch1",det),"c1",1200,700);	
		c1 -> Divide(4,4);
		TCanvas *c2 = new TCanvas(Form("det == %d dch16",det),"c2",1200,700);	
		c2 -> Divide(4,4);


		for(auto dch = 1; dch <=32; dch++){
	
			if(dch <=16) c1 -> cd(dch);	
			else c2 -> cd(dch - 16);
			TF1 *fit1 = (TF1 *)file -> Get(Form("fit_peak1_det == %d dch == %d",det,dch));
			TF1 *fit2 = (TF1 *)file -> Get(Form("fit_peak2_det == %d dch == %d",det,dch));
		
			double mean1 = fit1 -> GetParameter(1);
			double sigma1 = fit1 -> GetParameter(2);
			double mean2 = fit2 -> GetParameter(1);
			double sigma2 = fit2 -> GetParameter(2);
		// y = ax + b
			TMatrixD A(2,2);
			A(0,0) = mean1; A(0,1) = 1;
			A(1,0) = mean2; A(1,1) = 1;
			
			TVectorD b(2);
			b(0) = Henergy; 
			b(1) = Lenergy; 
			
			double detA = A.Determinant();

			if(detA == 0) cout << "It has not the trivial solution" << endl;
			
			TMatrixD A1(A);
			A1(0,0) = b(0);
			A1(1,0) = b(1);
			double detA1 = A1.Determinant();

			TMatrixD A2(A);
			A2(0,1) = b(0);
			A2(1,1) = b(0);
			double detA2 = A2.Determinant();
			// y = ax + b
			double a = detA1 / detA;
			double c = detA1 / detA;
			
			TString namehist = Form("hist_det%dcdch%d",det,dch);
		
			
		//	TH2D *hist = new TH2D(namehist,"2D",100,mean2 - 100,Lenergy,100,mean1 + 100,Henergy);			
			double x[2] = {mean2,mean1};	
			double y[2] = {Lenergy,Henergy};	
			
		//	hist -> Draw();
			TGraph *graph = new TGraph(2,x,y);
			
			graph -> SetLineColor(kRed);
			graph -> SetLineWidth(2);	
			graph -> SetMarkerStyle(21);
			graph -> SetMarkerSize(1.5);
			graph -> SetMarkerColor(kBlue);
			

			graph -> Draw("PL SAME");
			
			write << det <<" " << dch <<" " <<  a <<" " << c << endl;
			

		}
	}

	write.close();
}
