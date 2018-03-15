#include<bits/stdc++.h>
using namespace std;

int lines=0, break_point=INT_MAX, memregflag=0, pc, line_number=1, dp, sp=1000;
vector<string> memoryLocations;
string program_counter, starting_address;
map<string, string> RAM;
map<string, int> commands;
map<string, int> inst_size;
map<string, int> memory;
map<char, int> registers;
map<char, int> flag;

//Load and store
void MOV(char,char);
void MVI(char,string);
void LDA(string);
void STA(string);
void LHLD(string);
void SHLD(string);
void STAX(char);
void XCHG();
void SPHL();
void XTHL();
void PUSH(char);
void POP(char);

//Arithamatic
void ADD(char);
void ADI(string);
int ADC(char);
int ACI(string);
void SUB(char);
void LXI(char,string);
void SUI(string);
void SBB(char);
void SBI(string);
void INR(char);
void INX(char);
void DCR(char);
void DCX(char);
void DAD(char);

//Branching
void JMP(string);
void JC(string);
void JNC(string);
void JZ(string);
void JNZ(string);
void JP(string);
void JM(string);
void JPE(string);
void JPO(string);

//logical
void CMA();
void CMP(char);
void SET(string, string);

//Required Functiom
string DecimalToHex(int);
string DecimalToBinary(int);
string int_to_str(int);
int BinaryToDecimal(string);
int HexToDecimal(string);
int lenint(int);
int parity(int);
int insturctionPresent(string);
int str_to_int(string);
int indexOf(string,char);
void test_flags_1(char);
void test_flags_2();
void test_carry(char);
void test_sign(char);
void test_zero(char);
void test_parity(char);
void test_auxilary(char);
void reset_flags();
void reset_registers();
void set_instructions_size();
void set_instructions();
bool test0(string);
bool test1(string);
bool test2(string);
bool test3(string);
bool test4(string);
bool test5(string);
bool test6(string);
bool test7(string);
bool test8(string);

int str_to_int(string str)
{
    int n;
    stringstream ss(str);
    ss>>n;
    return n;
}

string DecimalToHex(int n)
{
    stringstream ss;
    ss << hex << n;
    return ss.str();
}

int HexToDecimal(string s)
{
    istringstream converter(s);
    int value;
    converter>>hex>>value;
    return value;
}

string DecimalToBinary(int a)
{
	string str="";
	while(a>0)
	{
		str+=('0'+(a%2));
		a=a/2;
	}
	return str;
}

int BinaryToDecimal(string str)
{
	int temp,i,a=0;
	for(i=0;i<str.size();i++)
		a += pow(2,i) * (str[i]-'0');
	return a;
}

string int_to_str(int n)
{
    stringstream ss;
    ss<<n;
    return ss.str();
}

int indexOf(string s, char c)
{
    for(int i=0;i<s.size();i++)
        if(c==s[i])
            return(i);
    return -1;
}

int lenint(int a)
{
	int len=0;
	while(a>0)
	{
		len++;
		a=a/10;
	}
	return len;
}

int parity(int a)
{
	int count=0;
	while(a)
	{
		a=a&(a-1);
		count++;
	}
	if(count%2==0)
	return 0;
	else return 1;
}

int insturctionPresent(string s)
{
    if(s=="ADD"||s=="SUB"||s=="CMP"||s=="INR"||s=="DCR"||s=="LDA"||s=="STA"||s=="LHLD"||s=="SHLD"||s=="JMP"||s=="JC"||s=="JNC"||s=="JZ"||s=="JNZ"||s=="ADI"||s=="SUI"||s=="STAX"||s=="INX"||s=="DCX"||s=="MOV"||s=="LXI"||s=="MVI"||s=="SET")
        return 1;
    return 0;
}

bool test0(string s)
{
    if(s=="XCHG"||s=="CMA"||s=="PCHL"||s=="SPHL")
        return 1;
    return 0;
}

bool test1(string s)
{
    string a[] = {"A","B","C","D","E","H","L","M","a","b","c","d","e","h","l","m"};
    for(int i=0;i<8;i++)
        if(a[i] == s)
            return 1;
    return 0;
}

bool test2(string s)
{
    int flag=0;
    if(s.size()==4)
    {
        for(int i=0;i<4;i++)
            if(!((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='F') || (s[i]>='a' && s[i]<='f')))
                    flag = 1;
        if(flag==0)
            return 1;
    }
    return 0;
}
bool test3(string s)
{
    int flag=0;
    if(s.size()==2)
    {
        for(int i=0;i<2;i++)
            if(!((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='F') || (s[i]>='a' && s[i]<='f')))
                    flag = 1;
        if(flag==0)
            return 1;
    }
    return 0;
}
bool test4(string s)
{
    if(s=="B" || s=="D" || s=="H" || s=="b" || s=="d" || s=="h")
        return 1;
    return 0;
}

