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
        if (expression[i] == '(')
            stack.push(expression[i]);
        
        else if (expression[i] == ')')
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