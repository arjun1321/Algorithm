#include<iostream>
#include<algorithm>
using namespace std;
const int MAX=5;
struct process{
    int id,arrival,waiting,cpu_bust,priority,flag=0;
}obj[MAX];

bool comp1 (process a,process b){
    if (a.arrival<b.arrival)
        return true;
    return false;
}
bool comp2 (process a,process b){
    if (a.priority<b.priority)
        return true;
    return false;
}

int main(){
    int i,arrive,cnt,finish;
    cout<<"Enter Input \n\n Id  Arrival_Time  Bust Priority\n";
    for(i=0;i<MAX;i++){
        cin>>obj[i].id;
        cin>>obj[i].arrival;
        cin>>obj[i].cpu_bust;
        cin>>obj[i].priority;
    }
    sort(obj,obj+MAX,comp1);

for(int i=0; i<5; i++)
{
    cout<<obj[i].id<<" "<<obj[i].arrival<<" "<<obj[i].cpu_bust<<" "<<obj[i].priority<<endl;
}

  /*  int total=0;
    arrive=obj[0].arrival;
    cnt=0;
    finish=0;
    while(cnt+1<MAX && obj[++cnt].arrival==arrive);

    while(finish<MAX){
        sort(obj+finish,obj+cnt,comp2);
        i=finish;

            obj[i].waiting=total;
            if((total-obj[i].arrival)>0)
                obj[i].wai=total-obj[i].arrival;
            else{
                obj[i].waiting=0;
                total+=obj[i].arrival-total;
            }
            total+=obj[i].cpu_bust;

        cnt=finish++;
        while(cnt<MAX && obj[++cnt].arrival<=total);

    }

    cout<<"\n\nId  Arrival_Time  Bust  Waiting  Turn_over\n";
    float avg=0;
    for(i=0;i<MAX;i++){
        avg+=obj[i].waiting;
        cout<<obj[i].id<<"          "<<obj[i].arrival<<"       ";
        cout<<obj[i].cpu_bust<<"     "<<obj[i].waiting<<"          ";
        cout<<obj[i].waiting+obj[i].cpu_bust<<endl;
    }
    cout<<"\n\n Average waiting time  :  "<<avg/MAX;*/
return 0;
}
