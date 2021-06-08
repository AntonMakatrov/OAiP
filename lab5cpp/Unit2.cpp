//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "list.h"
#include "list.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
extern int choose;
extern Queque<int> queque;
extern List list;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	if (choose == 1)
	{
		int number, i = 0;
		int size = StrToInt(Edit1 -> Text);
		if (size < 0) throw new Exception("Число строк не может быть отрицательным");
		while (i != size)
		{
			number = rand();
			list.push_back(number);
			i++;
		}
		for (int i = 0; i < list.size(); i++)
		{
			Form1 -> ListBox1 -> Items -> Add(list[i].data);
		}
		Form1 -> Button1 -> Visible = False;
		Form1 -> Button2 -> Visible = True;
		Form1 -> Button3 -> Visible = True;
		Form1 -> Button4 -> Visible = True;
		Form1 -> Button5 -> Visible = True;
        Form1 -> Button8 -> Visible = True;
	}
	else if (choose == 2)
	{
		int number = StrToInt(Edit1 -> Text);
		queque.push_back(number);
		Form1 -> ListBox1 -> Items -> Clear();
		for (int i = 0; i < queque.size(); i++)
		{
			Form1 -> ListBox1 -> Items -> Add(IntToStr(queque[i]));
		}
	}
	ModalResult = mrOk;
	Edit1 -> Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button2Click(TObject *Sender)
{
	ModalResult = mrCancel;
    Edit1 -> Text = "";
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

