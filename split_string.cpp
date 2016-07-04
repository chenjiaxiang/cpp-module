#include<string>
#include<vector>
using namespace std;
//ds is destination string need to be split，after_split is a vector storing result,decollator is set of separators.
void str_split(const string &ds,vector<string> &after_split,const string &decollator)
{
    if(!ds.size())
        throw runtime_error("the stirng needed to be splited is empty!");
    string::size_type beforepos = 0,afterpos = 0;
    while(true)
    {
        afterpos = ds.find_first_of(decollator,beforepos);
        if(afterpos == string::npos)
            break;
        if(afterpos == beforepos)
            ;
        else
        {
            string temp(ds,beforepos,afterpos-beforepos);
            after_split.push_back(temp);
        }
        beforepos = afterpos+1;
    }
    if(beforepos == ds.size())
        return;
    string temp(ds,beforepos);
    after_split.push_back(temp);
}
