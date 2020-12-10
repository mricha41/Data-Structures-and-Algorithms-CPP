#include "Stack.hpp"

template <std::size_t stackSize, class T1>
void Display(Stack<stackSize, T1> stack)
{
    assert(stack.size() > 0 &&
        "Your stack is empty. This function requires a non-empty stack.");

    std::cout << "Stack size: " << stack.size() << std::endl;
    std::cout << "Stack max size: " << stack.maxSize() << std::endl;
    std::cout << "Elements in Stack: " << std::endl;
    for (std::size_t i = stack.size() - 1; i > 0; --i)
    {
        i < stack.size() ? std::cout << stack[i] << " " :
            std::cout << stack[i];
    }
    std::cout << "\n\n";
}

template <std::size_t stackSize>
bool MatchParenthesis(char* expression)
{
    //printf("expression: %s\n", expression);

    Stack<stackSize, char> stack;

    for (std::size_t i = 0; expression[i] != '\0'; ++i)
    {
        //printf("current char: %c\n", expression[i]);
        if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(')
            stack.push(expression[i]);
        
        else if (expression[i] == '}' || expression[i] == ']' || expression[i] == ')')
        {
            if (stack.size() == 0)
                return false;

            stack.pop();
        }
    }

    /*if (stack.size() > 0)
    {
        std::cout << "stack contents after checks: " << "\n";
        Display(stack);
    }*/
    return stack.size() == 0 ? true : false;
}

std::size_t precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    
    return 0;
}

bool isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return false;

    return true;
}

template <std::size_t stackSize>
char* infixToPostfix(char* infix)
{
    std::size_t i = 0, j = 0;
    char* postfix = new char[stackSize];
    Stack<stackSize, char> stack;
    stack.push('\0'); //to ensure the char* postfix is well-formed

    while (stack.size() > 0 && infix[i] != '\0') {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if (stack.size() > 0 && precedence(infix[i]) > precedence(stack.top()))
                stack.push(infix[i++]);
            else {
                if(stack.size() > 0)
                    postfix[j++] = stack.pop();
            }
        }
    }

    while (stack.size() > 0)
        postfix[j++] = stack.pop();

    return postfix;
}