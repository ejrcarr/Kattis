#include <vector>
#include <iostream> 
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        vector<string> cities;
        for (int j = 0; j < t; j++)
        {
            string s;
            cin >> s;
            bool alreadyFound = false;
            for (int k = 0; k < cities.size(); k++)
            {
                if (!alreadyFound && cities[k] == s)
                {
                    alreadyFound = true;
                    break;
                }
            }

            if (!alreadyFound)
            {
                cities.push_back(s);
            }
        }
        cout << cities.size() << endl;
    }
}