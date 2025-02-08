#include  <iostream>

using namespace std;

//implementacao imperativa

string longest_common_prefix(string* array, int size)
{   
    if(size < 1)
        return " ";
    string prefix = array[0];
    for(int i = 1; i < size; i++)
    {
        string new_prefix = "";
        int prefix_size = prefix.size();

        for(int j = 0; j < prefix_size; j++)
            if(prefix[j] == array[i][j])
                new_prefix.push_back(prefix[j]);
            else
                break;

        prefix = new_prefix;
    }
    return prefix;
}

int main(void)
{
    string array[] = {"lucaslindodemais", "lucaslindoabsurdamente", "lucaslindodemasiadamente", "lucaslindodenovo", "luquinhas"};
    int array_size = sizeof(array)/sizeof(string);

    cout << longest_common_prefix(array, array_size) << endl;

    return EXIT_SUCCESS;
}