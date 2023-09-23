#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    vector<string> names;
    names.push_back(s);
    string type = "";
    for (int i = 0; i < n - 1; i++)
    {
        cin >> s;
        if (type == "")
        {
            if (names[i] < s)
            {
                type = "INCREASING";
            }
            else if (names[i] > s)
            {
                type = "DECREASING";
            }
        }
        else
        {
            if ((names[i] < s && type != "INCREASING") || (names[i] > s && type != "DECREASING"))
            {
                type = "NEITHER";
            }
        }
        names.push_back(s);
    }
    if (type == "")
    {
        type = "NEITHER";
    }
    cout << type;
}