bool test5(string s)
{
    int f = indexOf(s,',');
    if(f!=-1)
    {
        string s1,s2;
        s1 = s.substr(0,1);
        s2 = s.substr(f+1,1);
        if(test1(s1) && test1(s2)&& (s1!=s2))
            return 1;
    }
    return 0;
}
bool test6(string s)
{
    int f = indexOf(s,',');
    if(f>-1)
    {
        string s1,s2;
        s1 = s.substr(0,1);
        s2 = s.substr(f+1,INT_MAX);
        if(test1(s1) && test3(s2))
            return 1;
    }
    return 0;
}
bool test7(string s)
{
    int f = indexOf(s,',');
    if(f!=-1)
    {
        string s1,s2;
        s1 = s.substr(0,1);
        s2 = s.substr(f+1,INT_MAX);
        if(test4(s1) && test2(s2))
            return 1;
    }
    return 0;
}
bool test8(string s)
{
    int f = indexOf(s,',');
    if(f!=-1)
    {
        string s1,s2;
        s1 = s.substr(0,f);
        s2 = s.substr(f+1,INT_MAX);
        if(test2(s1) && test3(s2))
            return 1;
    }
    return 0;
}

void test_flags_1(char operand)
{
	if(registers[operand]==0 || registers[operand]==128 || registers[operand]==-129)
    {
		flag['z']=1;
		registers[operand]=0;
	}
	else
		flag['z']=0;
}
void test_flags_2()
{
	if(registers['A']<0)
    {
		flag['s']=1;
		if(registers['A']<(-128))
		{
			flag['c']=1;
			registers['A']=129-registers['A'];
		}
	}
	else
	{
		flag['s']=0;
		flag['c']=registers['A']/128;
		registers['A']%=128;
	}
	if(registers['A']==0)
		flag['z']=1;
	else
		flag['z']=0;
}

void test_carry(char operand = 'A')
{
	if(registers[operand]>255)
    {
		flag['c']=1;
		registers[operand] %= 256;
	}
	else if(registers[operand]<0)
	{
		flag['c']=1;
		registers[operand]+=256;
	}
	else
		flag['c'] = 0;
}

void test_sign(char operand ='A')
{
	if(registers[operand]>127)
		flag['s']=1;
	else
		flag['s']=0;
}

void test_zero(char operand = 'A')
{
	if(registers[operand]==0)
		flag['z'] = 1;
	else
		flag['z'] = 0;
}

void test_parity(char operand = 'A')
{
	int count=0;
	int a = registers[operand];
	while(a)
	{
		a=a&(a-1);
		count++;
	}
	if(count%2==0)
		flag['p'] = 1;
	else
		flag['p'] = 0;
}

void test_auxilary(char operand = 'A'){}

void reset_flags()
{
    flag['z'] = 0;
    flag['s'] = 0;
    flag['c'] = 0;
    flag['p'] = 0;
    flag['a'] = 0;
}

void reset_registers()
{
    registers['A'] = 0;
    registers['B'] = 0;
    registers['C'] = 0;
    registers['D'] = 0;
    registers['E'] = 0;
    registers['H'] = 0;
    registers['L'] = 0;
}

void set_instructions_size()
{
    inst_size["MOV"] = 1;
    inst_size["XCHG"] = 1;
    inst_size["ADD"] = 1;
    inst_size["SUB"] = 1;
    inst_size["INR"] = 1;
    inst_size["DCR"] = 1;
    inst_size["INX"] = 1;
    inst_size["DCX"] = 1;
    inst_size["CMA"] = 1;
    inst_size["CMP"] = 1;
    inst_size["ADC"] = 1;
    inst_size["SBB"] = 1;
    inst_size["SPHL"] = 1;
    inst_size["XTHL"] = 1;
    inst_size["PUSH"] = 1;
    inst_size["POP"] = 1;
    inst_size["MVI"] = 2;
    inst_size["ADI"] = 2;
    inst_size["SUI"] = 2;
    inst_size["MVI"] = 2;
    inst_size["SBI"] = 2;
    inst_size["LDA"] = 3;
    inst_size["STA"] = 3;
    inst_size["LHLD"] = 3;
    inst_size["SHLD"] = 3;
    inst_size["STAX"] = 3;
    inst_size["JMP"] = 3;
    inst_size["JC"] = 3;
    inst_size["JNC"] = 3;
    inst_size["JZ"] = 3;
    inst_size["JNZ"] = 3;
    inst_size["SET"] = 4;
}

