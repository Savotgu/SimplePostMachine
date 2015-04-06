#include "includes/postlogic.h"
#include <iostream>
#include <string>
#include <QtDebug>
#include <unistd.h>

int PostLogic::sum(std::string &text)
{
    int a(0), b(0);
    while(text[b]=='c')
        b++;
    if(text[b]!='#')
    {
        a=1;
        text[b]='c';
    }
    else
        text[b]=' ';
    return a;
}

int PostLogic::sub(std::string &text)
{
    int i(0);
    for(;text[i]=='a';i++);
    if(i>0 && text[i]!='#'){
        qDebug() << i;
        text.erase(i,1);
        text.erase(0,1);
    }
    else
    {
        return sum(text);
    }
    return 0;
}

int PostLogic::mul(std::string &text)
{
    int i(0),sum(0);
    for(;text[i]=='a';i++);
    if(i>0)
    {
        i=-1;
        text.erase(0,1);
        while(text[i]!='#')
        {
            if(text[i]=='b')
            {
                text.insert(text.begin()+(i+1),'c');
                sum+=1;
            }
            i++;
        }
    }
    else
    {
        while(text.back()=='#')
        {
            if(text[i]!='c')
                text.erase(i,1);
            else
                i++;
        }
    }
    return sum;
}

int PostLogic::div(std::string &text)
{
    int sum(0),i(1);
    for(;text[i]=='a' || text[i]=='b';i++)
    {
        if(text[i]=='b' && text[0]=='a'){
            text.erase(0,1);
            i-=1;
            sum=1;
        }else
            sum=0;
    }
    if(sum==1){
        text.insert(text.end()-1,'c');
    }
    else
    {
        for(int j(0);text.back()=='#';j++)
        {
            if(text[j]!='c'){
                text.erase(j,1);
                j-=1;
            }
        }
    }
    return sum;
}



