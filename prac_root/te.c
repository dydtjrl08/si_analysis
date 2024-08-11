typedef ROOT::Math::SMatrix<double,3> SMatrix33;



void te(){


	SMatrix33 m0;
	
	SMatrix33 i = ROOT::Math::SMatrixIdentity();
	double a[9] = {1,2,3,4,5,6,7,8,9};

	SMatrix33 m(a,9);
	
	std::vector<double> v(6);
	v[0] 
}
