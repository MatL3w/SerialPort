#include<iostream>

namespace Lecik {
	using namespace System;						// System zawiera klasy podstawowe i klasy bazowe, definiuj¹ce powszechnie u¿ywane wartoœci odniesienia typów danych, zdarzenia i procedury obs³ugi zdarzeñ, interfejsy, atrybuty i wyj¹tki przetwarzania.
	using namespace System::ComponentModel;		// System.ComponentModel Nazw zawiera klasy, które s¹ u¿ywane do implementowania zachowanie run-time i czasu projektowania sk³adników i formanty.Ten obszar nazw zawiera podstawowych klas i interfejsów dla realizacji atrybuty i konwertery typu, wi¹zanie danych Ÿróde³ i licencjonowania sk³adników.
	using namespace System::Collections;		// Przestrzenie nazw System.Collections zawieraj¹ typy definiuj¹ce obiekty ró¿nych kolekcji standardowych, specjalizowanych i ogólnych.
	using namespace System::Windows::Forms;		// System.Windows.Forms Nazw zawiera klasy dla tworzenia aplikacji opartych na systemie Windows, które w pe³ni korzystaæ u¿ytkownika bogate funkcje interfejsu, które s¹ dostêpne w systemie operacyjnym Microsoft Windows.
	using namespace System::Data;				// Przestrzenie nazw System.Data zawieraj¹ klasy s³u¿¹ce do uzyskiwania dostêpu do danych pochodz¹cych z ró¿nych Ÿróde³ oraz zarz¹dzania tymi danymi.
	using namespace System::Drawing;			// System.Drawing Nazw zapewnia dostêp do funkcji podstawowych elementów graficznych GDI +.
	using namespace System::IO::Ports;			// System.IO.Ports Przestrzeñ nazw zawiera klasy steruj¹ce seryjny portów.Najwa¿niejsze klasy, SerialPort, oferuje strukturê synchroniczne sterowanym zdarzeniami we/wy, dostêp do kodu pin i podzia³u stanów i dostêp do w³aœciwoœci seryjny sterownika.Mo¿e s³u¿yæ do zakodowania Stream obiektów, umo¿liwiaj¹c seryjny mo¿na uzyskaæ dostêp przez klasy, które u¿ywaj¹ strumieni.
	using namespace System::IO;					// Obszar nazw System.IO zawiera typy, zezwalaj¹ce na odczyt i zapis do plików i strumienie danych oraz typy, które dostarczaj¹ podstawowych plików i obs³ugi technicznej katalogu.


	public ref class MyForm : public System::Windows::Forms::Form //Klasa MyForm
	{
	public:
		MyForm(void)
		{
			InitializeComponent();		//wywolanie funkcji ktora ³aduje skompilowane strony sk³adnika.
			findPorts();				// wywolanie funkcji ktora szuka dostepnych portów
			
		}

	protected:
		
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
		// Wszystkie obiekty kotrych bd uzywac w MyFormie
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button5;
	private: System::ComponentModel::IContainer^  components;


		void InitializeComponent(void)	// inicjalizacja naszychn obiektow: jak wymiary jakie wartosc itp.	Wa¿ne jest u¿ycie gcnew typami CLR
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(490, 21);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 0;
			// 
			// comboBox2
			// 
			this->comboBox2->AllowDrop = true;
			this->comboBox2->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"9600", L"115200" });
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"9600", L"38400", L"115200" });
			this->comboBox2->Location = System::Drawing::Point(490, 82);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 33);
			this->comboBox2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(354, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"PORTY";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(354, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(130, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Prêdkoœæ transmisji";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(357, 131);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 29);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Za³¹cz Port";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(357, 166);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 31);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Od³¹cz Port";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 79);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(331, 55);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"otrzymujesz";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 183);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(331, 45);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"nadajesz";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(65, 140);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 37);
			this->button3->TabIndex = 8;
			this->button3->Text = L"WYSY£AJ";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(180, 140);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(85, 37);
			this->button4->TabIndex = 9;
			this->button4->Text = L"CZYTAJ";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 12);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(159, 45);
			this->progressBar1->TabIndex = 10;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(177, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 17);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Port Status";
			// 
			// button5
			// 
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->Location = System::Drawing::Point(435, 21);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(49, 31);
			this->button5->TabIndex = 12;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(636, 250);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"UART";
			this->TransparencyKey = System::Drawing::Color::Red;
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		//szuka dostepnych portów
	private: void findPorts(void)
	{
		this->comboBox1->Items->Clear(); // czysci comboboxa
		array<Object^>^ objectArray = SerialPort::GetPortNames(); // pobiera dostepne porty i ich nazwy umieszcza w tablicy
		this->comboBox1->Items->AddRange(objectArray); //umieszcza w combboxie nazwy dostepnych portow
		
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->serialPort1->Close();//zamyka port
		this->progressBar1->Value = 0;//czyscy progresbar
		this->textBox2->Text = "Port zosta³ zamkniêty";//czysci textboxa
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
	
	if (this->serialPort1->IsOpen) //sprawdza czy port jest otwarty
		{
		this->textBox1->Text = String::Empty;// restuje napis w textbox1
		
		try // odzczytuje dane z portu
			{
			this->textBox1->Text = this->serialPort1->ReadLine();
			}
		catch (TimeoutException^) //jesli sie nie uda odczytac wypisuje blad
			{
			this->textBox1->Text = "ERROR";
			}
		}
	else
		
		this->textBox2->Text = "Port Zamkniêty";
		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
	this->textBox1->Text = String::Empty;
	if (this->comboBox1->Text == String::Empty || this->comboBox2->Text == String::Empty)
		this->textBox2->Text = "Wybierz ustawienia portu!";
	else {
		try 
		{
			
			if (!this->serialPort1->IsOpen) //upewnia sie ze port nie jest otawrty
			{
				this->serialPort1->PortName = this->comboBox1->Text;			
				this->serialPort1->BaudRate = Int32::Parse(this->comboBox2->Text); //ustawi predkosc transmisji
				this->textBox2->Text = "Wpisz wiadomosc";	//info do textbox2 o wpisanie wiadomosci
				this->serialPort1->Open();	//otwiera wybrany port
				this->progressBar1->Value = 100; // ustawia progressbara na maxa(info ze wszystko jest ok)
			}
			else
				this->textBox2->Text = "Port juz jest otwarty!";
		}
		catch (UnauthorizedAccessException^) 
		{
			this->textBox2->Text = "B³ad";
		}
		}
}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
	String^ name = this->serialPort1->PortName;	//pobieramy nazwe portu
	String^ message = this->textBox2->Text;		//pobieramy wiadomosc do wyslania
	if (this->serialPort1->IsOpen)
		this->serialPort1->WriteLine(message);//jesli port jest otwarty wysyla wiadomosc
	else
		this->textBox2->Text = "Port zamkniêty";//a jesli nie jest to o tym informuje
	}

	private: System::Void button5_Click_1(System::Object^  sender, System::EventArgs^  e) 
	{
	findPorts(); //ponownie szukam dostepnych portow
	}

};
}
