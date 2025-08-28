class MyStack {
    int arr[1000];
    int top;
  public:
    MyStack() {
        top = -1;
    }
    
    void push(int x) {
        // code here
        top++;
        arr[top] = x;
    }
    
    int pop() {
        // code here
        if (top == -1) {
            return -1;
        }
        int poppedElement = arr[top];
        top--;
        return poppedElement;
    }
};