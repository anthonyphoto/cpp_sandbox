#include <iostream> 
#include <string> 
#include <vector> 

using namespace std;

void all_combos(vector<char>& letters, int n, string prefix = "")
{
    if (n == 0) {
        cout << prefix << endl;
        return;
    }

    for (char letter : letters) {
        string newPrefix = prefix + letter;
        all_combos(letters, n - 1, newPrefix);
    }
}

int main() {
    vector<char> letters;
    letters.push_back('U');
    letters.push_back('S');
    letters.push_back('C');
    
    all_combos(letters, 4);

    return 0; 
}