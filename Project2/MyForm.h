#pragma once
#include <opencv2/opencv.hpp>
#include "iostream"
#include "math.h"
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>


namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace cv;

	// src img
	std::string x;
	//Mat src = imread("1.JPG", 0);
	Mat src;
	//Mat src = imread("pictureBox1->Image",0);
		//= Image::FromFile(ofd->FileName);
	/*array<string^>^ files;
	string^ path;
	int currentInd;*/
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void getContours(Mat imgDil, Mat src) {

			vector<vector<cv::Point>> contours;
			vector<Vec4i> hierarchy;

			findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
			//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

			vector<vector<cv::Point>> conPoly(contours.size());
			vector<Rect> boundRect(contours.size());

			for (int i = 0; i < contours.size(); i++)
			{
				int area = contourArea(contours[i]);
				cout << area << endl;
				string objectType;

				if (area > 1000)
				{
					float peri = arcLength(contours[i], true);
					approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
					cout << conPoly[i].size() << endl;
					boundRect[i] = boundingRect(conPoly[i]);

					int objCor = (int)conPoly[i].size();

					if (objCor == 3) { objectType = "Tri"; }
					else if (objCor == 4)
					{
						float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
						cout << aspRatio << endl;
						if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
						else { objectType = "Rect"; }
					}
					else if (objCor > 4) { objectType = "Circle"; }

					drawContours(src, conPoly, i, Scalar(255, 0, 255), 2);
					rectangle(src, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
					putText(src, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
				}
			}
		}
	void MarshalString(System::String^ s, std::string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}





	private: System::Windows::Forms::Button^ translation;
	private: System::Windows::Forms::Button^ rotation;
	private: System::Windows::Forms::Button^ DeskewingF;

	private: System::Windows::Forms::Button^ image_zoom;
	private: System::Windows::Forms::Button^ VerticalFlip;

	private: System::Windows::Forms::Button^ equali;

	private: System::Windows::Forms::Button^ negative_im;
	private: System::Windows::Forms::Button^ LogTransformF;
	private: System::Windows::Forms::Button^ BitPlane;







	private: System::Windows::Forms::Button^ Graysclicing;
	private: System::Windows::Forms::Button^ powertrans;


	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::TextBox^ YValue;

	private: System::Windows::Forms::TextBox^ XValue;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ Deg;
	private: System::Windows::Forms::TextBox^ scal;

	private: System::Windows::Forms::Label^ degree;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ TradFill;
	private: System::Windows::Forms::Button^ pyramFil;
	private: System::Windows::Forms::Button^ cilFil;
	private: System::Windows::Forms::Button^ ConFil;
	private: System::Windows::Forms::Button^ ThresholdSeg;

	private: System::Windows::Forms::Button^ gauss;
	private: System::Windows::Forms::Button^ laplacSeg;
	private: System::Windows::Forms::Button^ SobelFil;
	private: System::Windows::Forms::Button^ HorizontalFlip;
	private: System::Windows::Forms::Button^ AllFlip;




	private: System::Windows::Forms::Button^ RLSkew;
	private: System::Windows::Forms::TextBox^ skewValue;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ UploadImg;
	private: System::Windows::Forms::OpenFileDialog^ ofd;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ buttonTrans1;

	private: System::Windows::Forms::Button^ buttonTransE;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Timer^ timer3;
	private: System::Windows::Forms::Timer^ timer4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::ComponentModel::IContainer^ components;
private: System::Windows::Forms::Button^ GrayImg;
private: System::Windows::Forms::GroupBox^ groupBox3;
private: System::Windows::Forms::GroupBox^ groupBox4;
private: System::Windows::Forms::Panel^ topbar;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::Button^ medianFil;
private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Button^ button3;

private: System::Windows::Forms::Button^ button4;
private: System::Windows::Forms::TrackBar^ gammavalue;
private: System::Windows::Forms::TrackBar^ LogValue;
private: System::Windows::Forms::Button^ Blinding;
private: System::Windows::Forms::TrackBar^ comvalue;
private: System::Windows::Forms::GroupBox^ groupBox5;
private: System::Windows::Forms::GroupBox^ groupBox6;
private: System::Windows::Forms::TrackBar^ thresholding;













	public: System::String^ path;





	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->translation = (gcnew System::Windows::Forms::Button());
			this->rotation = (gcnew System::Windows::Forms::Button());
			this->DeskewingF = (gcnew System::Windows::Forms::Button());
			this->image_zoom = (gcnew System::Windows::Forms::Button());
			this->VerticalFlip = (gcnew System::Windows::Forms::Button());
			this->equali = (gcnew System::Windows::Forms::Button());
			this->negative_im = (gcnew System::Windows::Forms::Button());
			this->LogTransformF = (gcnew System::Windows::Forms::Button());
			this->BitPlane = (gcnew System::Windows::Forms::Button());
			this->Graysclicing = (gcnew System::Windows::Forms::Button());
			this->powertrans = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->YValue = (gcnew System::Windows::Forms::TextBox());
			this->XValue = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Deg = (gcnew System::Windows::Forms::TextBox());
			this->scal = (gcnew System::Windows::Forms::TextBox());
			this->degree = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->TradFill = (gcnew System::Windows::Forms::Button());
			this->pyramFil = (gcnew System::Windows::Forms::Button());
			this->cilFil = (gcnew System::Windows::Forms::Button());
			this->ConFil = (gcnew System::Windows::Forms::Button());
			this->ThresholdSeg = (gcnew System::Windows::Forms::Button());
			this->gauss = (gcnew System::Windows::Forms::Button());
			this->laplacSeg = (gcnew System::Windows::Forms::Button());
			this->SobelFil = (gcnew System::Windows::Forms::Button());
			this->HorizontalFlip = (gcnew System::Windows::Forms::Button());
			this->AllFlip = (gcnew System::Windows::Forms::Button());
			this->RLSkew = (gcnew System::Windows::Forms::Button());
			this->skewValue = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->UploadImg = (gcnew System::Windows::Forms::Button());
			this->ofd = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonTrans1 = (gcnew System::Windows::Forms::Button());
			this->buttonTransE = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->GrayImg = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->topbar = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->medianFil = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->gammavalue = (gcnew System::Windows::Forms::TrackBar());
			this->LogValue = (gcnew System::Windows::Forms::TrackBar());
			this->Blinding = (gcnew System::Windows::Forms::Button());
			this->comvalue = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->thresholding = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->topbar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gammavalue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogValue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->comvalue))->BeginInit();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->thresholding))->BeginInit();
			this->SuspendLayout();
			// 
			// translation
			// 
			this->translation->BackColor = System::Drawing::SystemColors::HighlightText;
			this->translation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->translation->ForeColor = System::Drawing::Color::Black;
			this->translation->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"translation.Image")));
			this->translation->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->translation->Location = System::Drawing::Point(7, 16);
			this->translation->Margin = System::Windows::Forms::Padding(4);
			this->translation->Name = L"translation";
			this->translation->Size = System::Drawing::Size(151, 53);
			this->translation->TabIndex = 3;
			this->translation->Text = L"Move";
			this->translation->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->translation->UseVisualStyleBackColor = false;
			this->translation->Click += gcnew System::EventHandler(this, &MyForm::translation_Click);
			// 
			// rotation
			// 
			this->rotation->BackColor = System::Drawing::SystemColors::HighlightText;
			this->rotation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rotation->ForeColor = System::Drawing::Color::Black;
			this->rotation->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"rotation.Image")));
			this->rotation->Location = System::Drawing::Point(5, 22);
			this->rotation->Margin = System::Windows::Forms::Padding(4);
			this->rotation->Name = L"rotation";
			this->rotation->Size = System::Drawing::Size(159, 55);
			this->rotation->TabIndex = 4;
			this->rotation->Text = L"Rotation";
			this->rotation->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->rotation->UseVisualStyleBackColor = false;
			this->rotation->Click += gcnew System::EventHandler(this, &MyForm::rotation_Click);
			// 
			// DeskewingF
			// 
			this->DeskewingF->BackColor = System::Drawing::SystemColors::HighlightText;
			this->DeskewingF->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DeskewingF->ForeColor = System::Drawing::Color::Black;
			this->DeskewingF->Location = System::Drawing::Point(7, 33);
			this->DeskewingF->Margin = System::Windows::Forms::Padding(4);
			this->DeskewingF->Name = L"DeskewingF";
			this->DeskewingF->Size = System::Drawing::Size(146, 36);
			this->DeskewingF->TabIndex = 5;
			this->DeskewingF->Text = L"Left to Right";
			this->DeskewingF->UseVisualStyleBackColor = false;
			this->DeskewingF->Click += gcnew System::EventHandler(this, &MyForm::DeskewingF_Click);
			// 
			// image_zoom
			// 
			this->image_zoom->BackColor = System::Drawing::SystemColors::HighlightText;
			this->image_zoom->ForeColor = System::Drawing::Color::Black;
			this->image_zoom->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"image_zoom.Image")));
			this->image_zoom->Location = System::Drawing::Point(1055, 256);
			this->image_zoom->Margin = System::Windows::Forms::Padding(4);
			this->image_zoom->Name = L"image_zoom";
			this->image_zoom->Size = System::Drawing::Size(76, 144);
			this->image_zoom->TabIndex = 7;
			this->image_zoom->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->image_zoom->UseVisualStyleBackColor = false;
			this->image_zoom->Click += gcnew System::EventHandler(this, &MyForm::image_zoom_Click);
			// 
			// VerticalFlip
			// 
			this->VerticalFlip->BackColor = System::Drawing::SystemColors::HighlightText;
			this->VerticalFlip->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VerticalFlip->ForeColor = System::Drawing::Color::Black;
			this->VerticalFlip->Location = System::Drawing::Point(11, 38);
			this->VerticalFlip->Margin = System::Windows::Forms::Padding(4);
			this->VerticalFlip->Name = L"VerticalFlip";
			this->VerticalFlip->Size = System::Drawing::Size(153, 36);
			this->VerticalFlip->TabIndex = 8;
			this->VerticalFlip->Text = L"Vertical";
			this->VerticalFlip->UseVisualStyleBackColor = false;
			this->VerticalFlip->Click += gcnew System::EventHandler(this, &MyForm::reflection_Click);
			// 
			// equali
			// 
			this->equali->ForeColor = System::Drawing::Color::Black;
			this->equali->Location = System::Drawing::Point(212, 551);
			this->equali->Margin = System::Windows::Forms::Padding(4);
			this->equali->Name = L"equali";
			this->equali->Size = System::Drawing::Size(148, 38);
			this->equali->TabIndex = 9;
			this->equali->Text = L"Contrast";
			this->equali->UseVisualStyleBackColor = true;
			this->equali->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// negative_im
			// 
			this->negative_im->ForeColor = System::Drawing::Color::Black;
			this->negative_im->Location = System::Drawing::Point(212, 656);
			this->negative_im->Margin = System::Windows::Forms::Padding(4);
			this->negative_im->Name = L"negative_im";
			this->negative_im->Size = System::Drawing::Size(148, 36);
			this->negative_im->TabIndex = 11;
			this->negative_im->Text = L"Invert";
			this->negative_im->UseVisualStyleBackColor = true;
			this->negative_im->Click += gcnew System::EventHandler(this, &MyForm::negative_im_Click);
			// 
			// LogTransformF
			// 
			this->LogTransformF->ForeColor = System::Drawing::Color::Black;
			this->LogTransformF->Location = System::Drawing::Point(28, 646);
			this->LogTransformF->Margin = System::Windows::Forms::Padding(4);
			this->LogTransformF->Name = L"LogTransformF";
			this->LogTransformF->Size = System::Drawing::Size(148, 36);
			this->LogTransformF->TabIndex = 12;
			this->LogTransformF->Text = L"Brightness";
			this->LogTransformF->UseVisualStyleBackColor = true;
			this->LogTransformF->Click += gcnew System::EventHandler(this, &MyForm::LogTransformF_Click);
			// 
			// BitPlane
			// 
			this->BitPlane->ForeColor = System::Drawing::Color::Black;
			this->BitPlane->Location = System::Drawing::Point(212, 796);
			this->BitPlane->Margin = System::Windows::Forms::Padding(4);
			this->BitPlane->Name = L"BitPlane";
			this->BitPlane->Size = System::Drawing::Size(148, 36);
			this->BitPlane->TabIndex = 13;
			this->BitPlane->Text = L"Compression";
			this->BitPlane->UseVisualStyleBackColor = true;
			this->BitPlane->Click += gcnew System::EventHandler(this, &MyForm::BitPlane_Click);
			// 
			// Graysclicing
			// 
			this->Graysclicing->ForeColor = System::Drawing::Color::Black;
			this->Graysclicing->Location = System::Drawing::Point(212, 596);
			this->Graysclicing->Margin = System::Windows::Forms::Padding(4);
			this->Graysclicing->Name = L"Graysclicing";
			this->Graysclicing->Size = System::Drawing::Size(148, 36);
			this->Graysclicing->TabIndex = 15;
			this->Graysclicing->Text = L"Highlights";
			this->Graysclicing->UseVisualStyleBackColor = true;
			this->Graysclicing->Click += gcnew System::EventHandler(this, &MyForm::Graysclicing_Click);
			// 
			// powertrans
			// 
			this->powertrans->ForeColor = System::Drawing::Color::Black;
			this->powertrans->Location = System::Drawing::Point(28, 551);
			this->powertrans->Margin = System::Windows::Forms::Padding(4);
			this->powertrans->Name = L"powertrans";
			this->powertrans->Size = System::Drawing::Size(148, 36);
			this->powertrans->TabIndex = 16;
			this->powertrans->Text = L"Darken";
			this->powertrans->UseVisualStyleBackColor = true;
			this->powertrans->Click += gcnew System::EventHandler(this, &MyForm::powertrans_Click);
			// 
			// button9
			// 
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::White;
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.Image")));
			this->button9->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button9->Location = System::Drawing::Point(537, 388);
			this->button9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(161, 49);
			this->button9->TabIndex = 17;
			this->button9->Text = L" Reset";
			this->button9->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// YValue
			// 
			this->YValue->Location = System::Drawing::Point(232, 45);
			this->YValue->Margin = System::Windows::Forms::Padding(4);
			this->YValue->Name = L"YValue";
			this->YValue->Size = System::Drawing::Size(65, 22);
			this->YValue->TabIndex = 18;
			// 
			// XValue
			// 
			this->XValue->Location = System::Drawing::Point(232, 16);
			this->XValue->Margin = System::Windows::Forms::Padding(4);
			this->XValue->Name = L"XValue";
			this->XValue->Size = System::Drawing::Size(65, 22);
			this->XValue->TabIndex = 19;
			this->XValue->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(166, 48);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 17);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Y-Value";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(166, 20);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 17);
			this->label3->TabIndex = 22;
			this->label3->Text = L"X-Value";
			// 
			// Deg
			// 
			this->Deg->Location = System::Drawing::Point(230, 22);
			this->Deg->Name = L"Deg";
			this->Deg->Size = System::Drawing::Size(65, 22);
			this->Deg->TabIndex = 23;
			// 
			// scal
			// 
			this->scal->Location = System::Drawing::Point(230, 55);
			this->scal->Name = L"scal";
			this->scal->Size = System::Drawing::Size(65, 22);
			this->scal->TabIndex = 24;
			// 
			// degree
			// 
			this->degree->AutoSize = true;
			this->degree->Location = System::Drawing::Point(179, 25);
			this->degree->Name = L"degree";
			this->degree->Size = System::Drawing::Size(53, 17);
			this->degree->TabIndex = 25;
			this->degree->Text = L"degree";
			this->degree->Click += gcnew System::EventHandler(this, &MyForm::degree_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(183, 58);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 17);
			this->label4->TabIndex = 26;
			this->label4->Text = L"scale";
			// 
			// TradFill
			// 
			this->TradFill->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TradFill->ForeColor = System::Drawing::Color::Black;
			this->TradFill->Location = System::Drawing::Point(19, 164);
			this->TradFill->Name = L"TradFill";
			this->TradFill->Size = System::Drawing::Size(157, 34);
			this->TradFill->TabIndex = 27;
			this->TradFill->Text = L"traditional ";
			this->TradFill->UseVisualStyleBackColor = true;
			this->TradFill->Click += gcnew System::EventHandler(this, &MyForm::TradFill_Click);
			// 
			// pyramFil
			// 
			this->pyramFil->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pyramFil->ForeColor = System::Drawing::Color::Black;
			this->pyramFil->Location = System::Drawing::Point(19, 41);
			this->pyramFil->Name = L"pyramFil";
			this->pyramFil->Size = System::Drawing::Size(157, 34);
			this->pyramFil->TabIndex = 28;
			this->pyramFil->Text = L"pyramidal";
			this->pyramFil->UseVisualStyleBackColor = true;
			this->pyramFil->Click += gcnew System::EventHandler(this, &MyForm::pyramFil_Click);
			// 
			// cilFil
			// 
			this->cilFil->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cilFil->ForeColor = System::Drawing::Color::Black;
			this->cilFil->Location = System::Drawing::Point(19, 81);
			this->cilFil->Name = L"cilFil";
			this->cilFil->Size = System::Drawing::Size(157, 34);
			this->cilFil->TabIndex = 29;
			this->cilFil->Text = L"cirular";
			this->cilFil->UseVisualStyleBackColor = true;
			this->cilFil->Click += gcnew System::EventHandler(this, &MyForm::cilFil_Click);
			// 
			// ConFil
			// 
			this->ConFil->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ConFil->ForeColor = System::Drawing::Color::Black;
			this->ConFil->Location = System::Drawing::Point(19, 121);
			this->ConFil->Name = L"ConFil";
			this->ConFil->Size = System::Drawing::Size(157, 34);
			this->ConFil->TabIndex = 30;
			this->ConFil->Text = L"Cone";
			this->ConFil->UseVisualStyleBackColor = true;
			this->ConFil->Click += gcnew System::EventHandler(this, &MyForm::ConFil_Click);
			// 
			// ThresholdSeg
			// 
			this->ThresholdSeg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ThresholdSeg->ForeColor = System::Drawing::Color::Black;
			this->ThresholdSeg->Location = System::Drawing::Point(16, 76);
			this->ThresholdSeg->Name = L"ThresholdSeg";
			this->ThresholdSeg->Size = System::Drawing::Size(148, 36);
			this->ThresholdSeg->TabIndex = 31;
			this->ThresholdSeg->Text = L"Thresholding";
			this->ThresholdSeg->UseVisualStyleBackColor = true;
			this->ThresholdSeg->Click += gcnew System::EventHandler(this, &MyForm::ThresholdSeg_Click);
			// 
			// gauss
			// 
			this->gauss->ForeColor = System::Drawing::Color::Black;
			this->gauss->Location = System::Drawing::Point(613, 796);
			this->gauss->Name = L"gauss";
			this->gauss->Size = System::Drawing::Size(157, 36);
			this->gauss->TabIndex = 33;
			this->gauss->Text = L"Blur";
			this->gauss->UseVisualStyleBackColor = true;
			this->gauss->Click += gcnew System::EventHandler(this, &MyForm::gauss_Click);
			// 
			// laplacSeg
			// 
			this->laplacSeg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->laplacSeg->ForeColor = System::Drawing::Color::Black;
			this->laplacSeg->Location = System::Drawing::Point(16, 33);
			this->laplacSeg->Name = L"laplacSeg";
			this->laplacSeg->Size = System::Drawing::Size(148, 35);
			this->laplacSeg->TabIndex = 34;
			this->laplacSeg->Text = L"Laplacain ";
			this->laplacSeg->UseVisualStyleBackColor = true;
			this->laplacSeg->Click += gcnew System::EventHandler(this, &MyForm::laplacSeg_Click);
			// 
			// SobelFil
			// 
			this->SobelFil->ForeColor = System::Drawing::Color::Black;
			this->SobelFil->Location = System::Drawing::Point(398, 796);
			this->SobelFil->Name = L"SobelFil";
			this->SobelFil->Size = System::Drawing::Size(148, 35);
			this->SobelFil->TabIndex = 35;
			this->SobelFil->Text = L"Sharping";
			this->SobelFil->UseVisualStyleBackColor = true;
			this->SobelFil->Click += gcnew System::EventHandler(this, &MyForm::SobelFil_Click);
			// 
			// HorizontalFlip
			// 
			this->HorizontalFlip->BackColor = System::Drawing::SystemColors::HighlightText;
			this->HorizontalFlip->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HorizontalFlip->ForeColor = System::Drawing::Color::Black;
			this->HorizontalFlip->Location = System::Drawing::Point(11, 82);
			this->HorizontalFlip->Margin = System::Windows::Forms::Padding(4);
			this->HorizontalFlip->Name = L"HorizontalFlip";
			this->HorizontalFlip->Size = System::Drawing::Size(153, 36);
			this->HorizontalFlip->TabIndex = 36;
			this->HorizontalFlip->Text = L"Horizontal";
			this->HorizontalFlip->UseVisualStyleBackColor = false;
			this->HorizontalFlip->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// AllFlip
			// 
			this->AllFlip->BackColor = System::Drawing::SystemColors::HighlightText;
			this->AllFlip->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AllFlip->ForeColor = System::Drawing::Color::Black;
			this->AllFlip->Location = System::Drawing::Point(11, 126);
			this->AllFlip->Margin = System::Windows::Forms::Padding(4);
			this->AllFlip->Name = L"AllFlip";
			this->AllFlip->Size = System::Drawing::Size(153, 36);
			this->AllFlip->TabIndex = 37;
			this->AllFlip->Text = L"Horizontal + Vertical";
			this->AllFlip->UseVisualStyleBackColor = false;
			this->AllFlip->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// RLSkew
			// 
			this->RLSkew->BackColor = System::Drawing::SystemColors::HighlightText;
			this->RLSkew->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RLSkew->ForeColor = System::Drawing::Color::Black;
			this->RLSkew->Location = System::Drawing::Point(7, 77);
			this->RLSkew->Margin = System::Windows::Forms::Padding(4);
			this->RLSkew->Name = L"RLSkew";
			this->RLSkew->Size = System::Drawing::Size(146, 36);
			this->RLSkew->TabIndex = 40;
			this->RLSkew->Text = L"Right To Left";
			this->RLSkew->UseVisualStyleBackColor = false;
			this->RLSkew->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_2);
			// 
			// skewValue
			// 
			this->skewValue->Location = System::Drawing::Point(225, 52);
			this->skewValue->Name = L"skewValue";
			this->skewValue->Size = System::Drawing::Size(65, 38);
			this->skewValue->TabIndex = 41;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(179, 21);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(121, 17);
			this->label7->TabIndex = 43;
			this->label7->Text = L"De-skewing Value";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// UploadImg
			// 
			this->UploadImg->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->UploadImg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UploadImg->ForeColor = System::Drawing::Color::White;
			this->UploadImg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UploadImg.Image")));
			this->UploadImg->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->UploadImg->Location = System::Drawing::Point(12, 388);
			this->UploadImg->Name = L"UploadImg";
			this->UploadImg->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->UploadImg->Size = System::Drawing::Size(153, 49);
			this->UploadImg->TabIndex = 44;
			this->UploadImg->Text = L"Upload";
			this->UploadImg->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->UploadImg->UseVisualStyleBackColor = true;
			this->UploadImg->Click += gcnew System::EventHandler(this, &MyForm::UploadImg_Click);
			// 
			// ofd
			// 
			this->ofd->Filter = L"\"JPEG|*.jpg|All Files|*.*\"";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 56);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(686, 322);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// buttonTrans1
			// 
			this->buttonTrans1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonTrans1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->buttonTrans1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonTrans1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonTrans1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonTrans1->ForeColor = System::Drawing::Color::White;
			this->buttonTrans1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonTrans1.Image")));
			this->buttonTrans1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonTrans1->Location = System::Drawing::Point(704, 56);
			this->buttonTrans1->Name = L"buttonTrans1";
			this->buttonTrans1->Size = System::Drawing::Size(115, 61);
			this->buttonTrans1->TabIndex = 46;
			this->buttonTrans1->Text = L"Edit";
			this->buttonTrans1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buttonTrans1->UseVisualStyleBackColor = true;
			this->buttonTrans1->Click += gcnew System::EventHandler(this, &MyForm::buttonTrans1_Click);
			// 
			// buttonTransE
			// 
			this->buttonTransE->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonTransE->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->buttonTransE->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonTransE->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonTransE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonTransE->ForeColor = System::Drawing::Color::White;
			this->buttonTransE->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonTransE.Image")));
			this->buttonTransE->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonTransE->Location = System::Drawing::Point(6, 478);
			this->buttonTransE->Name = L"buttonTransE";
			this->buttonTransE->Size = System::Drawing::Size(254, 48);
			this->buttonTransE->TabIndex = 48;
			this->buttonTransE->Text = L"Enhancement";
			this->buttonTransE->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buttonTransE->UseVisualStyleBackColor = true;
			this->buttonTransE->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_3);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 1;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Interval = 1;
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// timer4
			// 
			this->timer4->Interval = 1;
			this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->translation);
			this->groupBox1->Controls->Add(this->YValue);
			this->groupBox1->Controls->Add(this->XValue);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Location = System::Drawing::Point(825, 56);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(306, 81);
			this->groupBox1->TabIndex = 49;
			this->groupBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->VerticalFlip);
			this->groupBox2->Controls->Add(this->HorizontalFlip);
			this->groupBox2->Controls->Add(this->AllFlip);
			this->groupBox2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->ForeColor = System::Drawing::Color::White;
			this->groupBox2->Location = System::Drawing::Point(825, 239);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(172, 168);
			this->groupBox2->TabIndex = 50;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Flip";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &MyForm::groupBox2_Enter);
			// 
			// GrayImg
			// 
			this->GrayImg->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GrayImg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GrayImg->ForeColor = System::Drawing::Color::White;
			this->GrayImg->Location = System::Drawing::Point(171, 388);
			this->GrayImg->Name = L"GrayImg";
			this->GrayImg->Size = System::Drawing::Size(172, 49);
			this->GrayImg->TabIndex = 51;
			this->GrayImg->Text = L"Black|White";
			this->GrayImg->UseVisualStyleBackColor = true;
			this->GrayImg->Click += gcnew System::EventHandler(this, &MyForm::GrayImg_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->DeskewingF);
			this->groupBox3->Controls->Add(this->RLSkew);
			this->groupBox3->Controls->Add(this->skewValue);
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->groupBox3->Location = System::Drawing::Point(825, 413);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(306, 128);
			this->groupBox3->TabIndex = 52;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Skewing";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->rotation);
			this->groupBox4->Controls->Add(this->Deg);
			this->groupBox4->Controls->Add(this->scal);
			this->groupBox4->Controls->Add(this->degree);
			this->groupBox4->Controls->Add(this->label4);
			this->groupBox4->Location = System::Drawing::Point(825, 143);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(306, 87);
			this->groupBox4->TabIndex = 53;
			this->groupBox4->TabStop = false;
			// 
			// topbar
			// 
			this->topbar->BackColor = System::Drawing::Color::WhiteSmoke;
			this->topbar->Controls->Add(this->button1);
			this->topbar->Location = System::Drawing::Point(1, 0);
			this->topbar->Name = L"topbar";
			this->topbar->Size = System::Drawing::Size(1177, 37);
			this->topbar->TabIndex = 54;
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(753, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(44, 37);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// medianFil
			// 
			this->medianFil->ForeColor = System::Drawing::Color::Black;
			this->medianFil->Location = System::Drawing::Point(212, 699);
			this->medianFil->Name = L"medianFil";
			this->medianFil->Size = System::Drawing::Size(148, 36);
			this->medianFil->TabIndex = 55;
			this->medianFil->Text = L"Noise Reduction";
			this->medianFil->UseVisualStyleBackColor = true;
			this->medianFil->Click += gcnew System::EventHandler(this, &MyForm::medianFil_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"\"JPEG|*.jpg|All Files|*.*\"";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(15, 164);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(148, 36);
			this->button2->TabIndex = 56;
			this->button2->Text = L"IDFT";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_4);
			// 
			// button3
			// 
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(28, 751);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(157, 36);
			this->button3->TabIndex = 57;
			this->button3->Text = L"Reduce quality";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
			// 
			// button4
			// 
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(349, 388);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(182, 49);
			this->button4->TabIndex = 59;
			this->button4->Text = L"shape detection";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
			// 
			// gammavalue
			// 
			this->gammavalue->Location = System::Drawing::Point(28, 583);
			this->gammavalue->Minimum = 1;
			this->gammavalue->Name = L"gammavalue";
			this->gammavalue->Size = System::Drawing::Size(148, 56);
			this->gammavalue->TabIndex = 60;
			this->gammavalue->Value = 1;
			this->gammavalue->Scroll += gcnew System::EventHandler(this, &MyForm::gammavalue_Scroll);
			// 
			// LogValue
			// 
			this->LogValue->Location = System::Drawing::Point(28, 689);
			this->LogValue->Name = L"LogValue";
			this->LogValue->Size = System::Drawing::Size(148, 56);
			this->LogValue->TabIndex = 61;
			// 
			// Blinding
			// 
			this->Blinding->ForeColor = System::Drawing::Color::Black;
			this->Blinding->Location = System::Drawing::Point(212, 750);
			this->Blinding->Margin = System::Windows::Forms::Padding(4);
			this->Blinding->Name = L"Blinding";
			this->Blinding->Size = System::Drawing::Size(148, 38);
			this->Blinding->TabIndex = 10;
			this->Blinding->Text = L"Blind";
			this->Blinding->UseVisualStyleBackColor = true;
			this->Blinding->Click += gcnew System::EventHandler(this, &MyForm::Blinding_Click);
			// 
			// comvalue
			// 
			this->comvalue->Location = System::Drawing::Point(28, 793);
			this->comvalue->Maximum = 100;
			this->comvalue->Minimum = 1;
			this->comvalue->Name = L"comvalue";
			this->comvalue->Size = System::Drawing::Size(148, 56);
			this->comvalue->TabIndex = 62;
			this->comvalue->Value = 1;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->pyramFil);
			this->groupBox5->Controls->Add(this->TradFill);
			this->groupBox5->Controls->Add(this->cilFil);
			this->groupBox5->Controls->Add(this->ConFil);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox5->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->groupBox5->Location = System::Drawing::Point(594, 551);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(200, 211);
			this->groupBox5->TabIndex = 63;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Smoothing";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->button2);
			this->groupBox6->Controls->Add(this->laplacSeg);
			this->groupBox6->Controls->Add(this->ThresholdSeg);
			this->groupBox6->Controls->Add(this->thresholding);
			this->groupBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox6->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->groupBox6->Location = System::Drawing::Point(383, 551);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(189, 220);
			this->groupBox6->TabIndex = 64;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Segmentation";
			// 
			// thresholding
			// 
			this->thresholding->Location = System::Drawing::Point(16, 118);
			this->thresholding->Maximum = 200;
			this->thresholding->Minimum = 50;
			this->thresholding->Name = L"thresholding";
			this->thresholding->Size = System::Drawing::Size(147, 56);
			this->thresholding->TabIndex = 65;
			this->thresholding->Value = 50;
			this->thresholding->Scroll += gcnew System::EventHandler(this, &MyForm::thresholding_Scroll);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->ClientSize = System::Drawing::Size(815, 552);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->comvalue);
			this->Controls->Add(this->Blinding);
			this->Controls->Add(this->LogValue);
			this->Controls->Add(this->gammavalue);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->medianFil);
			this->Controls->Add(this->topbar);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->GrayImg);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->buttonTransE);
			this->Controls->Add(this->buttonTrans1);
			this->Controls->Add(this->UploadImg);
			this->Controls->Add(this->SobelFil);
			this->Controls->Add(this->gauss);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->powertrans);
			this->Controls->Add(this->Graysclicing);
			this->Controls->Add(this->BitPlane);
			this->Controls->Add(this->LogTransformF);
			this->Controls->Add(this->negative_im);
			this->Controls->Add(this->equali);
			this->Controls->Add(this->image_zoom);
			this->Controls->Add(this->pictureBox1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Image Processing";
			this->TransparencyKey = System::Drawing::Color::Black;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->topbar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gammavalue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogValue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->comvalue))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->thresholding))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		namedWindow("image", 0);
		imshow("image", src);
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	equalizeHist(src, src);
	imwrite("image.jpg", src);
	pictureBox1->ImageLocation = "image.jpg";
	//namedWindow("image", 0);
	//imshow("image", src);
}
private: System::Void translation_Click(System::Object^ sender, System::EventArgs^ e) {

	int tx = Convert::ToInt32(XValue ->Text);
	int ty = Convert::ToInt32(YValue ->Text);
	Mat tr = (Mat_<float>(2, 3) << 1, 0, tx, 0, 1, ty);
	warpAffine(src, src, tr, src.size());
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
	//namedWindow("image", 0);
	//imshow("image", src);

}
private: System::Void negative_im_Click(System::Object^ sender, System::EventArgs^ e) {
	
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0 ; j < src.cols; j++)
		{
			src.at<uchar>(i, j) = 255 - src.at<uchar>(i, j);
		}
	}
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	//MessageBox::Show("Do you want to delet your work?", "worning");
	//reset button
	//src = imread("1.JPG", 0);
	src = imread(x);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void rotation_Click(System::Object^ sender, System::EventArgs^ e) {
	int R_degree = Convert::ToInt32(Deg->Text);
	float R_Scale = Convert::ToDouble(scal->Text);
	Mat RM = getRotationMatrix2D(Point2f(src.cols / 2, src.rows / 2), R_degree,R_Scale);           //to get the rotation mat takes the rotation point,angle,scale
	warpAffine(src,src , RM, src.size());
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void DeskewingF_Click(System::Object^ sender, System::EventArgs^ e) {
	float Skew_Val = Convert::ToDouble(skewValue->Text);
	Point2f src_p[3];                              //the three source points
	src_p[0] = Point2f(0, 0);
	src_p[1] = Point2f(src.cols - 1, 0);
	src_p[2] = Point2f(Skew_Val, src.rows - 1);

	Point2f dst_p[3];                          //the three destination points (usually the first two is the same as the source
	dst_p[0] = Point2f(0, 0);
	dst_p[1] = Point2f(src.cols - 1, 0);
	dst_p[2] = Point2f(0, src.rows - 1);

	Mat SM = getAffineTransform(src_p, dst_p);

	warpAffine(src, src, SM, src.size());
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void image_zoom_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat Zooming = src(Rect(0, 0, src.cols / 2, src.rows / 2));
	//resize(src, src, src.size(), 2, 2, 0);
	imwrite("save.jpg", Zooming);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void reflection_Click(System::Object^ sender, System::EventArgs^ e) {
	//left to Right , around Y
	flip(src, src, 0);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void Blinding_Click(System::Object^ sender, System::EventArgs^ e) {
	//double source_value = Convert::ToDouble(SourceVal->Value/10);
	//double blind_value = Convert::ToDouble(BlindVal->Value/10);
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		Mat src2, dst;
		path = openFileDialog1->FileName;
		string x;
		MarshalString(path, x);
		src2 = imread(x);
		cvtColor(src2, src2, COLOR_BGR2GRAY);
		resize(src2, src2, src.size());
		addWeighted(src, 0.8, src2, 0.2, 0, dst);
		imwrite("save.jpg", dst);
		pictureBox1->ImageLocation = "save.jpg";
	}
	//Mat src2 = imread("xx.png", 0);
	//resize(src2, src2, src.size());
	//Mat dst(src.size(), CV_8UC1, Scalar(0));

	//for (int i = 0; i < src.rows; i++)
	//{
		//for (int j = 0; j < src.cols; j++)
		//{
			//dst.at<uchar>(i, j) = src.at<uchar>(i, j) * 0.8 + src2.at<uchar>(i, j) * 0.2;
		//}
	//}

	//namedWindow("SRC1", 0);
	//imshow("SRC1", src);
	//namedWindow("SRC2", 0);
	//imshow("SRC2", src2);
	//namedWindow("Blinding", 0);
	//imshow("Blinding", dst);

}
private: System::Void LogTransformF_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat dst(src.rows, src.cols, CV_32FC1);
	double Log_value = Convert::ToDouble(LogValue->Value);
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			dst.at<float>(i, j) = log(src.at<uchar>(i, j) + Log_value);
		}
	}
	normalize(dst, dst, 0, 255, NORM_MINMAX);
	convertScaleAbs(dst, dst);
	imwrite("save.jpg", dst);
	pictureBox1->ImageLocation = "save.jpg";

}
private: System::Void powertrans_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat dst2(src.rows, src.cols, CV_32FC1);
	double GammaValue = Convert::ToDouble(gammavalue-> Value);

	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			dst2.at<float>(i, j) = powf(src.at<uchar>(i, j), GammaValue);
		}
	}
	normalize(dst2, dst2, 0, 255, NORM_MINMAX);
	convertScaleAbs(dst2, dst2);
	imwrite("save.jpg", dst2);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void BitPlane_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			if (src.at<uchar>(i, j) & 64)
				src.at<uchar>(i, j) = 255;
			else src.at<uchar>(i, j) = 0;
		}
	}
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void Graysclicing_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			if (src.at<uchar>(i, j) > 130 && src.at<uchar>(i, j) < 200)
				src.at<uchar>(i, j) = 255;
			else src.at<uchar>(i, j) = src.at<uchar>(i, j);
		}
	}
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void TradFill_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat dstT;
	Mat kernel_T = (Mat_<float>(3, 3) << 1, 1, 1, 1, 1, 1, 1, 1, 1);
	kernel_T = kernel_T / 9;
	filter2D(src, src, CV_8UC1, kernel_T);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";

}
private: System::Void pyramFil_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat kernel_p = (Mat_<float>(5, 5) << 1, 2, 3, 2, 1, 2, 4, 6, 4, 2, 3, 6, 9, 6, 3, 2, 4, 6, 4, 2, 1, 2, 3, 2, 1);
	kernel_p = kernel_p / 81;

	filter2D(src, src, CV_8UC1, kernel_p);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void cilFil_Click(System::Object^ sender, System::EventArgs^ e) {

	Mat kernel_c = (Mat_<float>(5, 5) << 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0);

	kernel_c = kernel_c / 21;

	filter2D(src, src, CV_8UC1, kernel_c);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";

}
private: System::Void ConFil_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat kernel_c1 = (Mat_<float>(5, 5) << 0, 0, 1, 0, 0, 0, 2, 2, 2, 8, 1, 2, 5, 2, 1, 0, 2, 2, 2, 0, 0, 0, 1, 0, 0);
	kernel_c1 = kernel_c1 / 25;
	filter2D(src, src, CV_8UC1, kernel_c1);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void ThresholdSeg_Click(System::Object^ sender, System::EventArgs^ e) {
	double Thresh_Value = Convert::ToDouble(thresholding->Value);
	double th = Thresh_Value;
	for (int x = 0; x < 3; x++)
	{
		threshold(src, src, th, 255, THRESH_BINARY);
		//namedWindow("image", 0);
		//createTrackbar("Threshold","image", &th, 255);
		imwrite("save.jpg", src);
		pictureBox1->ImageLocation = "save.jpg";
	}
}
private: System::Void EdgeBasedSeg_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void gauss_Click(System::Object^ sender, System::EventArgs^ e) {
	GaussianBlur(src, src, cv::Size(3,3), 3,0);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void laplacSeg_Click(System::Object^ sender, System::EventArgs^ e) {
	Laplacian(src, src, CV_8UC1);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void SobelFil_Click(System::Object^ sender, System::EventArgs^ e) {
	Mat kernel_TH = (Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
	filter2D(src, src, CV_8UC1, kernel_TH);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";

	Mat kernel_TV = (Mat_<int>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
	filter2D(src, src, CV_8UC1, kernel_TV);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";

	Mat kernel_Td = (Mat_<int>(3, 3) << 2, 1, 0, 1, 0, -1, 0, -1, -2);
	filter2D(src, src, CV_8UC1, kernel_Td);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";

	addWeighted(src, 1, src, 1, 0, src);
	addWeighted(src, 1, src, 1, 0, src);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	//right to left , around x
	flip(src, src, 1);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	//down to up, around Y
	flip(src, src, 0);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
	//namedWindow("image", 0);
	//imshow("image", src);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//down to up, around Y
	flip(src, src, -1);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void button2_Click_2(System::Object^ sender, System::EventArgs^ e) {
	float Skew_Val = Convert::ToDouble(skewValue->Text);
	Point2f src_p[3];                              //the three source points
	src_p[0] = Point2f(0, 0);
	src_p[1] = Point2f(src.cols - 1, 0);
	src_p[2] = Point2f(-Skew_Val, src.rows - 1);

	Point2f dst_p[3];                          //the three destination points (usually the first two is the same as the source
	dst_p[0] = Point2f(0, 0);
	dst_p[1] = Point2f(src.cols - 1, 0);
	dst_p[2] = Point2f(0, src.rows - 1);

	Mat SM = getAffineTransform(src_p, dst_p);

	warpAffine(src, src, SM, src.size());
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void UploadImg_Click(System::Object^ sender, System::EventArgs^ e) {
	ofd->InitialDirectory = ("Pictures");
	//ofd->Filter = "jpg files (.jpg)|.jpg|All files (.)|.PNG|.";
	ofd->FilterIndex = 2;
	ofd->RestoreDirectory = true;

	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		path = ofd->FileName;



		MarshalString(path, x);
		src = imread(x);
		if (src.empty()) {
			std::cout << "no image";
		}
		pictureBox1->ImageLocation = path;


	}



		//OpenFileDialog ofd = new OpenFileDialog();
	//if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	//{
		//pictureBox1->Image = Image::FromFile(ofd->FileName);
	//}

		 //po
		//PictureBox ->ImageLocation = ofd->FileName;
		//path = System::IO::Path::GetDirectoryName(ofd->FileName);
		//files = System::IO::Directory::GetFiles(path);

}
	   int count;
private: System::Void buttonTrans1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (buttonTrans1->Text == "Edit")
	{
		timer1->Start();
		buttonTrans1->Text = "<";
	}
	else {
		timer2->Start();
		buttonTrans1->Text = "Edit";
	}
}   

private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (count < 10) {
		Form::Width += 25;
		count++;
	}
	else
	{
		timer1->Stop();
	}
}
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (count > 0) {
		Form::Width -= 25;
		count--;
	}
	else
	{
		timer2->Stop();
	}
}
private: System::Void button2_Click_3(System::Object^ sender, System::EventArgs^ e) {
	if (buttonTransE->Text =="Enhancement")
	{
			timer3->Start();
			buttonTransE->Text = "<";
	}
	else
	{
		timer4->Start();
		buttonTransE->Text = "Enhancement";
	}
}
	   int count1;
private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (count1 < 10) {
		Form::Height += 25;
		count1++;
	}
	else
	{
		timer3->Stop();
	}
}

private: System::Void timer4_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (count1 > 0) 
	{
		Form::Height -= 25;
		count1--;
	}
	else
	{
		timer4->Stop();
	}
}
private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void GrayImg_Click(System::Object^ sender, System::EventArgs^ e) {
	cvtColor(src, src, COLOR_BGR2GRAY);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Environment::Exit(0);
}
private: System::Void medianFil_Click(System::Object^ sender, System::EventArgs^ e) {
	medianBlur(src, src,7);
	imwrite("save.jpg", src);
	pictureBox1->ImageLocation = "save.jpg";

}
private: System::Void button2_Click_4(System::Object^ sender, System::EventArgs^ e) {
	Mat FI;
	int d0 = 100;
	Mat DFTSHOW(Mat planes[2]);

	int m = getOptimalDFTSize(src.rows);
	int n = getOptimalDFTSize(src.cols);
	Mat padded;
	copyMakeBorder(src, padded, 0, m - src.rows, 0, n - src.cols, 0);
	padded.convertTo(padded, CV_32FC1, 1.0 / 255.0);
	Mat planes[2] = { padded,Mat::zeros(padded.size(),CV_32FC1) };
	Mat complexI;
	merge(planes, 2, complexI);
	dft(complexI, complexI);
	split(complexI, planes);

	/////////////////////////////////////
	int cx = complexI.cols / 2;
	int cy = complexI.rows / 2;
	Mat p1(complexI, Rect(0, 0, cx, cy));
	Mat p2(complexI, Rect(cx, 0, cx, cy));
	Mat p3(complexI, Rect(0, cy, cx, cy));
	Mat p4(complexI, Rect(cx, cy, cx, cy));
	Mat temp;
	p1.copyTo(temp);
	p4.copyTo(p1);
	temp.copyTo(p4);
	p2.copyTo(temp);
	p3.copyTo(p2);
	temp.copyTo(p3);
	split(complexI, planes);
	//////////////////////////////////////
	Mat Lfilter(complexI.size(), CV_32FC1);
	namedWindow("after IDFT", 0);
	for (int i = 0; i < Lfilter.rows; i++)
		for (int j = 0; j < Lfilter.cols; j++)
		{
			double z1 = i - Lfilter.rows / 2;
			double z2 = j - Lfilter.cols / 2;
			if (sqrt(pow(z1, 2) + pow(z2, 2)) > d0)
				Lfilter.at<float>(i, j) = 0;
			else
				Lfilter.at<float>(i, j) = 1;
		}
	Mat outR, outI;
	multiply(planes[0], Lfilter, outR);
	multiply(planes[1], Lfilter, outI);
	Mat out_planes[2] = { outR,outI };
	Mat out_complexI;
	merge(out_planes, 2, out_complexI);
	idft(out_complexI, out_complexI);
	//split(out_complexI,planes);
	/////////////DFT visualization////////////////
	split(out_complexI, planes);
	Mat out;
	magnitude(planes[0], planes[1], out);
	normalize(out, out, 1, 0, NORM_MINMAX);
	imshow("after IDFT", out);
	imwrite("x.jpg", out);
	pictureBox1->ImageLocation = "x.jpg";
}
private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
	std::vector<int>params;
	params.push_back(IMWRITE_JPEG_QUALITY);
	params.push_back(Convert::ToInt32(comvalue->Value));
	// that's percentage, so 100 == no compression, 1 == full 											   

	imwrite("save.jpg", src, params);
	pictureBox1->ImageLocation = "save.jpg";
}
private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Mat copy;
	copy = src.clone();
	cvtColor(copy, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, cv::Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, cv::Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, copy);

	imshow("Image", copy);
	imwrite("save.jpg", copy);

	pictureBox1->ImageLocation = "save.jpg";
	//imshow("Image Gray", imgGray);
	//imshow("Image Blur", imgBlur);
	//imshow("Image Canny", imgCanny);
	//imshow("Image Dil", imgDil);

	waitKey(0);
}
private: System::Void degree_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox6_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void gammavalue_Scroll(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void thresholding_Scroll(System::Object^ sender, System::EventArgs^ e) {
}
};


}
