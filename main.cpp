#include <iostream>
#include <stack>

using namespace std;

bool isMoveValid(const stack<int>& from, const stack<int>& to)
{
    return (!from.empty() && (to.empty() || to.top() > from.top()));
}
void moveDisk(stack<int>& from, stack<int>& to)
{
    if (isMoveValid(from, to))
    {
        to.push(from.top());
        from.pop();

        return;
    }

    if (isMoveValid(to, from))
    {
        from.push(to.top());
        to.pop();
    }

}
void print(stack<int> A, stack<int> B, stack<int> C, int N)
{
    for (int i = N; i > 0; i--)
    {
        if (A.size() == i)
        {
            cout << A.top() << "\t";
            A.pop();
        }
        else
        {
            cout << "|" << "\t";
        }

        if (B.size() == i)
        {
            cout << B.top() << "\t";
            B.pop();
        }
        else
        {
            cout << "|" << "\t";
        }

        if (C.size() == i)
        {
            cout << C.top() << endl;
            C.pop();
        }
        else
        {
            cout << "|" << endl;
        }
    }

    cout << endl;
}

int main()
{
    stack<int> A, B, C;
    int N = 10;

    stack<int>& start = A;
    stack<int>& goal = C;

    for (int i = N; i > 0; i--)
    {
        start.push(i);
    }

    print(A, B, C, N);

    while (goal.size() < N)
    {
        moveDisk(A, B);
        print(A, B, C, N);
        moveDisk(A, C);
        print(A, B, C, N);
        moveDisk(B, C);
        print(A, B, C, N);
    }

    return 0;
}
