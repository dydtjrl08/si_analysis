#include <TCanvas.h>
#include <TH2F.h>
#include <TFile.h>
#include <TTree.h>
#include <iostream>

// 클릭 이벤트 핸들러 함수
void ClickEvent(Int_t event, Int_t x, Int_t y, TObject* selected)
{   
    //마우스 왼쪽 버튼 클릭 이벤트일 때만 처리
    if (event != kButton1Down) return;
    // 전역적으로 현재 활성화된 캔버스를 얻음
    TCanvas *c = (TCanvas*)gPad;
    
    // 클릭한 좌표 (픽셀 좌표계)
    double xpixel = x;
    double ypixel = y;

    // 픽셀 좌표를 실제 그래프 좌표로 변환
    double xcoord = c->AbsPixeltoX(xpixel);
    double ycoord = c->AbsPixeltoY(ypixel);

   std::cout << "Clicked at (graph coordinates): (" << xcoord << ", " << ycoord << ")" << std::endl;

}

void event_test()
{
    // ROOT 파일 및 트리 열기
    TFile *file = TFile::Open("RUN528.hit.root");
    TTree *tree = (TTree*)file->Get("hit");
	
    TCut cut1= "det1 == 2 && det2 == 1";
    TCut cut2= "det1 == 1 && det2 == 2";
	    
    TCanvas *c1 = new TCanvas("c1", "2D Histogram with Click Event", 800, 600);
    // 2D 히스토그램 생성 및 데이터 채우기
    TH2F *h2 = new TH2F("h2", "2D Histogram;X axis;Y axis", 800, 0,8000, 1000, 0, 8000);
    TH2F *h3 = new TH2F("h3", "2D Histogram;X axis;Y axis", 800, 0,8000, 1000, 0, 8000);
    tree->Draw("adc2:adc1+adc2 >> h2",cut1, "COLZ");
    c1 -> SaveAs("det1_2.jpg");	
    tree->Draw("adc2:adc1+adc2 >> h3",cut2, "COLZ");
    c1 -> SaveAs("det1_1.jpg");	
/*  // 캔버스 생성
    h2->Draw("COLZ");

    // 이벤트 핸들러 설정
    c1->Connect("ProcessedEvent(Int_t, Int_t, Int_t, TObject*)", 0, 0, "ClickEvent(Int_t, Int_t, Int_t, TObject*)");

    // 이벤트 루프 실행
    c1->Update();
    
    // TCutG 생성 (이름, 점의 개수)
    TCutG *cutg = new TCutG("cutg", 5);

    // 다각형의 각 점의 좌표 설정 (여기서는 임의의 좌표 사용)
    cutg->SetPoint(0, -5, -5);
    cutg->SetPoint(1,  5, -5);
    cutg->SetPoint(2,  5,  5);
    cutg->SetPoint(3, -5,  5);
    cutg->SetPoint(4, -5, -5);  // 처음 점으로 돌아옴

    // 다각형 영역을 히스토그램에 오버레이
    cutg->SetLineColor(kRed);
    cutg->SetLineWidth(2);
    cutg->Draw("L");*/
}