void set_instructions()
{
    commands["XCHG"] = 0;
    commands["CMA"] = 0;
    commands["SPHL"] = 0;
    commands["XTHL"] = 0;
    commands["ADC"] = 1;
    commands["SBB"] = 1;
    commands["SUB"] = 1;
    commands["ADD"] = 1;
    commands["INR"] = 1;
    commands["DCR"] = 1;
    commands["CMP"] = 1;
    commands["LDA"] = 2;
    commands["STA"] = 2;
    commands["LHLD"] = 2;
    commands["SHLD"] = 2;
    commands["JMP"] = 2;
    commands["JC"] = 2;
    commands["JNC"] = 2;
    commands["JZ"] = 2;
    commands["JNZ"] = 2;
    commands["ADI"] = 3;
    commands["SUI"] = 3;
    commands["ADI"] = 3;
    commands["SBI"] = 3;
    commands["PUSH"] = 4;
    commands["POP"] = 4;
    commands["STAX"] = 4;
    commands["DCX"] = 4;
    commands["MOV"] = 5;
    commands["MVI"] = 6;
    commands["LXI"] = 7;
    commands["SET"] = 8;
}

void display()
{
    if(dp==0)
    {
        int i;
        remove("outputFile.txt");
        ofstream outfile;
        outfile.open("outputFile.txt");
        cout<<"Values in Registers:\n";
        outfile<<"Values in Registers:"<<endl;
        char ch;
        string s,f;
        for(ch='A';ch<='E';ch=ch+1)
        {
            s = DecimalToHex(registers[ch]);
            transform(s.begin(), s.end(), s.begin(), ::toupper);
            f = ch;
            f = f+" : "+((s.size()==1)?("0"+s):s);
            cout<<f<<endl;
            outfile<<f<<endl;
        }

        s = DecimalToHex(registers['H']);
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        f = "H : "+((s.size()==1)?("0"+s):s);
        cout<<f<<endl;
        outfile<<f<<endl;

        s = DecimalToHex(registers['L']);
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        f = "L : "+((s.size()==1)?("0"+s):s);
        cout<<f<<endl;
        outfile<<f<<endl;

        cout<<"\nValues of Flags:\n";
        outfile<<"\nValues of Flags:"<<endl;

        f = "Z  : "+ int_to_str(flag['z']);
        cout << f << endl;
        outfile << f << endl;
        f = "S  : "+ int_to_str(flag['s']);
        cout << f << endl;
        outfile << f << endl;
        f = "C  : " + int_to_str(flag['c']);
        cout << f << endl;
        outfile << f << endl;
        f = "P  : " + int_to_str(flag['p']);
        cout << f << endl;
        outfile << f << endl;
        f = "AC : " + int_to_str(flag['a']);
        cout << f << endl;
        outfile << f << endl;

        cout << "\nMemory Locations Used : " << endl;
        outfile << "\nMemory Locations Used : " <<endl;
        if(memoryLocations.size())
        {
            for(i=0;i<memoryLocations.size();i++)
            {
                s = DecimalToHex(memory[memoryLocations[i]]);
                transform(s.begin(), s.end(), s.begin(), ::toupper);
                f=memoryLocations[i]+" : "+((s.size()==1)?("0"+s):s);
                cout<<f<<endl;
                outfile<<f<<endl;
            }
        }
        else
        {
            cout<<"None!"<<endl;
            outfile<<"None!"<<endl;
        }
        cout<<endl;
        outfile.close();
    }
}

void break_point_set(int ch)
{
    cout<<"\nEnter line number to set break point:\n";
    cin>>break_point;
    if(break_point==1 && ch==1)
    {
        cout<<"Break point cannot set at line number 1 !\n\n";
        break_point = INT_MAX;
    }
    else
    {
        if(break_point>lines || break_point<1)
        {
            cout<<"\nLine number does not exist !\n\n";
            break_point = INT_MAX;
        }
        else
        {
            cout<<"\nBreak point Set !\n\n";
        }
    }
}
void help()
{
    cout<<"\nHELP" << endl;
    cout<<"1. break b :- Set break point on given line number.\n";
    cout<<"2. run or r :- Run the complete program.\n";
    cout<<"3. step or s :- Run the program one instruction at a time.\n";
    cout<<"4. quit or q :- Quits debugger\n";
    cout<<"5. help or h :- Show all commands.\n\n";
}

