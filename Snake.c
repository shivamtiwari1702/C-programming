#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int height=30,width=70,fruitX,fruitY,x,y,gameOver=0,myScore=0,tailX[100],tailY[100],p=1,N;
char keyPressed='a',*name="SHIVAM-TIWARI-CREATION";

void init();
void show();
void snakeMove();
void scores();

void init(){
	x=width/2;
	y=height/2;
	tailX[0]=x;
	tailY[0]=y;
	fruitX=rand()%(width-1);
	fruitY=rand()%(height-1);
}

void show(){
	int i,j,k,t=0;
	N=strlen(name);
	
	printf("\n\n");	
	for(j=0;j<height;j++){
		printf("\t\t*");
		for(i=0;i<width;i++){
			t=0;
			if(j==0 || j==height-1)
				printf("*");
						
			else if(i==fruitX && j==fruitY)
				printf("F");
						
		    else if(i==tailX[0] && j==tailY[0])
				printf("%c",name[0]);
				
			else{
				t=0;
				for(k=1;k<=myScore;k++)
					if(tailX[k]==i && tailY[k]==j){
						printf("%c",name[p]);
						p=(++p)%N;
						t=1;
					}
				if(t!=1)
					printf(" ");
			}
		}		
		printf("*\n");
	}
	printf("\n\nYour Current Score is :- %d",myScore);
}

void snakeMoveTrack(){
	int i;
		
	if(kbhit())
		keyPressed=getch();
	switch(keyPressed){
		case 'a':
			x--;
			break;
			
		case 'd':
			x++;
			break;
				
		case 's':
			y++;
			break;
				
		case 'w':
			y--;
			break;
			
		default:
			gameOver=1;
	}
		
		for(i=myScore;i>0;i--){
			tailX[i]=tailX[i-1];
			tailY[i]=tailY[i-1];
		}
		
		tailX[0]=x;
		tailY[0]=y;
		
		if(x==width-1 || x<0 ||y==0 || y==height)
			gameOver=1;
		for(i=1;i<=myScore && !gameOver;i++)
			if(tailX[0]==tailX[i] && tailY[0]==tailY[i])
				gameOver=1;
	
}

void scores(){
	if(x==fruitX && y==fruitY){
		myScore+=1;
		fruitX=rand()%(width-1);
		fruitY=rand()%(height-1);
		tailX[myScore]=x;
		tailY[myScore]=y;
	}
}


void main(){
	init();
	while(!gameOver){
		system("cls");
		show();
		snakeMoveTrack();
		scores();
	}
	getch();
}