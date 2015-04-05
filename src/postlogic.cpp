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
    for(i;text[i]=='a';i++);
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



