#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int enemyY[3];
int enemyX[3];
int enemyFlag[3];
char car[4][4] = { ' ','^','^',' ',
                    '^','^','^','^',
                    ' ','^','^',' ',
                    '^','^','^','^' };
char car1[4][4] = { ' ','+','+',' ',
                    '+','+','+','+',
                    ' ','+','+',' ',
                    '+','+','+','+' };
char car2[4][4] = { ' ','x','x',' ',
                    'x','x','x','x',
                    ' ','x','x',' ',
                    'x','x','x','x' };
char car3[4][4] = { ' ','o','o',' ',
                    'o','o','o','o',
                    ' ','o','o',' ',
                    'o','o','o','o' };

int carPos = WIN_WIDTH/2;
int score = 0;

void gotoxy(int x, int y){
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
void setcursor(bool visible, DWORD size) {
    if(size == 0)
        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console,&lpCursor);
}
void drawBorder(){
    for(int i=0; i<SCREEN_HEIGHT; i++){
        for(int j=0; j<17; j++){
            gotoxy(0+j,i); cout<<"±";
            gotoxy(WIN_WIDTH-j,i); cout<<"±";
        }
    }
    for(int i=0; i<SCREEN_HEIGHT; i++){
        gotoxy(SCREEN_WIDTH,i); cout<<"±";
    }
}
void genEnemy(int ind){
    enemyX[ind] = 17 + rand()%(33);
}
void drawEnemy(int ind){
    if( enemyFlag[ind] == true ){
        gotoxy(enemyX[ind], enemyY[ind]);   cout<<"****";
        gotoxy(enemyX[ind], enemyY[ind]+1); cout<<"****";
        gotoxy(enemyX[ind], enemyY[ind]+2); cout<<"****";
        gotoxy(enemyX[ind], enemyY[ind]+3); cout<<"****";
    }
}
void eraseEnemy(int ind){
    if( enemyFlag[ind] == true ){
        gotoxy(enemyX[ind], enemyY[ind]); cout<<"    ";
        gotoxy(enemyX[ind], enemyY[ind]+1); cout<<"    ";
        gotoxy(enemyX[ind], enemyY[ind]+2); cout<<"    ";
        gotoxy(enemyX[ind], enemyY[ind]+3); cout<<"    ";
    }
}
void resetEnemy(int ind){
    eraseEnemy(ind);
    enemyY[ind] = 1;
    genEnemy(ind);
}

void drawCar(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            gotoxy(j+carPos, i+22); cout<<car[i][j];
        }
    }
}
void drawCar1(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            gotoxy(j+carPos, i+22); cout<<car1[i][j];
        }
    }
}
void drawCar2(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            gotoxy(j+carPos, i+22); cout<<car2[i][j];
        }
    }
}
void drawCar3(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            gotoxy(j+carPos, i+22); cout<<car3[i][j];
        }
    }
}
void eraseCar(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            gotoxy(j+carPos, i+22); cout<<" ";
        }
    }
}

int collision(){
    if( enemyY[0]+4 >= 23 ){
        if( enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9  ){
            return 1;
        }
    }
    if( enemyY[1]+4 >= 23 ){
        if( enemyX[1] + 4 - carPos >= 0 && enemyX[1] + 4 - carPos < 9  ){
            return 1;
        }
    }
    return 0;
}
void gameover(){
    system("cls");
    cout<<endl;
    cout<<"\t\tYOUR_SCORE:"<<score<<endl;
    cout<<"\t\t__________________________"<<endl;
    cout<<"\t\t__________________________"<<endl;
    cout<<"\t\t_________Game Over________"<<endl;
    cout<<"\t\t__________________________"<<endl;
    cout<<"\t\t_________Play again_______"<<endl;
    cout<<"\t\t__________________________"<<endl<<endl;
    cout<<"\t\tPress any key to go back to menu.";
    getch();
}
void updateScore(){
    gotoxy(WIN_WIDTH + 7, 5);cout<<"Score: "<<score<<endl;
}

