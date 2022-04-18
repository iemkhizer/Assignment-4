#include<iostream>
#include<Windows.h>           //clear screen
#include<cstring>
#include<string>
#include<conio.h>
#include<cstdlib>
#include<time.h>
#include<fstream>
using namespace std;

void display()
{
	cout << "** Welcome to the Word Search World ***" << endl;
	cout << "Guess the hidden word & get 1 score ;) " << endl;
}

int Gamefunction()
{
	string array[10];
	ifstream file("words1.txt");
	if (file.is_open())
	{

		for (int i = 0; i < 10; ++i)
		{
			file >> array[i];
		}
		
	}
	else
	cout<<"no file found";
	int rows,cols;
	cout<<"Enter NUmber of Rows";
	cin>>rows;
	cout<<"Enter Number of cols:";
	cin>>cols;	
	char matrix[50][50];
	matrix[rows][cols];
	int r;
	char c;
	srand(time(0));
	//generating random alphabets of puzzle
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			r = rand() %26;
			c = 'a' + r;
			matrix[i][j] = c;
		}

	}
	int terms;
	cout<<"Enter Number of words you want to Enter:";
	cin>>terms;
	//print the puzzle matrix
	cout << "*** Puzzle ***" << endl;
	
	//print words in array in puzzle
	int path[10]={0};
	int count=0;
	
	int index =rand()%10;
	string output = array[index];
	
	while(rows<array[index].length() || array[index].length()>cols)
	{
		index=rand()%10;	
	}
	cout << array[index].length() << endl;
	while(count==0)
	{
		count=0;
		int row = rand() % 10;
		int col = rand() % 10;
		int gamble = rand()%3;
	if(gamble==0)
	{
		if ( col+array[index].length()<cols)//horizontally(left to right)
		{
		//horizontally print(Up to Down)
			path[0]=row+col*10;	
		for (int i = 0; array[index][i] != '\0'; i++,col++)
		{
			matrix[row][col] = array[index][i];
			
		}
		path[1]=row+col*10;
		count++;
		}
	//horizontally( right to left )
	else if ( col-array[index].length()>0 )
	{
		path[0]=row+col*10;
		for (int i = 0; array[index][i] != '\0' && row!=10 && col!=10; i++, col--)
		{
			{
				matrix[row][col] = array[index][i];
			}
		}
		path[1]=row+col*10;
		count++;
	}
	
	}
	if(gamble==1)
	{
		
	//diagonal (top left to right bottom)
	if (row+array[index].length()<rows && col+array[index].length()<cols)
	{
		path[0]=row+col*10;
		for (int i = 0; array[index][i] != '\0'; i++, row++, col++)
		{
			matrix[row][col] = array[index][i];
		}
		path[1]=row+col*10;
		count++;
	}
	//diagonal (top right to  left bottom)
	else if (  row+array[index].length()<rows && col-array[index].length()>0) 
	{
		
		path[0]=row+col*10;
		for (int i = 0; array[index][i] != '\0'; i++, row++,col--)
		{
			matrix[row][col] = array[index][i];
		}
		path[1]=row+col*10;
		count++;
	}
	//diagnol (bottom left to top right)
	else if (  row-array[index].length()>0 && col+array[index].length()<cols) 
	{
		path[0]=row+col*10;
		for (int i = 0; array[index][i] != '\0'; i++, row--,col++)
		{
			matrix[row][col] = array[index][i];
		}
		path[1]=row+col*10;
		count++;
	}
	//diagnol (bottom right to top left)
	else if (row-array[index].length()>0 && col-array[index].length()>0) 
	{
		path[0]=row+col*10;
		for (int i = 0; array[index][i] != '\0'; i++, row--,col--)
		{
			matrix[row][col] = array[index][i];
		}
		path[1]=row+col*10;
	count++;
	}
	
	}
	if(gamble==2)
	{
	//vertically print(  top to bottom)
	if (row+array[index].length()<rows)
	{		
	path[0]=row+col*10;
		for (int i = 0; array[index][i] != '\0'; i++,row++)
		{
			matrix[row][col] = array[index][i];
		}
		path[1]=row+col*10;
		count++;
	}
	
	//vertically print( bottom to top)
	else if(row-array[index].length()>1)
	{	
	path[0]=row+col*10;
        for (int i = 0; array[index][i] != '\0'; i++, row--)
		{
			matrix[row][col] = array[index][i];
		}
		path[1]=row+col*10;
		count++;
	}

	}
	}
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
			Sleep(100);
		}
		cout << endl;
	}
	string guess;
	char hint;
	while(terms>0)
	{
	
	a:
	cout << "Press 1 for direct guess: " << endl;
	cout << "Press 2 for hint: " << endl;	
	cin >> hint;

	if (hint == '1')
	{
		cout << "Enter you guess: ";
		cin >> guess;
		cout << endl;
	}
	else if (hint == '2')
	{
		cout << "The size of the word is: " << output.length() << endl;
		cout << "Enter you guess: ";
		cin >> guess;
		cout << endl;
	}
	else
	{
		cout << "Invalid Input!"<<endl;
		goto a;
	}
	if (output == guess)
	{
		cout << '{'<<path[0]/10<<','<<path[0]%10<<'}'<<" "<< '{'<<path[1]/10<<','<<path[1]%10<<'}';
	}
	else
	{
		cout << "Not available" << endl;
	}
	terms--;
	}
return 0;
}


int main()
{
	string name;
	cout << "Enter your name:  ";
	getline (cin, name);
	cout << endl;

	int score = 0;
	char input;
	do
	{
		
		
		display();
		score = score + Gamefunction();
		cout << "Would you like to play this game again?  y/n  : ";
		cin >> input;
		system("cls");
	
	} while (input != 'n');
		cout << name << " Your final score is: " << score;
		cout << endl;
}