void _run(int op)
{
    string s1, s2, s3, s4, o;
    int f=0;
    while(op)
    {
        if(op==1)
            f=1;
        if(line_number==break_point+1 || RAM[program_counter] == "HLT" || RAM[program_counter]=="EOF")
        {
            f=1;
            if(RAM[program_counter]=="HLT" || RAM[program_counter]=="EOF")
            {
                cout<<"\nProgram Executed!\n\n";
                display();
                ++dp;
            }
            else
            {
                cout<<"\nProgram executed till break point!\n\n";
                display();
            }
        }
        else
        {
            s1 = RAM[program_counter];
            if(s1.size()==2 || s1.size()==3 || s1.size()==4)
            {
                if(s1!="EOF" && s1!="HLT" && test0(s1))
                {
                    pc = HexToDecimal(program_counter);
                    pc = pc + inst_size[s1];
                    program_counter = DecimalToHex(pc);
                }
                else
                {
                    if(s1=="EOF" || s1=="HLT")
                    {
                        cout<<"\nProgram fully executed!\n";
                        display();
                        f=1;
                    }
                    else
                    {
                        cout<<"\nError at line number(s) "<<line_number<<"!\n\n";
                        f=1;
                        --line_number;
                    }
                }
            }
            else
            {
                if(s1.size()>4)
                {
                    s2 = s1.substr(0,indexOf(s1,' '));
                    o = s1.substr(indexOf(s1,' ')+1,s1.size());
                    switch(commands[s2])
                    {
                        case 1:
                                if(test1(o))
                                {
                                    if(s2=="ADD")
                                        ADD(o[0]);
                                    if(s2=="SUB")
                                        SUB(o[0]);
                                    if(s2=="INR")
                                        INR(o[0]);
                                    if(s2=="DCR")
                                        DCR(o[0]);
                                    if(s2=="CMP")
                                        CMP(o[0]);
                                    if(s2=="ADC")
                                        ADC(o[0]);
                                    if(s2=="SBB")
                                        SBB(o[0]);

                                    pc = HexToDecimal(program_counter);
                                    pc = pc + inst_size[s2];
                                    program_counter = DecimalToHex(pc);
                                }
                                else
                                {
                                    cout<<"\nError at line number " << line_number << "!\n\n";
                                    f=1;
                                    --line_number;
                                }
                                break;
                        case 2:
                                if(test2(o))
                                {
                                    if(s2=="LDA")
                                    {
                                        LDA(o);
                                        pc = HexToDecimal(program_counter);
                                        pc = pc + inst_size[s2];
                                        program_counter = DecimalToHex(pc);
                                    }
                                    if(s2=="STA")
                                    {
                                        memoryLocations.push_back(o);
                                        STA(o);
                                        pc = HexToDecimal(program_counter);
                                        pc = pc + inst_size[s2];
                                        program_counter = DecimalToHex(pc);
                                    }
                                    if(s2=="LHLD")
                                    {
                                        LHLD(o);
                                        pc = HexToDecimal(program_counter);
                                        pc = pc + inst_size[s2];
                                        program_counter = DecimalToHex(pc);
                                    }
                                    if(s2=="SHLD")
                                    {
                                        SHLD(o);
                                        pc = HexToDecimal(program_counter);
                                        pc = pc + inst_size[s2];
                                        program_counter = DecimalToHex(pc);
                                    }
                                    if(s2=="JMP")
                                        JMP(o);
                                    if(s2=="JC")
                                        JC(o);
                                    if(s2=="JNC")
                                        JNC(o);
                                    if(s2=="JZ")
                                        JZ(o);
                                    if(s2=="JNZ")
                                        JNZ(o);
                                }
                                else
                                {
                                    cout<<"\nError at line number "<< line_number<<"!\n\n";
                                    f=1;
                                    --line_number;
                                }
                                break;
                        case 3:
                                if(test3(o))
                                {
                                    if(s2=="ADI")
                                        ADI(o);
                                    if(s2=="SUI")
                                        SUI(o);
                                    if(s2=="ACI")
                                        ACI(o);
                                    if(s2=="SBI")
                                        SBI(o);

                                    pc = HexToDecimal(program_counter);
                                    pc = pc + inst_size[s2];
                                    program_counter = DecimalToHex(pc);
                                }
                                else
                                {
                                    cout<<"\nError at line number "<<line_number<<"!\n\n";
                                    --line_number;
                                    f=1;
                                }
                                break;
                        case 4:
                                if(test4(o))
                                {
                                    if(s2=="STAX")
                                        STAX(o[0]);
                                    if(s2=="INX")
                                        INX(o[0]);
                                    if(s2=="DCX")
                                        DCX(o[0]);
                                    if(s2=="PUSH")
                                        PUSH(o[0]);
                                    if(s2=="POP")
                                        POP(o[0]);
                                    pc = HexToDecimal(program_counter);
                                    pc = pc + inst_size[s2];
                                    program_counter = DecimalToHex(pc);
                                }
                                else
                                {
                                    cout<<"\nError at line number "<<line_number<<"!\n\n";
                                    f=1;
                                    --line_number;
                                }
                                break;
                        case 5:
                                if(test5(o))
                                {
                                    s3 = s1.substr(indexOf(s1,' ')+1,1);
                                    s4 = s1.substr(indexOf(s1,',')+1,1);
                                    if(s2=="MOV")
                                        MOV(s3[0],s4[0]);

                                    pc = HexToDecimal(program_counter);
                                    pc = pc + inst_size[s2];
                                    program_counter = DecimalToHex(pc);
                                }
                                else
                                {
                                    cout<<"\nError at line number "<<line_number<<"!\n\n";
                                    f=1;
                                    --line_number;
                                }
                                break;
                        case 6:
                                if(test6(o))
                                {
                                    s3 = s1.substr(indexOf(s1,' ')+1,1);
                                    s4 = s1.substr(indexOf(s1,',')+1,2);
                                    if(s2=="MVI")
                                        MVI(s3[0],s4);

                                    pc = HexToDecimal(program_counter);
                                    pc = pc + inst_size[s2];
                                    program_counter = DecimalToHex(pc);
                                }
                                else
                                {
                                    cout << "\nError at line number " << line_number << "!\n\n";
                                    f=1;
                                    --line_number;
                                }
                                break;
                        case 7:
                                if(test7(o))
                                {
                                    s3 = s1.substr(indexOf(s1,' ')+1,1);
                                    s4 = s1.substr(indexOf(s1,',')+1,4);
                                    if(s2=="LXI")
                                        LXI(s3[0],s4);

                                    pc = HexToDecimal(program_counter);
                                    pc = pc + inst_size[s2];
                                    program_counter = DecimalToHex(pc);
                                }
                                else
                                {
                                    cout<<"\nError at line number "<<line_number<<"!\n\n";
                                    f=1;
                                    --line_number;
                                }
                                break;
                        case 8:
                                if(test8(o))
                                {
                                    s3 = s1.substr(indexOf(s1,' ')+1,4);
                                    s4 = s1.substr(indexOf(s1,',')+1,2);
                                    if(s2=="SET")
                                    {
                                        SET(s3,s4);
                                        memoryLocations.push_back(s3);
                                    }

                                    pc = HexToDecimal(program_counter);
                                    pc = pc + inst_size[s2];
                                    program_counter = DecimalToHex(pc);
                                }
                                else
                                {
                                    cout << "\nError at line number " << line_number << "!\n\n";
                                    f=1;
                                    --line_number;
                                }
                    }
                }
                else
                {
                    cout << "\nInvalid instruction present!\n\n";
                    f=1;
                }
            }
            ++line_number;
        }
        if(f==1)
            break;
    }
}
void debugger(int file)
{
    string choice;
    set_instructions();
    reset_flags();
    reset_registers();
    program_counter = starting_address;
    cout<<"\nCommands:";
    cout<<"\nFor Break: b";
    cout<<"\nFor Run: r";
    cout<<"\nFor Step: s";
    cout<<"\nFor Quit: q";
    cout<<"\nFor Help: h\n\n";

    do{
        memregflag = 0;
        cout<<"Enter Command:\n";
        fflush(stdin);
        getline(cin, choice);
        switch(choice[0])
        {
            case 'B':
            case 'b':break_point_set(file);
                     break;
            case 'H':
            case 'h':help();
                     break;
            case 'R':
            case 'r':_run(2);
                     break;
            case 's':_run(1);
                     break;
            default:
                if(!(choice[0]=='q' || choice[0]=='Q')){
                    cout << "Oops!!! Wrong Input, Enter Again !\n\n";
                }
        }
    }while(!(choice[0]=='q' || choice[0]=='Q'));
}


