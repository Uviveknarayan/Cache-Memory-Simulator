#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <bitset>
#include <string>
using namespace std;

vector<pair<int,string> > v[10000];
double hit;

string HexToBin(string hexdec)
{
    long int i = 0;
    string bi="";
    while (hexdec[i]) {
 
        switch (hexdec[i]) {
        case '0':
            bi=bi+"0000";
            break;
        case '1':
            bi=bi+"0001";
            break;
        case '2':
            bi=bi+"0010";
            break;
        case '3':
            bi=bi+"0011";
            break;
        case '4':
            bi=bi+"0100";
            break;
        case '5':
            bi=bi+"0101";
            break;
        case '6':
            bi=bi+"0110";
            break;
        case '7':
            bi=bi+"0111";
            break;
        case '8':
            bi=bi+"1000";
            break;
        case '9':
            bi=bi+"1001";
            break;
        case 'A':
        case 'a':
            bi=bi+"1010";
            break;
        case 'B':
        case 'b':
            bi=bi+"1011";
            break;
        case 'C':
        case 'c':
            bi=bi+"1100";
            break;
        case 'D':
        case 'd':
            bi=bi+"1101";
            break;
        case 'E':
        case 'e':
            bi=bi+"1110";
            break;
        case 'F':
        case 'f':
            bi=bi+"1111";
            break;
        default:
            cout << "\nInvalid hexadecimal digit "
                 << hexdec[i];
        }
        i++;
    }return bi;
}
 
int bintodec(int a){
	int k,i=0;
	int s=0;
	while(a!=0){
		k=a%10;
		a=a/10;
		s=s+k*pow(2,i);
		i++;
	}
	return s;
}

void hitornot(int index,string tag,int k){
	if(v[index][0].first==0){
            v[index][0].second=tag;
            v[index][0].first=1;
            return ;
         }
   bool b=false;
   for(int i=0;i<k;i++){
      if(v[index][i].first==1 && v[index][i].second==tag){
      	 b=true;
      	 hit++;
      	 for(int j=i;j<k-1;j++){
      	 	v[index][j].first=v[index][j+1].first;
      	    v[index][j].second=v[index][j+1].second;
      	 }
      	 if(v[index][k-1].first==1){
      	 	v[index][k-1].second=tag;
      	 }
      	 else{
      	 	for(int i=0;i<k;i++){
      	 		if(v[index][i].first==0){
      	 			v[index][i].first=1;
      	 			v[index][i].second=tag;
      	 			break;
      	 		}
      	 	}
      	 }
         return ;
      }
   }
   if(b==false){
      if(v[index][k-1].first==1){
         for(int i=0;i<k-1;i++){
            v[index][i].second=v[index][i+1].second;
         }
         v[index][k-1].second=tag;
         return;
      }
      else{
         for(int i=0;i<k;i++){
            if(v[index][i].first==0){
               v[index][i].first=1;
               v[index][i].second=tag;
               return;
            }
         }
      }
   }
}
 
int main(){
	hit=0;
    int t,k;
    ifstream par("mmout.txt");
    par>>t>>k;
     int a,ibit,c;
     par>>a>>ibit>>c;
     int l=pow(2,ibit);
     for(int i=0;i<l;i++){
      for(int j=0;j<k;j++){
        v[i].push_back(make_pair(0,""));
      }
    }
    double r=(double)t;
     while(t>0){
        string s1;
        par>>s1;
        /*stringstream ss;
        ss << hex << s1;
        unsigned n;
        ss >> n;
        //int u=4*s1.size();
        bitset<28> b(n);
        string s=b.to_string();*/
        string s=HexToBin(s1);
        string boff=s.substr(a+ibit,c);
        string ind=s.substr(a,ibit);
        string tag=s.substr(0,a);
        int indi=stoi(ind);
        int index=bintodec(indi);
        hitornot(index,tag,k);
        //cout<<index<<" "<<tag<<" "<<v[index][0].first<<endl;
     t--;}
     double hr=hit/r;
     cout<<hit<<endl;
     cout<<hr<<endl;
     /*for(int i=0;i<4;i++){
     	   cout<<v[2][i].second<<endl;
        }*/
     return 0;
}