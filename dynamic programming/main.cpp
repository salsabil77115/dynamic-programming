#include <iostream>
#include<vector>
using namespace std;

int main()
{
vector<string>itemName;
vector<int>profits;
vector<int>prices;
prices.push_back(0);
profits.push_back(0);
int profit=0;
int price=0;
string Name;
int maxWeight=0;

cout<<"Enter MaxWeight:";
cin>>maxWeight;
int calcProfit[9][maxWeight+1];
for(int j=0;j<maxWeight+1;j++){
   calcProfit[0][j]=0;
}
for(int i=0;i<9;i++){
    calcProfit[i][0]=0;
}
for(int i=1;i<9;i++){
cout<<"Enter itemName:";
cin.ignore();
getline(cin,Name);
itemName.push_back(Name);
cout<<"Enter Price:";
cin>>price;
prices.push_back(price);
cout<<"Enter Profit:";
cin>>profit;
profits.push_back(profit);
}
for(int i=1;i<9;i++){
for(int j=1;j<maxWeight+1;j++){
if(j<prices[i]){
calcProfit[i][j]=0;

    }else if(j==prices[i]){
        if(calcProfit[i-1][j]>profits[i]){

         calcProfit[i][j]=calcProfit[i-1][j];
        }else{

        calcProfit[i][j]=profits[i];}
    }else if(j>prices[i]){
        int second=profits[i]+calcProfit[i-1][j-prices[i]];
        if(second>calcProfit[i-1][j]){
         calcProfit[i][j]=second;
        }
        else{
        calcProfit[i][j]=calcProfit[i-1][j];
            }
}
}}
int i=8,j=30;
int x=-1;
vector<int>num;
while(true){
        if(x==0){break;}
   if(calcProfit[i][j]>calcProfit[i-1][j]){
        num.push_back(i);
    x=calcProfit[i][j]-profits[i];
    i--;
    int k=0;
    for(;k<j;k++){
   if(x==calcProfit[i][k]){
break;
}}
j=k;
   }else{
   i--;
   }
}
for(int i=0;i<num.size();i++){

    cout<<itemName[num[i]]<<endl;
}
    return 0;
}
