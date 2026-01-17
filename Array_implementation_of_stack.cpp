#include <iostream>
using namespace std;


struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

Stack* createStack(unsigned capacity){
    Stack* stack = new Stack();
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new int[(stack->capacity * sizeof(int))];
    return stack;
}

int isFull(Stack* stack){
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack){
    return stack->top == -1;
}

void push(Stack* stack, int item){
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    cout << item << " pushed to stack\n";
}

int pop(Stack* stack){
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int peek(Stack* stack){
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

int main(){
    Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    cout << pop(stack) << " popped from stack\n";
    cout << pop(stack) << " popped from stack\n";
    cout << pop(stack) << " popped from stack\n";
    cout << "Top element is: " << peek(stack) << endl;

    return 0;
}