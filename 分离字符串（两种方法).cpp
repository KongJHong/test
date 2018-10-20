

string str = "dog cat cat cat";
void diverseString(string str)
{
    vector<string> strs;
    string s = "";

    for(int i = 0; str[i] != '\0';i++)
    {
        if(str[i] == ' ')
        {
            strs.push_back(s);
            s = "";
        }
        else
            s += str[i];
    }

    strs.push_back(s);//保存最后一个string
}


#include <sstream>
void diverseString2(string str)
{
    istringstream in(str);//这里有点取巧
    string word;
    while(in>>word)
    {
        ...
    }


}