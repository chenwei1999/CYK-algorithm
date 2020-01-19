#include <bits/stdc++.h>
using namespace std;

vector <string>  CNF;

int  CNFNum;
//将CNF存储到vector容器
void LoadCNF()
{
     string s;
     int num;
     cout<<"请输入产生式数量:";
     cin>>num;
     CNFNum=num;
     cout<<"请输入乔姆斯基范式文法:\n";
     while(num--)
     {
         cin>>s;
         CNF.push_back(s);
     }
}

int main()
{
     LoadCNF();
     string str;
     cout<<"请输入待判断终止符串:\n";
     cin>>str;
     int strlen;
     int i,j,k,t,m,n;
	 strlen=str.length();
     vector<vector<string > > ans(strlen+1);
     for (i = 0; i < ans.size(); i++)
        ans[i].resize(strlen+1);
     

     //    先找出产生终止符的产生式左部
     for(i = 1 ;i <= strlen; i++)
        {
             for(t=0;t<CNF.size();t++)
                {
                    if(CNF[t].find(str[i-1],0)!=string::npos)
                        ans[1][i]+=CNF[t][0];
                }               
        }

    //    再利用动态规划找出表内其余内容
    string temp;
    for(j=2;j<=strlen;j++)
        for(i=1;i<=strlen-j+1;i++)
        {
            for(k=1;k<=j-1;k++)
               {
                   //    如果此格为空直接跳过
                   if((ans[k][i].empty())||(ans[j-k][i+k].empty()))  
                         continue;

                   for(m=0;m<ans[k][i].length();m++)
                     for(n=0;n<ans[j-k][i+k].length();n++)
                        {
                            temp.clear();
                            temp+=ans[k][i][m];
                            temp+=ans[j-k][i+k][n];
                            for(t=0;t<CNF.size();t++)
                            {
                                if(CNF[t].find(temp,0)!=string::npos)
                                  if(ans[j][i].find(CNF[t][0],0)==string::npos)  //如果表格内已有没必要再加入(去重)
									           ans[j][i]+=CNF[t][0];
                            }       
                        }
               }
        }
  
   //底下为内容显示部分
   cout<<"\n表如下:\n\n";
   cout<<"\t";
   for(i=0;i<strlen;i++)
    cout<<str[i]<<"\t";
   cout<<endl<<endl;
   cout<<"\t";
   for(i=0;i<strlen;i++)
    cout<<i+1<<"\t";
   cout<<endl<<endl;
   for(i=1;i<=strlen;i++)
      {
          cout<<i<<"\t";
          for(j=1;j<=strlen-i+1;j++)
        {
               if(ans[i][j].empty())
                   cout<<"-"<<"\t";
               else
               {
                     cout<<ans[i][j]<<"\t";
               }
               
        }
        cout<<endl<<endl;
      }
    

    //如果V1n表格中有起始符S,x属于L(G)
    cout<<endl<<endl;
    if(ans[strlen][1].find("S",0)!=string::npos)
         cout<<"输出:Y\n";
    else
         cout<<"输出:N\n";
    
   system("pause"); 
}
