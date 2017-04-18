#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
    vector<int> scores;
    vector<int> bullshitScores;
    bullshitScores.push_back(300);
    vector<int>::const_iterator iteratorConst;

    scores.push_back(1500);
    scores.push_back(3000);
    scores.push_back(4500);

    cout << "Scores are:\n";
    for (iteratorConst = scores.begin(); iteratorConst != scores.end(); iteratorConst++)
    {
        cout << *iteratorConst << endl;
    }
    cout << endl;

    iteratorConst = find(scores.begin(), scores.end(), 3000);
    if (iteratorConst == scores.end())
    {
        cout << "Score wasn't found." << endl;
    }
    else
    {
        cout << "Score was found, great!" << endl;
    }

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(scores.begin(), scores.end());
    cout << "Scores in randomised order are:\n";
    for (iteratorConst = scores.begin(); iteratorConst != scores.end(); iteratorConst++)
    {
        cout << *iteratorConst << endl;
    }
    cout << endl;

    sort(scores.begin(), scores.end());
    cout << "Scores in sorted orders are:\n";
    for (iteratorConst = scores.begin(); iteratorConst != scores.end(); iteratorConst++)
    {
        cout << *iteratorConst << endl;
    }
    cout << endl;

    vector<int> test(10, 0);
    cout << "Vector     size is: " << test.size() << endl;
    cout << "Vector capacity is: " << test.capacity() << endl;
    test.push_back(0);
    cout << "Vector     size is: " << test.size() << endl;
    cout << "Vector capacity is: " << test.capacity() << endl;





    return 0;
}
