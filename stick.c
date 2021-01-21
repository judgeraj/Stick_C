/*
PROGRAMMING ASSIGNMENT 2
Rajpreet Judge
10/16/2019 17:16
Nick Macias
CSE 224

This program is a stick picking like similiar to Program assignment 1 but instead of choosing who goes first, in this case user always goes first.
Player can give either command line argument or arguments in game. 

*/

#include<stdio.h>
#include<string.h>

int start(int argc, char** argv);
int parse(char *);
int pick(int);

int main(int argc, char** argv) {

  int  i, j, ret, sticks, retval, n;
  int turn, play = 1, comp = 0;
  char numsticks[120], picksticks[100];
  int  stickspicked, minusstick, compsticks;


  ret = start(argc, argv);

//Checks return value from start function to determine if game should quit due to incorrect input

  if((ret==-2)||(ret==-3)) {
    printf("Clearly haven't passed english GAME FORFEITED\n");
    return 0;
  }
  else if(argc==2) {
    printf("We will play with %d sticks\n", ret);
  }
  sticks = ret;

//if no command line argument game prompts user to enter number of sticks else this is skipped

  if(ret==-1) {
    char tmp[120];
    printf("Enter Number of sticks you would like to play with: ");
    fgets(numsticks,120,stdin);
    retval = sscanf(numsticks,"%d%s", &sticks,tmp);
      if(retval!=1) {
        printf("Clearly cannot read or care to read instructions\n");
        return 0;
      }
      if(sticks<10) {
        printf("Clearly cannot read or care to read instructions\n");   
        return 0;
      }
      if(retval==2) {
        printf("Clearly cannot read or care to read instructions\n");
        return 0;
      }

//welcomes user and prints number of sticks aswell as actual sticks themselves

     printf("\n\nWELCOME TO THE STICK GAME! If you haven't passed the amount of sticks already\nYou will be prompted to enter the amount of stickaroos now. (10 or greater sticks) PLEASE READ!\n");
     printf("~~~~~~~~USER ALWAYS GOES FIRST~~~~~~~~\n\n\n");

     printf("We will be playing with %d sticks\n", sticks);      
   }
   for(i=0;i<sticks;i++) {
     printf("|");
   }
   printf("<%d>\n", sticks);

//start of the game itself
//rest of this code will call functions to get valid input/confirm the user input to be valid
//will subtract the user entered sticked from total pile and when sticks are 0 will declare who wins

  while(sticks > 0) { 
    turn = 1;
    if(turn == 1) {
      printf("Enter how many sticks you wish to take: ");
      retval = parse(fgets(picksticks,100,stdin));
      while(retval == -1) {
        printf("Of course the pleb cannot follow instructions reenter sticks : ");
        retval = parse(fgets(picksticks,100,stdin));
      }
    sticks = sticks - retval;
    for(i=0;i<sticks;i++){
      printf("|");  
    }
    printf("<%d>\n",sticks);
    turn = 0;
    if(sticks <= 0) {
      printf("USER WON?!?!?! Surprisingly considering rogue is the only game user is a good at. Maybe user is not a pleb\n");
      return 0;
    }
    }
    if(turn == 0) {
      n = 0;  
      n = pick(sticks);
      sticks = sticks - n;
      printf("Computer takes %d stick/sticks\n", n);
      for(i=0;i<sticks;i++) {
        printf("|");
      }
      printf("<%d>\n",sticks);
      turn = 1;
      if(sticks <= 0) {
        printf("COMP WON! Please go back to rogue user lacking brain power. \n");
        return 0;
      }
    }
  }
}


//~~~~~~~~Checks command line arguments for valid int~~~~~~~~~

int start(int argc, char* argv[]) {

  int i;
  char tmp[120];

  if(argc!=2) {
    return -1;
  }
  if(argc==2) {
    int result = sscanf(argv[1],"%d%s",&i,tmp);
    if((result==1) && (i < 10)) {
      return -3;
    }
    else if(result==0)
      return -2;
    else if(result==2) 
      return -3;
  }
  return i;
}


//~~~~~~~~Checks for user input to be within 1-3 and valid inputs~~~~~~~~~

int parse(char* num) {

  int  y = 0, result = 0;
  char extra[120];

  result = sscanf(num, "%d%s",&y,extra);
  if (result == 1){
    if (y == 1)
      return 1;

    else if (y == 2)
      return 2;

    else if (y == 3)
      return 3;
    }
  if(result == 2)
    return -1;
  return -1;
}
//~~~~~~~~~~~~COMPUTER LOGIC TO PICK THE STICKS~~~~~~~~~~~~~~~~~~

int pick (int n) {

  int remain = 0;

  remain = n%4;

  if(remain == 0)
    return (1);


  return (remain);
}
                                                                                                                                                                                                           
                                                                                                                                                                                                           
       