void MOV(char operand1,char operand2)
{
	if(operand1!='M' && operand2!='M')
	{
		registers[operand1]=registers[operand2];
	}
	else
	{
		int address = registers['H']*256 + registers['L'];
		if(memory.find(DecimalToHex(address))==memory.end())
		{
			memory[DecimalToHex(address)]=0;
		}
		if(operand1=='M')
		{
			memory[DecimalToHex(address)]=registers[operand2];
		}
		else
		{
			registers[operand1]=memory[DecimalToHex(address)];
		}
	}
}

void MVI(char operand,string val)
{
	registers[operand]=HexToDecimal(val);
}

void LDA(string address)
{
	if(memory.find(address)==memory.end())
			memory[address]=0;
	registers['A']=memory[address];
}

void STA(string address)
{
	if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
	memory[address]=registers['A'];
}

void LHLD(string address)
{
	int add=HexToDecimal(address);
	if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
	if(memory.find(DecimalToHex(add+1))==memory.end())
		{
			memory[DecimalToHex(add+1)]=0;
		}

	registers['H']=memory[address];
	registers['L']=memory[DecimalToHex(add+1)];
}

void SHLD(string address)
{
	int add=HexToDecimal(address);
	if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
	if(memory.find(DecimalToHex(add+1))==memory.end())
		{
			memory[DecimalToHex(add+1)]=0;
		}
	memory[address]=registers['L'];
	memory[DecimalToHex(add+1)]=registers['H'];
}

