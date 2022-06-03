#include <stack>

using namespace std;

class SQueue
{
    private:
        stack<int> main;
        stack<int> temp;

    public:
        void enqueue(int);
        void dequeue();
        void printQueue();
};