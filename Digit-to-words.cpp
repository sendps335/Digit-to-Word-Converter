#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,string> m1;
    m1[1]="one";
    m1[2]="two";
    m1[3]="three";
    m1[4]="four";
    m1[5]="five";
    m1[6]="six";
    m1[7]="seven";
    m1[8]="eight";
    m1[9]="nine";
    
    map<int,string> m2;
    m2[0]="ten";
    m2[1]="eleven";
    m2[2]="twelve";
    m2[3]="thirteen";
    m2[4]="forteen";
    m2[5]="fifteen";
    m2[6]="sixteen";
    m2[7]="seventeen";
    m2[8]="eighteen";
    m2[9]="nineteen";
    
    map<int,string> m3;
    //m3[1]="ten";
    m3[1]="ten";
    m3[2]="twenty";
    m3[3]="thirty";
    m3[4]="forty";
    m3[5]="fifty";
    m3[6]="sixty";
    m3[7]="seventy";
    m3[8]="eighty";
    m3[9]="ninety";
    
    int t,pos,rem,prev,dup,n,rem2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        prev=0;
        pos=0;
        rem=0;
        dup=n;
        stack<string> words;
        while(dup != 0)
        {
            rem=dup%10;
            if(pos == 0)
            {
                if(rem != 0)
                {
                    words.push(m1[rem]);
                }
            }
            else if(pos == 1 and rem != 0)
            {
                if(rem == 1 and words.size() != 0)//Special Case of 10-19
                {
                    words.pop();
                    words.push(m2[prev]);
                }
                else if(rem != 1 and words.size() != 0)
                {
                    words.push(m3[rem]+" ");
                }
                else if(words.size()==0 and rem != 1)
                {
                    words.push(m3[rem]);
                }
                else if(rem ==1 and words.size()==0)
                {
                    words.push(m3[rem]);
                }
            }
            else if(pos == 2 and rem != 0)
            {
                if(words.size()!= 0)
                {
                    words.push(m1[rem]+" hundred "+"and ");
                }
                else
                {
                    words.push(m1[rem]+" hundred ");
                }
            }
            else if(pos == 3 and rem != 0)
            {
                words.push(m1[rem]+" "+"thousand ");
            }
            pos+=1;
            dup=dup/10;
            prev=rem;
        }
        while(words.empty() == false)
        {
            cout<<words.top();
            words.pop();
        }
        cout<<endl;
    }
    
}