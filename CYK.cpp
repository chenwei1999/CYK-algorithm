#include <bits/stdc++.h>
using namespace std;

vector <string>  CNF;

int  CNFNum;
//��CNF�洢��vector����
void LoadCNF()
{
     string s;
     int num;
     cout<<"���������ʽ����:";
     cin>>num;
     CNFNum=num;
     cout<<"��������ķ˹����ʽ�ķ�:\n";
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
     cout<<"��������ж���ֹ����:\n";
     cin>>str;
     int strlen;
     int i,j,k,t,m,n;
	 strlen=str.length();
     vector<vector<string > > ans(strlen+1);
     for (i = 0; i < ans.size(); i++)
        ans[i].resize(strlen+1);
     

     //    ���ҳ�������ֹ���Ĳ���ʽ��
     for(i = 1 ;i <= strlen; i++)
        {
             for(t=0;t<CNF.size();t++)
                {
                    if(CNF[t].find(str[i-1],0)!=string::npos)
                        ans[1][i]+=CNF[t][0];
                }               
        }

    //    �����ö�̬�滮�ҳ�������������
    string temp;
    for(j=2;j<=strlen;j++)
        for(i=1;i<=strlen-j+1;i++)
        {
            for(k=1;k<=j-1;k++)
               {
                   //    ����˸�Ϊ��ֱ������
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
                                  if(ans[j][i].find(CNF[t][0],0)==string::npos)  //������������û��Ҫ�ټ���(ȥ��)
									           ans[j][i]+=CNF[t][0];
                            }       
                        }
               }
        }
  
   //����Ϊ������ʾ����
   cout<<"\n������:\n\n";
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
    

    //���V1n���������ʼ��S,x����L(G)
    cout<<endl<<endl;
    if(ans[strlen][1].find("S",0)!=string::npos)
         cout<<"���:Y\n";
    else
         cout<<"���:N\n";
    
   system("pause"); 
}
