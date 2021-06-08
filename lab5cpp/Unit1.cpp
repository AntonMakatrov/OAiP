//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "list.h"
#include "list.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Queque<int> queque;
List list;
int choose;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	srand(time(NULL));
	Form1 -> Button1 -> Visible = True;
	Form1 -> Button2 -> Visible = True;
	Form1 -> Button3 -> Visible = True;
	Form1 -> Button4 -> Visible = True;
	Form1 -> Button5 -> Visible = True;
    Form1 -> Button8 -> Visible = True;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    ListBox2 -> Items -> Clear();
	Form2 -> Edit1 -> TextHint = "Введите кол-во элементов";
	choose = 1;
	Form2 -> ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    ListBox2 -> Items -> Clear();
	Form2 -> Edit1 -> TextHint = "Введите строку";
	choose = 2;
	Form2 -> ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	queque.clear();
	ListBox1 -> Items -> Clear();
    ListBox2 -> Items -> Clear();
	for (int i = 0; i < queque.size(); i++)
	{
		ListBox1 -> Items -> Add(IntToStr(queque[i]));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	queque.is_empty(ListBox1);
    ListBox2 -> Items -> Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	ListBox1 -> Items -> Clear();
    ListBox2 -> Items -> Clear();
	for (int i = 0; i < queque.size(); i++)
	{
		ListBox1 -> Items -> Add(IntToStr(queque[i]));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int i, number;
	int size = rand() % 30 + 3;
	ListBox1 -> Items -> Clear();
	ListBox1 -> Items -> Add("Неотсортированный");
	while (i != size)
	{
		number = rand() - 5000;
		list.push_back(number);
		i++;
	}
	for (int i = 0; i < list.size(); i++)
	{
		ListBox1 -> Items -> Add(list[i].data);
	}
	ListBox2 -> Items -> Clear();

	for (int i = 0; i < list.size(); i++)
	{
		ListBox2 -> Items -> Add(list[i].data);
	}
	//list.clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	queque.pop_front();
	ListBox1 -> Items -> Clear();
    ListBox2 -> Items -> Clear();
	for (int i = 0; i < queque.size(); i++)
	{
		ListBox1 -> Items -> Add(IntToStr(queque[i]));
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------



void __fastcall TForm1::Button7Click(TObject *Sender)
{

	//for (int i = 0; i < queque.size(); i++)
   //	{
   //		ListBox1 -> Items -> Add(list[i].data);
   //	}
   //	ListBox1->Items->Clear();
   for (int i = 0; i < ListBox1->Count; i++)
   {

		if( ListBox1->Selected[i])
		{
			ListBox2->Items->Add(IntToStr(i));
		}
   }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	//Node<String> *p = list.GetItem(3) ;
	for(int i = 0; i<ListBox1->Count;i++ )
   {
		if( ListBox1->Selected[i])
		{
			for(int k = 0; k<ListBox2->Count;k++)
			{
			  Node<String> *n = list.sort(list.GetItem(StrToInt(ListBox2->Items->Strings[k])));
			  list.insertBefore(&list ,list.GetItem(i),n);

			}
			ListBox2->Items->Clear();
		}
   }


   ListBox1->Items->Clear();
  // for(int i = 0; i< list.size();i++)
   //{
   //	   ListBox1->Items->Add(list[i].data);
  // }
   list.Show(ListBox1);

}
//---------------------------------------------------------------------------

