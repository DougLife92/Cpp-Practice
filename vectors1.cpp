// Takes 2 numbers, find the numbers divisable by 4 and 6 between the 2 numbers

#include <iostream>
#include <vector>

using namespace std;

vector<int> application(int x, int y)
{
    cout << "x = " << x << ", y = "<< y;
    
    vector<int> range;
    
    for (int i = x; i <= y; i++) 
        range.push_back(i); 
    
    auto it = range.begin();
    while (it != range.end())
    {
        // removes vector elements that arent divisable by 4 & 6
        if (((*it % 4) != 0) && ((*it % 6) != 0)) 
            it = range.erase(it);
        
        // Otherwise incriments the interator
        else 
            ++it;
    }
    
    return range;
}

int main()
{
    cout<<"Hello World\n\n";

    vector<int> res = application(3, 40);
    
    return 0;
}
