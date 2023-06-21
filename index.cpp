#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
using namespace std;

//initailly both user and computer have zero score
static int userScore = 0; 
static int computerScore = 0;
static int machine;
static char user;
char properInput()//returns input given by user
 {
   char c;
   cin>>c;
   if(c>='A'&&c<='Z')
   c = c - 'A' + 'a';//converting the uppercase into lowercase
   return c;
 }
char computerChoice()//gives us  a random choice for the computer for every round
 {
   srand(time(0));//this ensures that random numbers are generated according to the given time
   machine = rand()%3;//this ensures that there are only three possible values: 0,1 and 2
  if(machine==0)//means computer played rock
  return 'r';
  else if(machine==1)//means computer played paper
  return 'p';
  else return 's';//means computer played scissors
 }
void userChoice()//takes input the choice of the user for every round
 {
  cout<<"Input your choice:";
  user=properInput();
  if(user!= 'r' && user!= 'p' && user!='s'){
    cout<<"Invalid choice,re-input your choice:"<<endl;
    user=properInput();
  }
 }
void printRules()//prints the rules of the game
 {
  cout<<"Rock can beat scissors, paper can beat rock and scissors can beat paper"<<endl;
  cout<<"Input r for rock,p for paper and s for scissors"<<endl;
 }
void game(int currentRound,int rounds)//recursive function to execute the game for number of rounds given by user
 {
  if(currentRound==rounds)return;
  userChoice();
  char computer = computerChoice();
  if(computer=='r')
  cout<<"Machine played rock"<<endl;
  else if(computer=='p')
  cout<<"Machine played paper."<<endl;
  else 
  cout<<"Machine played scissors."<<endl;
  if(user==computer)
  {
    cout<<"The round is a draw."<<endl;
  }
  else if((user=='r' && computer=='s') || (user=='p' && computer=='r') || (user=='s' && computer=='p'))
  {
    cout<<"You win this round."<<endl;
    userScore++;
  }
  else
  {
    cout<<"You lose this round."<<endl;
    computerScore++;
  }
  game(++currentRound,rounds);//starting the next round
 }
void result()//prints the final result of all the rounds
{
  cout<<"You scored "<<userScore<<" and the system scored "<<computerScore<<endl;
  if(userScore==computerScore)
  cout<<"It is a draw."<<endl;
  else if(userScore>computerScore)
  cout<<"Congrats!! You won"<<endl;
  else cout<<"You lost,Better luck next time!!"<<endl;
}
int main()
{
    int rounds;
    cout<<"Enter the number of rounds"<<endl;
    cin>>rounds;

  cout<<"There will be "<<rounds<<" round(s)"<<endl;
  printRules();
  game(0,rounds);
  result();
  return 0;
}