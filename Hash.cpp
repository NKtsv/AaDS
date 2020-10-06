#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#define TABLESIZE (10000)
#define IMPVALUE (-2147483648)

using namespace std;

class Hash
{
public:

    void AddElm(int value)
    {
        int key = hash_function(value);
        auto iterator = find(container[key].begin(), container[key].end(), value);
        if (iterator == container[key].end())
        {
            container[key].push_back(value);
        }        
//        container[key].sort();
    }

    void DelElm(int value)
    {
        if (value != IMPVALUE)
        {
            int key = hash_function(value);
            auto iterator = find(container[key].begin(), container[key].end(), value);
            if (iterator != container[key].end())
            {
                container[key].erase(iterator);
            }
        }
    }

    vector<int> ReturnVal()
    {
        vector<int> values;

        for (int i = 0; i < TABLESIZE; i++)
        {
            while (container[i].size() > 0)
            {
                values.push_back(container[i].front());
                container[i].pop_front();
            }
        }
        return values;
    }

private:
    vector<list<int>> container{TABLESIZE};

    int hash_function(int value)
    {
        return value % TABLESIZE;
    }
};

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    Hash Sequence;

    int number = 0;
    input >> number;
    while (number != 0)
    {
        number > 0 ? Sequence.AddElm(number) : Sequence.DelElm(number * -1);
        input >> number;
    }
    
    vector<int> Values = Sequence.ReturnVal();
    sort(Values.begin(), Values.end());

    for (int i = 0; i < Values.size(); i++)
    {
        output << Values[i] << " ";
    }
}