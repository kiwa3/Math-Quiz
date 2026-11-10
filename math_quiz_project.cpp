#include <iostream>
using namespace std;
enum enlevel {easy=1,med=2,hard=3,levelmix=4};
enum enopration {add=1,sub=2,mul=3,divide=4,oprationmix=5};
enum enispassed{pass=1,fail=2};

struct quizeround
{
    int firstnumber;
    int secounnumber;
short questionnumber=0;
int playeranswer;
int rightanswer;
enlevel qustionlevel;
enopration opration;
bool checkifright;
int answer;
};
struct fianlresult
{
short questionnumber=0;
enlevel qustionlevel;
enopration opration;
short numberof_right_answer=0;
short numberof_wrong_answer=0;
enispassed passed;
};
int randomnumber(int last,int first){
    return rand()%(last-first+1)+first;
}
short getnumberofqustions(){

short number;

cout<<"how many qustions you want to answer\n";
cin>>number;
return number;

}
enlevel getqustionlevel(){
    int number;
do
{
cout<<"enter qustion level easy[1] ,med[2],hard[3],mix[4]\n";
cin>>number;
} while (number<1||number>4);




return (enlevel)number;
}

string getpassedorfaild(enispassed ispassed){
string arry[2] ={"passed","fail"};
return arry[ispassed-1];

}
string stringgetqustionlevel(enlevel level){
string arry[4]={"easy","med","hard","mix"};
return arry[level-1];
}
string stringoprationtype(enopration opration){
string arry[5]={"add","sub","mul","divide","mix"};
return arry[opration-1];


}
enopration getopration(){
int number;
do
{
cout<<"enter opration typr add[1], sub[2], mul[3],div[4],mix[5]\n";
cin>>number;
} while (number<1||number>5);
return (enopration)number;


}
int getrandomnumber(enlevel quizlevel){
   
    
switch (quizlevel)
{
case enlevel::easy :
    return randomnumber(10,1);
    break;
case enlevel::med:
return randomnumber(50,10);
break;
case enlevel::hard:
return randomnumber(100,50);
break;

}


}

enopration getoprationtype(enopration oprationtype){

if (oprationtype==enopration::oprationmix)
{
    return(enopration)(randomnumber(4,1));
}
else {
    return oprationtype;
}


}
int qustion(quizeround quzeinfo,enopration opration){
    switch (opration)
    {
    case enopration::add:
    return quzeinfo.firstnumber+quzeinfo.secounnumber;
        break;
    case enopration::sub:
    return quzeinfo.firstnumber-quzeinfo.secounnumber;
        break;
        case enopration::mul:
    return quzeinfo.firstnumber*quzeinfo.secounnumber;
        break;
        case enopration::divide :
    return quzeinfo.firstnumber/quzeinfo.secounnumber;
        break;
    }




}
char charopration(enopration opration){
    char arry[4]={'+','-','*','/'};
    return arry[opration-1];

}
void printhequstion(quizeround quizeroundinfo,int numberofquestion,enopration opration){
    cout<<"question number["<<quizeroundinfo.questionnumber<<"/"<<numberofquestion<<"]\n\n";
    cout<<quizeroundinfo.firstnumber<<endl;
    cout<<quizeroundinfo.secounnumber<<" "<<charopration(opration)<<endl;
    cout<<"____________\n";



}




int playeransawe(){
    int number;
    cin>>number;
    return number;
}

void printresult(quizeround quizeinfo){
    if (quizeinfo.playeranswer==quizeinfo.rightanswer)
    {
        cout<<"right answer :-)\n";
       
    }
    else{
        cout<<"wrong answer the right answer is : "<< quizeinfo.rightanswer<<endl;
        



    }
    



}
enlevel getlevel(enlevel level){
if (level==enlevel::levelmix)
{
    return enlevel(randomnumber(3,1));
}
else 
return level;

}
enispassed chackresult(short qustionnumber,short qustioncorrect){
    if (qustioncorrect>(qustionnumber/2))
    {
    
    return enispassed::pass;
    }
    else{
        return enispassed::fail;
    }
    



}
fianlresult playgame(int numberofqustions){
    quizeround quizeroundinfo;
short numberof_right_answers=0;short numberof_wrong_answers=0;
quizeroundinfo.qustionlevel=getqustionlevel();
quizeroundinfo.opration=getopration();
enopration tempopration;
enlevel templevel;
for (int i = 0; i <numberofqustions; i++)
{
quizeroundinfo.questionnumber=i+1;
tempopration=getoprationtype(quizeroundinfo.opration);
templevel=getlevel(quizeroundinfo.qustionlevel);
quizeroundinfo.firstnumber=getrandomnumber(templevel);
quizeroundinfo.secounnumber=getrandomnumber(templevel);
quizeroundinfo.rightanswer=qustion(quizeroundinfo,tempopration);
printhequstion(quizeroundinfo,numberofqustions,tempopration);
quizeroundinfo.playeranswer=playeransawe();
if (quizeroundinfo.playeranswer==quizeroundinfo.rightanswer)
{
    numberof_right_answers++;
}
else{
numberof_wrong_answers++;
}
printresult(quizeroundinfo);

}
return {quizeroundinfo.questionnumber,quizeroundinfo.qustionlevel,quizeroundinfo.opration,numberof_right_answers,numberof_wrong_answers,chackresult(quizeroundinfo.questionnumber,numberof_right_answers)};





}

void gamesstatesr(fianlresult stats){


cout<<"__________________\n";
    cout<<"final result is "<<getpassedorfaild(stats.passed)<<endl;
    cout<<"__________________\n";
    cout<<"number of qustions:   "<<stats.questionnumber<<endl;
    cout<<"qustion level:   "<<stringgetqustionlevel(stats.qustionlevel)<<endl;
    cout<<"qustion level:   "<<stringgetqustionlevel(stats.qustionlevel)<<endl;
    cout<<"op type:   "<<stringoprationtype(stats.opration)<<endl;
    cout<<"number of right qustions:   "<<stats.numberof_right_answer<<endl;
    cout<<"number of worng qustions:   "<<stats.numberof_wrong_answer<<endl;
     cout<<"________________________________\n";

    
}

void startgame(){
    char playagain='Y';
do
{
    system("clear");
fianlresult game=playgame(getnumberofqustions());
    gamesstatesr(game);
    cout<<"if you want to play again press Y\n";
    cin>>playagain;



} while (playagain=='y'||playagain=='Y');

    
    


}


int main(){
srand( (unsigned)time(NULL));
startgame();

}