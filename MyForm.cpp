#include "MyForm.h"
#include <io.h>
using namespace System;
using namespace System::Windows::Forms;
using namespace Lecik;

[STAThreadAttribute]


int main(array<String ^> ^args)
{
	Application::EnableVisualStyles();						//EnableVisualStyles() musi zostaæ wywo³ana przed utworzeniem jakichkolwiek formantów w aplikacji, najczesciej pierwsza metoda w funkcji main(tak jak w tym przypadku)
	Application::SetCompatibleTextRenderingDefault(false);	// nowe kontrolki renderuja i mierza tekst przy pomocy TextRenderer class
	MyForm Uart;										//Reprezentuje okno lub okno dialogowe tworz¹cych interfejsu u¿ytkownika aplikacji.Stworzenie nowego obiektu klasy MyForm.
	Application::Run(%Uart);								// klasa Application zawiera min. metody do otwarci i zamkniecia aplikacji,tutaj bd uzywac metody Run(Form^) do odpalaenia naszej formy i wywietlenia jej na ekranie
	
	return 0;
}