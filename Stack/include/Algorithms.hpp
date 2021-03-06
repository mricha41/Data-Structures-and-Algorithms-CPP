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