#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

//#include <conio.h>
using namespace std;

struct MOT
{
	char mnemonics[4];
	char opcode;
	char instruction[2];
	char format[3];

};
struct POT
{
	char pseudo_op[5];
	char address;
};
struct SYMBOL
{
		char symbol[8];
		int value;
		char length;
		bool relocation;
};
struct LITERAL
{
		char symbol[8];
		char value[4];
		char length;
		bool relocation;
};

class Assembler
{
	
public:
	Assembler();
	 void addMOT();
	 void addPOT();
	 void addSOT(string,int,int,bool);
	 void view();
	 int findOperandLength(string);
	 void Init();
	 void operate(string, string, string,int, int);
	 void convert();
	 
};
Assembler::Assembler()
{
	Init();
}

void Assembler::Init()
{
	
}

void Assembler::view()
{
	ifstream in;
	in.open("MOT.txt");
	if(!in)
	{
		cout<<"Program self Error Handle: Unable to open MOT\n";
		exit(29);
	}
	char stream[10];
	in>>stream;
	MOT m;
	
	// OUTPUT FORMATTER CODE FOR DISPLAYING INSTRUCTIONS ....
		cout<<"Instruction\tOpCode\tInstruction\tFormat\n";
	//.......................................................
	int j=0;
	int k=0;
	int l=0;
	for(int i=0;i<10;i++)
	{
		if(i<4)
		{
			m.mnemonics[j]=stream[i];
			j++;
		}
		else if(i<5)
		{
			m.opcode=stream[i];
		}
		else if(i<7)
		{
			m.instruction[k]=stream[i];

			k++;
		}
		else
		{
			m.format[l]=stream[i];
			l++;
		}
	}
	cout<<m.instruction<<" "<<m.opcode<<" "<<m.instruction<<" "<<m.format;
	
	in.close();

	
}
 void Assembler::addMOT()
{
	ofstream out;
	out.open("MOT.txt",ios::app);
	if(!out)
	{
		cout<<"Program self Error Handle: Unable to open MOT\n";
		exit(29);
	}
	MOT m;
	cout<<"Mnemonic[4]: ";
	cin>>m.mnemonics;
	out<<m.mnemonics;
	cout<<"\nBinary Op Code[1] :";
	cin>>m.opcode;
	out<<m.opcode;
	cout<<"\nInstruction Length[2] :";
	cin>>m.instruction;
	out<<m.instruction;
	cout<<"\n Format[3] :";
	cin>>m.format;
	out<<m.format;
	out<<endl;
	out.close();
}
 void Assembler::addPOT()
{
	ofstream out;
	out.open("POT.txt",ios::app);
	if(!out)
	{
		cout<<"Program self Error Handle: Unable to open POT\n";
		exit(29);
	}
	POT m;
	cout<<"\nEnter Pseudo-Op :";
	cin>>m.pseudo_op;
	out<<m.pseudo_op;
	cout<<"\nAddress of subroutine :";
	cin>>m.address;
	out<<m.address;
	out<<endl;
	cout<<"\nSuccesfully written to POT\n";

	
}

 void Assembler::convert()
{
	ofstream out;
	ifstream in;
	in.open("source.txt");
	if(!in)
		cout<<"Internal Error Handler \nFailed to open the source file. Check directory structure or permission \n";
	char SYMBOL[8];
	char INSTRUCTION[5];
	char OPERAND[10];
	int lineNo=0;;;;;;
	int OPERAND_LENGTH=1;
	//SOURCE CODE FORMATTER	
		//**************************************************
		//**************************************************
		cout<<"RAW FILE: \n";
		//**************************************************
		//**************************************************
	int wc=1;
	int p=0;
	while(1)
	{
		
		char ch=in.get();
		
		//cout<<ch;
		if(ch==' ' &&  p ==0)
		{
			cout<<"Space in Indentation not allowed. line no :"<<lineNo+1;
			exit(99);
		}
		if(p<=7 && wc==1)
		{
			if(ch ==' ')
			{
				wc=2;
				SYMBOL[p]='\0';
			}
			else
			{
				SYMBOL[p]=ch;
				p++;
			}
		}
		else 
		{
			p=0;
		}
		if(p<5 && wc ==2)
		{
			if(ch==' ')
			{
				wc=3;
				INSTRUCTION[p]='\0';
			}
			else
			{
				INSTRUCTION[p]=ch;
				p++;
				
			}
		}
		else
			p=0;
		if(p<8 && wc ==3)
		{
			if(ch=='\n' || ch==' ')
			{
				wc=1;
				INSTRUCTION[p]='\0';
			}
			else
				{
					INSTRUCTION[p]=ch;
				p++;
				}
		}	
		else
			p=0;
		//operate(SYMBOL,INSTRUCTION,OPERAND,findOperandLength(OPERAND),lineNo);
		if(ch=='\n' || ch==EOF)
		{
			lineNo++;
			//Printing stored values;
			cout<<"\nSYMBOL :"<<SYMBOL;
			cout<<"\nINSTRUCTION :"<<INSTRUCTION;
			cout<<"\nOPERAND :"<<OPERAND;
			for(int i=0;i<10;i++)
			{
				SYMBOL[i]=' ';
				INSTRUCTION[i]=' ';
				OPERAND[i]=' ';
			}
			if(ch==EOF)
			break;
		
		}
	}
}
	


  
    
int Assembler::findOperandLength(string OPERAND)
{
	int count=0;
	for(int i=0;i<OPERAND.length();i++)
	{
		if(OPERAND[i]==',')
			count++;
	}
	return count+1;
}
void Assembler::addSOT(string SYMBOL,int lineNo,int length,bool Relocation)
{
	ofstream out;
	out.open("SOT.txt",ios::app);
}
void Assembler::operate(string SYMBOL,string INSTRUCTION,string OPERAND,int OPERAND_LENGTH,int lineNo)
{
	ofstream out;
	out.open("I.txt",ios::app);
//	if(search(SYMBOL))
		
}
int main()
{	
	cout<<"Assembler\n";
	cout<<"Menu \n"<<"1- Add Instructions to MOT\n"<<"2- Add Instructions to POT\n"<<"3- View Instructions\n"<<"4- Convert \n"<<"5- Exit \n";
	int  c;
	cin>>c;
	Assembler a;
	switch(c)
	{
		case 1: 
			a.addMOT();
			break;
		case 2:
			a.addPOT();
			break;
		case 3: 
			a.view();
			break;
		case 4:
			a.convert();
		case 5:
			exit(24);
		default:
			cout<<"Wrong input exit\n";
			exit(0);
	}
}