void STAX(char operand)
{
	string hex;
	int dec;
	switch(operand)
    {
        case 'B':
        hex=DecimalToHex(registers['B'])+DecimalToHex(registers['C']);
        dec=HexToDecimal(hex);
        if(memory.find(hex)==memory.end())
        {
            memory[hex]=0;
        }
        memory[hex]=registers['A'];
        break;
        case 'D':
        hex=DecimalToHex(registers['D'])+DecimalToHex(registers['E']);
        dec=HexToDecimal(hex);
        if(memory.find(hex)==memory.end())
        {
            memory[hex]=0;
        }
        memory[hex]=registers['A'];
        break;
        case 'H':
        hex=DecimalToHex(registers['H'])+DecimalToHex(registers['L']);
        dec=HexToDecimal(hex);
        if(memory.find(hex)==memory.end())
        {
            memory[hex]=0;
        }
        memory[hex]=registers['A'];
        break;
    }
}

void XCHG()
{
	int a;
	a=registers['D'];
	registers['D']=registers['H'];
	registers['H']=a;
	a=registers['E'];
	registers['E']=registers['L'];
	registers['L']=a;
}

void SPHL()
{
	if(memory.find(DecimalToHex(sp-1))==memory.end())
	{
		memory[DecimalToHex(sp-1)]=0;
	}
	if(memory.find(DecimalToHex(sp-2))==memory.end())
	{
		memory[DecimalToHex(sp-2)]=0;
	}
	memory[DecimalToHex(sp-1)]=registers['H'];
	memory[DecimalToHex(sp-2)]=registers['L'];
	sp=sp-2;
}

void XTHL()
{

	if(memory.find(DecimalToHex(sp-1))==memory.end())
	{
		memory[DecimalToHex(sp-1)]=0;
	}
	if(memory.find(DecimalToHex(sp-2))==memory.end())
	{
		memory[DecimalToHex(sp-1)]=0;
	}
	registers['L']=memory[DecimalToHex(sp)];
	registers['H']=memory[DecimalToHex(sp+1)];
}

void PUSH(char operand)
{
	if(memory.find(DecimalToHex(sp-1))==memory.end())
	{
		memory[DecimalToHex(sp-1)]=0;
	}
	if(memory.find(DecimalToHex(sp-2))==memory.end())
	{
		memory[DecimalToHex(sp-2)]=0;
	}
	switch(operand)
	{
		case 'B':
			memory[DecimalToHex(sp-1)]=registers['B'];
			memory[DecimalToHex(sp-2)]=registers['C'];
			sp=sp-2;
			break;
		case 'D':
			memory[DecimalToHex(sp-1)]=registers['D'];
			memory[DecimalToHex(sp-2)]=registers['E'];
			sp=sp-2;
			break;
		case 'H':
			memory[DecimalToHex(sp-1)]=registers['H'];
			memory[DecimalToHex(sp-1)]=registers['L'];
			sp=sp-2;
	}
}

void POP(char operand)
{
	if(memory.find(DecimalToHex(sp-1))==memory.end())
	{
		memory[DecimalToHex(sp-1)]=0;
	}
	if(memory.find(DecimalToHex(sp-2))==memory.end())
	{
		memory[DecimalToHex(sp-2)]=0;
	}
	switch(operand)
	{
		case 'B':
			registers['C']=memory[DecimalToHex(sp)];
			registers['B']=memory[DecimalToHex(sp+1)];
			sp=sp+2;
			break;
		case 'D':
			registers['E']=memory[DecimalToHex(sp)];
			registers['D']=memory[DecimalToHex(sp+1)];
			sp=sp+2;
			break;
		case 'H':
			registers['L']=memory[DecimalToHex(sp)];
			registers['H']=memory[DecimalToHex(sp+1)];
			sp=sp+2;
			break;
	}
}

