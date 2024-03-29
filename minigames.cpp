#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
using namespace std;

void hangman();
void numberguess();

void header()
{
	cout << "\n===================================================================================================================================================\n";
    cout << "                                                   R 4 F 4 Y 0 4   M I N I G A M E S\n";
    cout << "===================================================================================================================================================\n\n";
}

int main()
{
	
	
	header();
	cout<<endl<<endl;
	
	int game=1;
	while(game==1)
	{
	cout<<"Press 1 to play Hangman or 2 to play Guess the number"<<endl;
	
	int choice;cin>>choice;
	while (choice!=1&&choice!=2)
	{
		cout<<"invalid choice. either enter 1 or 2"<<endl;
		cin>>choice;
	}
	if (choice==1)
	{
		hangman();
	}
	else if (choice==2)
	{
		numberguess(); 
	}
	cout<<endl<<endl<<endl<<"Game Over.\n Press 1 to play again or any other key to quit the program"<<endl;
	cin>>game;
	
	system("cls");

	}
		return 0;
}


















string randomcountry();
void welcome();		void credits();

int letters();
void check(string,char,int[]);
void correct(int[],char,string&);
int random();

const int maxchar = 26;  

char guessed[maxchar] = {'\0'};
int guessCount = 0;


void stage1();
void stage2();
void stage3();
void stage4();
void stage5();
void stage6();
void stage7();
void stage8();

int countryindex=random();         
    

int attempts=8;

void hangman()
{
  
  int occur[3]={0}; 
  char x; 
  string country;				country=randomcountry(); 
  string guessed; 
   
  
  
  welcome();					 credits();
  
  cout<<"Press enter to begin"<<endl<<endl;
  cin.get();

  int length=letters();
  string guessedword(length,'_');
  //cout<<guessedword; to check array (ignore developer work)



  cout<<"The computer has selected a random country."<<endl<<"The country has "<<letters()<<" letters."<<endl<<endl<<"You have 8 tries."<<endl;
 // cout<<country; for developers help

  while(attempts!=0&&guessedword!=country) 
  {
    cout<<endl<<"Make your guess"<<endl;
    cin>>x; 
    
    x=tolower(x); 


       bool alreadyGuessed = false; 
          for (int i = 0; i < guessCount; ++i)
      {
            if (guessed[i] == x) 
        {
                alreadyGuessed = true; 
                break; 
            }
        }

    if (alreadyGuessed==true)  
      {
            cout << "You've already guessed '" << x << "'. Try a different letter." << endl;
            continue; 
        }

       guessed[guessCount] = x; 
        ++guessCount;

                  system("cls");
                  welcome(); 

    check(country,x,occur);
    correct(occur,x,guessedword);
  //	cout<<occur[0]<<occur[1]<<occur[2]<<endl; erase later for developers help
    cout<<guessedword;



  }
  if (attempts==0) 
  {
    cout<<endl<<"Oh no . Youre out of attempts"<<endl;
    cout<<endl<<"It was "<<country;
  }
  else if(guessedword==country) 
  {
    cout<<endl<<"Congratulations! You guessed the country correctly.";	
    cout<<endl<<"It was "<<country;
  }
  
  attempts =8;

}

string countries[30] = {
    "greenland", "canada", "mexico", "china", "india", "australia", "japan", "norway", "colombia",
    "argentina", "france", "germany", "italy", "spain", "england", "brazil", "russia", 
    "egypt", "palestine", "qatar", "iran", "turkey", "pakistan",
    "belgium", "sweden", "greece", "switzerland", "portugal", "nepal", "ireland",
};

int random()
{
  srand(time(0));
  return rand() % 30;
}

string randomcountry()
{
  return  countries[countryindex];
}
//count the letters the countries
int letters()
{
  string x;
  x=randomcountry();
  int count=0;

  while(x[count]!='\0')
    count++;

  return count;
}

void check(string x,char y,int occur[])
{
  int count=0;
  bool occurance=false;

  for (int i = 0; i < 3; ++i) 
    {
        occur[i] = 0;
    }

  for (int i=0;i<letters();i++) 

  {
      if(x[i]==y)
    {
          occur[count]= i; 
          ++count; 
      occurance=true;	
    }

    }

  if(occurance==false)
    {
  	  occur[0]=16; 
	}

}

void correct(int guessedIndices[], char a,string& guessedword)
{
    int currentIndex = 0;

  if(guessedIndices[0]==16)
  {
    attempts--;
    cout<<"Invalid choice. Attempts Left : "<<attempts<<endl;

    switch (attempts)
    {
      
      case 7:
        stage1(); break;
      case 6:
        stage2(); break;
      case 5:
        stage3(); break;
      case 4:
        stage4(); break;
      case 3:
        stage5(); break;
      case 2:
        stage6(); break;
      case 1:
        stage7(); break;
      case 0:
        stage8(); break;
    }

  }
  else
  {
    cout<<endl<<"Correct Choice                        (Hint:The country has "<<letters()<<" letters)"<<endl;
  }

    for (int i = 0; i < letters(); ++i)
    {
        if (currentIndex < 3 && i == guessedIndices[currentIndex])
        {
            guessedword[i]=a;
            ++currentIndex;
        }

    }

    cout << endl;
}


void welcome() 
{
    cout << "  _    _                                          \n";
    cout << " | |  | |                                         \n";
    cout << " | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __  \n";
    cout << " |  __  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n";
    cout << " | |  | | (_| | | | | (_| | | | | | | (_| | | | |\n";
    cout << " |_|  |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n";
    cout << "                     __/ |                         \n";
    cout << "                    |___/                          \n";

}

void credits()
 {
    cout << "\n=================================================\n";
    cout << "               C R E D I T S\n";
    cout << "=================================================\n\n";


    cout << "           Rafay Akram 2023491\n";
 

    cout<<endl<<endl;

}

void stage1() {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
}

void stage2() {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"  |   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
}
void stage3() {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"  |   | \n";
    cout<<" /    | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
}
void stage4() {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"  |   | \n";
    cout<<" /|   | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
}
void stage5() {
   cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"  |   | \n";
    cout<<" /|\\  | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
}
void stage6() {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"  |   | \n";
    cout<<" /|\\  | \n";
    cout<<"  |   | \n";
    cout<<" ========= \n";
}
void stage7() {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"  |   | \n";
    cout<<" /|\\  | \n";
    cout<<"  |   | \n";
    cout<<" /    | \n";
    cout<<" ========= \n";
}
void stage8() {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"  |   | \n";
    cout<<" /|\\  | \n";
    cout<<"  |   | \n";
    cout<<" / \\  | \n";
    cout<<" ========= \n";
}




void numberguess()
{
	srand(time(0)); 
	
	int x;
	
	x=rand()%1000; 
	
	cout<<"The computer has generated a random number (from 1 to 1000). Please try to guess it. Dont worry you will get all the help you need";
	
	cout<<endl<<"Please make your guess (From 1 to 1000)"<<endl;
	int guess;
	
	cin>>guess;
	
	while(guess<1||guess>1000)
	{
		cout<<"Invalid choice. The number should be between 0 and 1000 please try again"<<endl;
		cin>>guess;
	}
	

		
	//to test cout<<x<<endl;
	
	while(guess!=x) 
	{
		if(guess>x) 
		{
			cout<<"Try lower"<<endl;
			cin>>guess;
		}
		if(guess<x) 
		{
			cout<<"Try higher"<<endl;
			cin>>guess;
		}
		
	}
	cout<<"Yayyyy you were right. "<<endl; 
	
}






