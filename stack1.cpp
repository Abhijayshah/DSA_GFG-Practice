// // step 1  push() and display ()


// #include <iostream>
// using namespace std;


// int Mystack[5], n = 5, top = -1;


// void push(int x)
// {
//    if (top == n - 1)
//        cout << "stack is full " << endl;
//    else
//    {
//        top++;
//        Mystack[top] = x;
//    }
// }


// void display()
// {
//    if (top >= 0)
//    {
//        cout << "stack element are : " << endl;
//        for (int i = top; i >= 0; i--)
//            cout << Mystack[i] << endl;
//    }
//    else
//        cout << "stack is empty ";
// }


// int main()
// {
//    push(1);
//    push(2);
//    push(3);
//    push(4);
//    push(5);
//    push(6);    // ---> stack is full
//    display();   // --stack element are :   5 ,4 ,3, 2 ,1


// }


// step-2  pop()
// #include <iostream>
// using namespace std;


// int Mystack[5], n = 5, top = -1;


// void push(int x)
// {
//    if (top == n - 1)
//        cout << "stack is full " << endl;
//    else
//    {
//        top++;
//        Mystack[top] = x;
//    }
// }


// void pop()
// {
//    if (Mystack[top] == -1)
//    {
//        cout << "the stack is empty " << endl;
//    }
//    else
//    {


//        cout << "the poped element is " << Mystack[top] << endl;
//        top--;
//    }
// }

// void display()
// {
//    if (top >= 0)
//    {
//        cout << "stack element are : " << endl;
//        for (int i = top; i >= 0; i--)
//            cout << Mystack[i] << endl;
//    }
//    else
//        cout << "stack is empty ";
// }


// int main()
// {
//    push(1);
//    push(2);
//    push(3);
//    push(4);
//    push(5);
//    // push(6);
//    display();
//    pop();
//    pop();
//    pop();
//    pop();
//    pop();
// }



// // step-3 - peek( )
// #include <iostream>
// using namespace std;


// int Mystack[5], n = 5, top = -1;


// void push(int x)
// {
//    if (top == n - 1)
//        cout << "stack is full " << endl;
//    else
//    {
//        top++;
//        Mystack[top] = x;
//    }
// }


// int peek()
// {
//    return Mystack[top];
// }


// int main()
// {
//    push(1);
//    push(2);
//    push(3);
//    push(4);
//    push(5);


//    int y = peek();
//    cout << "top element of the stack is : " << y;
// }