void instructions(){

    system("cls");
    cout<<"Instructions";
    cout<<"\n*************";
    cout<<"\n Avoid obstacles by moving left or right. ";
    cout<<"\n\n Press 'a' to move left";
    cout<<"\n Press 'd' to move right";
    cout<<"\n Press 'esc' to exit";
    cout<<"\n\nPress any key to go back to menu";
    getch();
}
char choose_car()
{
    system("cls");
    gotoxy(50,5);
    cout<<"Choose your car";
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            gotoxy(j+40, i+10); cout<<car[i][j];
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            gotoxy(j+50, i+10); cout<<car1[i][j];
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            gotoxy(j+60, i+10); cout<<car2[i][j];
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            gotoxy(j+70, i+10); cout<<car3[i][j];
        }
    }
    gotoxy(42,15);
    cout<<"A";
    gotoxy(52,15);
    cout<<"B";
    gotoxy(62,15);
    cout<<"C";
    gotoxy(72, 15);
    cout<<"D";
    return getch();
}
void LOADING()
{
    int t = 0;
    char c1 = '%';
    int I = 100000000; while(I--){}
    system("cls");
    for(int i = 0; i < 25; i++) {
        char c = 178;
        t = (i+1) * 4;
        if(i != 24) printf("\n\n\t\t\t\t\n\n\t\t\t\tLoading...           %3d%c", t, c1);
        else        printf("\n\n\t\t\t\t\n\n\t\t\t\tLoaded               %3d%c", t, c1);
        printf("\n\t\t\t\t");
        for(long long j = 0; j <= i; j++) printf("%c", c);
        I = 50000000; while(I--){}
        if(i != 24) system("cls");
    }
    I = 500000000; while(I--){}
    system("cls");
}

void name()
{
    system("cls");
    string s;
    gotoxy(50, 13);
    cout<<"Enter a name: ";
    cin>>s;
}

int temp=0;

void play(){


    int i;
    name();
    char c = choose_car();

    for(i=0;i<1000000000;i++){}
    LOADING();

    carPos = -1 + WIN_WIDTH/2;
    score = 0;
    enemyFlag[0] = 1;
    enemyFlag[1] = 0;
    enemyY[0] = enemyY[1] = 1;

    system("cls");
    drawBorder();
    updateScore();
    genEnemy(0);
    genEnemy(1);

    gotoxy(WIN_WIDTH + 7, 2);cout<<"DODGE_CAR";
    gotoxy(WIN_WIDTH + 6, 4);cout<<"----------";
    gotoxy(WIN_WIDTH + 6, 6);cout<<"----------";
    gotoxy(WIN_WIDTH + 3, 12);cout<<"Control_Buttons";
    gotoxy(WIN_WIDTH + 7, 13);cout<<"------ ";
    gotoxy(WIN_WIDTH + 2, 14);cout<<" A Key  Left(<--)";
    gotoxy(WIN_WIDTH + 2, 15);cout<<" D Key  Right(-->)";

    gotoxy(18, 5);cout<<"Press any key to start";
    getch();
    gotoxy(18, 5);cout<<"                      ";


    while(1){
        if(kbhit()){
            char ch = getch();
            if( ch=='a' || ch=='A' ){
                if( carPos > 21 )
                    carPos -= 4;
            }
            if( ch=='d' || ch=='D' ){
                if( carPos < 50 )
                    carPos += 4;
            }
            if(ch==27){
                break;
            }
        }

        if(c=='a' || c=='A')
            drawCar();
        else if(c=='b' || c=='B')
            drawCar1();
        else if(c=='c' || c=='C')
            drawCar2();
        else if(c=='d' || c=='D')
            drawCar3();
        drawEnemy(0);
        drawEnemy(1);
        if( collision() == 1  ){
            gameover();
            return;
        }

        if(score%10==0)
            temp+=5;
        if(temp==45)
            temp=0;
        Sleep(60-temp);
        eraseCar();
        eraseEnemy(0);
        eraseEnemy(1);

        if( enemyY[0] == 10 )
            if( enemyFlag[1] == 0 )
                enemyFlag[1] = 1;

        if( enemyFlag[0] == 1 )
            enemyY[0] += 1;

        if( enemyFlag[1] == 1 )
            enemyY[1] += 1;

        if( enemyY[0] > SCREEN_HEIGHT-4 ){
            resetEnemy(0);
            score++;
            updateScore();
        }
        if( enemyY[1] > SCREEN_HEIGHT-4 ){
            resetEnemy(1);
            score++;
            updateScore();
        }
    }
}



int main()
{
    setcursor(0,0);
    srand( (unsigned)time(NULL));

    do{
        system("cls");
        gotoxy(30,5); cout<<"                            ";
        gotoxy(30,6); cout<<"         DODGE__CAR         ";
        gotoxy(30,7); cout<<"*****************************";
        gotoxy(30,9); cout<<"1. Start  ";
        gotoxy(30,10); cout<<"2. Instructions";
        gotoxy(30,11); cout<<"3. Quit";
        gotoxy(30,13); cout<<"Press button: ";
        char op = getche();

        if( op=='1') play();
        else if( op=='2') instructions();
        else if( op=='3') exit(0);

    }while(1);

    return 0;
}
