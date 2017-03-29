#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

//#include <conio.h>
using namespace std;

struct MOT
{
	char mnemonics[4];//Characters
	char opcode[2];//Hexadecimal
	char instruction[2];//Binary
	char format[3];//Instruction format in binary.

};
struct POT
{
	char pseudo_op[5];
	char address;
};
struct SYMBOL
{
		char symbol[8];
		int value;//AKA RELATIVE ADDRESS
		int length;
		bool relocation;
};
struct LITERAL
{
		char symbol[8];
		char value;
		char length;
		bool relocation;
};

class Assembler
{
	
public:
	Assembler();
	 void addMOT();
	 void addPOT();
	 void addSOT(SYMBOL,int,int);
	 void view();
	 int findOperandLength(string);
	 void Init();
	 void operate(string, string, string,int, int);
	 void convert();
	 
};

Assembler::Assembler()
{
	
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
	int z=0;
	for(int i=0;i<10;i++)
	{
		if(i<4)
		{
			m.mnemonics[j]=stream[i];
			j++;
		}
		else if(i<6)
		{
			m.opcode[z]=stream[i];
			z++;
		}
		else if(i<8)
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
	cout<<"\nBinary Op Code[2] :";
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

void Assembler::addSOT(SYMBOL s,int address_aka_value,int length)
{
	ofstream out;
	out.open("SOT.txt",ios::app);
	if(!out)
		cout<<"\nError opening SOT file. Please check directory structure or permission";
	
	
	
	out.close();
}


int search(string word)
{
	//Module that searches for the machine operation in the machine operation table
	cout<<"\n++++++"<<word<<endl;
	ifstream in;
	in.open("MOT.txt");
	if(!in)
		{
			cout<<"\nError opening MOT file in search.";
			exit(39);
		}
	MOT m;
	for(int i=0;i<4;i++)
	{
		if(word[i]!='\0')
			m.mnemonics[i]=word[i];
		else
		{
			for(int j=i;j<4;j++)
			{
				m.mnemonics[j]='b';
			}
			break;
		}
	}
	cout<<"LOOK HERE "<<m.mnemonics;
	char line[12];
	while(in.getline(line,12))
	{
		//cout<<"\nLOOK HERE"<<line;
		
	}
	
	/*for(int i=0;i<11;i++)
	{
		if(word[i]=='\0')
		{
			for(int j=i;j<11;j)
		}
		m.mnemonics[i]=word[i];
		
	}*/
	
	in.close();
		
}
void Assembler::convert()
{	
	int _base;
	cout<<"\nEnter the value of the base register :";
	cin>>_base;
	
	ofstream out;
	ifstream in;
	in.open("source.txt");
	out.open("I.txt");
	if(!in)
		cout<<"Internal Error Handler \nFailed to open the source file. Check directory structure or permission \n";
	if(!out)
		cout<<"Internal Error Handler \nFailed to open the Intermediate file. Check directory structure or permission \n";

	
	char line[20];
	int lineNo=0;;;;;;
	int rel_location=0;
	int OPERAND_LENGTH=1;
	
	//SOURCE CODE FORMATTER	
		//**************************************************
		//**************************************************
		cout<<"RAW FILE: \n";
		//**************************************************
		//**************************************************
		int count=0;
		int i=0;
		char lastchar;
		string word1,word2,word3;
		while(in.getline(line,25))
		{
			SYMBOL S;
			lineNo++;
			count=0;
			for(int i=0;line[i]!='\n' && i<25;i++)
			{
				if(line[i]=='\t')
					count++;
			}
			if(count !=2 && count!=3)
			{
				cout<<"\nError : No of arguements in line no \n"<<lineNo;
				exit(29);
			}

			else
			{
					istringstream ss(line);
					if(count==3)
						{
							ss>>word2>>word3;
							word1="NULL";
						}
						
					else
						ss>>word1>>word2>>word3;
			}
			//DEBUG..............................
			cout<<word1<<" "<<word2<<" "<<word3;
			cout<<" count: "<<count<<endl;
			//...................................
			
			if(word1!="NULL")
			{
				for(int i=0;i<8;i++)
				{
					if(word1[i]!='\0')
						S.symbol[i]=word1[i];
					else
					{
						for(int j=i;j<8;j++)
							S.symbol[j]='0';
						break;
					}
						
				}
			}
			S.length=findOperandLength(word3);
			S.value=rel_location;
			//cout<<"\nDEBUG NOW"<<S.length;
			if(search(word2))
			{
				//Here ---->>>>>>>>>>
			}
			else
			{
				cout<<"\nNo such Machine Operation Found at line no :"<<lineNo<<"\nTerminating..";
				exit(29);
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