void ADD(char operand)
{
	if(operand=='M'){
        string s = DecimalToHex(registers['L']);
		string address=DecimalToHex(registers['H'])+((s.size()==1)?("0"+s):s);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']+=memory[address];
	}
	else
		registers['A']+=registers[operand];
	test_carry();
	test_sign();
	test_zero();
	test_parity();
	test_auxilary();
}

void ADI(string val)
{
	registers['A']+=HexToDecimal(val);
	test_carry();
	test_sign();
	test_zero();
	test_parity();
	test_auxilary();
}

int ADC(char operand)
{
	if(operand=='M'){
		string s = DecimalToHex(registers['L']);
		string address=DecimalToHex(registers['H'])+((s.size()==1)?("0"+s):s);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']+=memory[address]+flag['c'];
	}
	else
		registers['A']+=registers[operand]+flag['c'];
	test_carry();
	test_sign();
	test_zero();
	test_parity();
	test_auxilary();
}

int ACI(string val)
{
	registers['A']+=HexToDecimal(val)+flag['c'];
	test_carry();
	test_sign();
	test_zero();
	test_parity();
	test_auxilary();
}

void SUB(char operand)
{
	if(operand=='M'){
		string s = DecimalToHex(registers['L']);
		string address=DecimalToHex(registers['H'])+((s.size()==1)?("0"+s):s);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']-=memory[address];
	}
	else
		registers['A']-=registers[operand];
	test_carry();
	test_sign();
	test_zero();
	test_parity();
	test_auxilary();
}

void SUI(string val)
{
	registers['A']-=HexToDecimal(val);
	test_carry();
	test_sign();
	test_zero();
	test_parity();
	test_auxilary();
}

void SBB(char operand)
{
	if(operand=='M')
    {
		string s = DecimalToHex(registers['L']);
		string address=DecimalToHex(registers['H'])+((s.size()==1)?("0"+s):s);
		if(memory.find(address)==memory.end())
		{
			memory[address]=0;
		}
		registers['A']-=memory[address]-flag['c'];
	}
	else
		registers['A']-=(registers[operand]-flag['c']);
	test_carry();
	test_sign();
	test_zero();
	test_parity();
	test_auxilary();
}

void SBI(string val)
{
	registers['A']-=HexToDecimal(val)-flag['c'];
	test_carry();
	test_sign();
	test_zero();
	test_parity();
	test_auxilary();
}

void LXI(char operand,string val)
{
	string val_L;
	val_L = val.substr(2,2);
	string val_H;
	val_H = val.substr(0,2);
	registers['H']=HexToDecimal(val_H);
	registers['L']=HexToDecimal(val_L);
}

void INR(char operand)
{
	registers[operand]++;
	if(registers[operand]>255)
    {
		registers[operand]%=256;
	}
	test_sign(operand);
	test_zero(operand);
	test_parity(operand);
	test_auxilary(operand);
}

void INX(char operand)
{
	if(operand=='B')
    {
		if(registers['C']==127)
		{
			registers['C']=0;
			if(registers['B']==127)
				registers['B']=0;
		}
		else
			registers['C']++;
	}
	else if(operand=='D')
	{
		if(registers['E']==127)
		{
			registers['E']=0;
			if(registers['D']==127)
				registers['D']=0;
		}
		else
			registers['E']++;
	}
	else if(operand=='H')
	{
		if(registers['L']==127)
		{
			registers['L']=0;
			if(registers['H']==127)
				registers['H']=0;
		}
		else
			registers['L']++;
	}
}

void DCR(char operand)
{
	registers[operand]--;
	if(registers[operand]<0)
    {
		registers[operand]+=256;
	}
	test_sign(operand);
	test_zero(operand);
	test_parity(operand);
	test_auxilary(operand);
}

void DCX(char operand)
{
	if(operand=='B')
    {
		if(registers['C']==-128)
		{
			registers['C']=0;
			if(registers['B']==-128)
				registers['B']=0;
		}
		else
			registers['C']--;
	}
	else if(operand=='D')
	{
		if(registers['E']==-128)
		{
			registers['E']=0;
			if(registers['D']==-128)
				registers['D']=0;
		}
		else
			registers['E']--;
	}
	else if(operand=='H')
	{
		if(registers['L']==-128)
		{
			registers['L']=0;
			if(registers['H']==-128)
				registers['H']=0;
		}
		else
			registers['L']--;
	}
}

void JMP(string address)
{
	program_counter=address;
	pc = HexToDecimal(program_counter);
}

void JC(string address)
{
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['c']==1){
		program_counter=address;
		pc = HexToDecimal(program_counter);
	}
	else {
		pc += 3;
		program_counter = DecimalToHex(pc);
	}
}

