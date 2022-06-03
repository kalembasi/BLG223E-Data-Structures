#include <queue>

using namespace std;

class QStack
{
    private:
        queue<int> main;

    public:
        void push(int);
        void pop();
        void printStack();
};