void JNC(string address)
{
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['c']==0)
    {
		program_counter=address;
		pc = HexToDecimal(program_counter);
	}
	else
        {
		pc += 3;
		program_counter = DecimalToHex(pc);
	}
}

void JZ(string address)
{
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['z']==1)
    {
		program_counter=address;
		pc = HexToDecimal(program_counter);
	}
	else
	{
		pc += 3;
		program_counter = DecimalToHex(pc);
	}
}

void JNZ(string address)
{
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['z']==0)
    {
		program_counter=address;
		pc = HexToDecimal(program_counter);
	}
	else
	{
		pc += 3;
		program_counter = DecimalToHex(pc);
	}
}

void JP(string address)
{
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['s']==0)
    {
		program_counter=address;
		pc = HexToDecimal(program_counter);
	}
	else
	{
		pc += 3;
		program_counter = DecimalToHex(pc);
	}
}

void JM(string address)
{
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['s']==1)
    {
		program_counter=address;
		pc = HexToDecimal(program_counter);
	}
	else
    {
		pc += 3;
		program_counter = DecimalToHex(pc);
	}
}

void JPE(string address)
{
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['p']==1)
    {
		program_counter=address;
		pc = HexToDecimal(program_counter);
	}
	else
	{
		pc += 3;
		program_counter = DecimalToHex(pc);
	}
}

void JPO(string address)
{
	transform(address.begin(), address.end(), address.begin(), ::tolower);
	if(flag['p']==0)
    {
		program_counter=address;
		pc = HexToDecimal(program_counter);
	}
	else
	{
		pc += 3;
		program_counter = DecimalToHex(pc);
	}
}

void CMA()
{
	registers['A']=255-registers['A'];
}

void CMP(char operand)
{
        if(operand=='M')
        {
            string address = DecimalToHex(registers['H']*256+registers['L']);
            if(registers['A']>memory[address])//if memory is used
            {
                flag['c']=0;
                flag['z']=0;
            }
            else
            {
                if(registers['A']==memory[address])
                    flag['z']=1;
                else
                    flag['c']=1;
            }
        }
        else
        {
			if(registers['A']>registers[operand])
			{
				flag['c']=0;
				flag['z']=0;
			}
			else
            {
                if(registers['A']==registers[operand])
                    flag['z']=1;
                else
                    flag['c']=1;
            }
        }
}
void SET(string mem,string val)
{
	memory[mem]=HexToDecimal(val);
}

int main()
{
    int pc;
    char choice, f, c;
    dp = 0;
    set_instructions_size();
    string line="";
    cout << "<<<-------\t8085 Microprocessor Emulator\t------>>>\n\n";
    cout << "\tEnter:\n\t1 to write outfile \n\t2 to Exit\n\n";
    do
    {
        cout<<"\tEnter : ";
        cin>>choice;

        if(!(choice=='1' || choice=='2'))
            cout<<"\tInvalid Input. Try Again !\n";

    }while(!(choice=='1' || choice=='2'));

        if(choice=='2')
        {
            cout<<"\n\tSuccessfully Exited!!\n";
            return 0;
        }

    if(choice=='1')
    {
        remove("outfile.txt");
        ofstream outfile;
        outfile.open("outfile.txt",ios::out);
        fflush(stdin);
            cout<<"\tEnter starting address between 0000 to FFFF:\n\t";
            getline(cin,starting_address);
        outfile<<starting_address<<endl;
        program_counter = starting_address;
        do
        {
            ++lines;
            cout << "\t" << program_counter << " : ";
            getline(cin,line);
            if(!test0(line))
            {
                if(inst_size[line.substr(0,indexOf(line,' '))] == 0)
                {
                    --lines;
                }
            }
            RAM[program_counter] = line;
            outfile<<line<<endl;
            pc = HexToDecimal(program_counter);
            if(line.size()==3 || line.size()==4 || line.size()==2)
            {
                pc += inst_size[line];
            }
            else
            {
                pc += inst_size[line.substr(0,indexOf(line,' '))];
            }
            program_counter = DecimalToHex(pc);
        }while(line!="HLT" && line!="EOF");

        ++lines;
        outfile.close();
    }

    do
    {
        cout<<"\nDebugger :\n  1) ON\n  2) OFF\n\nEnter:\n";
        cin>>f;
        if(f!='1' && f!='2')
        {
            cout<<"\nOops!!!\nWrong Choice. Try Again!\n";
        }
    }while(f!='1' && f!='2');

    if(f=='2')
    {
        set_instructions();
        reset_flags();
        reset_registers();
        program_counter = starting_address;
        _run(2);
        return 0;
    }

    debugger(int(choice-'0'));
    return 0;
}
