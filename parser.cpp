#include "parser.h"

parser::parser()
{
}

parser::~parser()
{
}

std::vector<std::string> parser::strToVector(std::string input)
{
    std::vector<std::string> expVect;

    std::queue<char> line;
    std::string send;

    //put input into a queue
    for(int i = 0; i < input.size(); i ++)
        line.push(input[i]);

    char firstCheck = line.front();

    //in case first number is negative
    if(firstCheck == '-')
    {
        send += firstCheck;
        line.pop();
    }
    firstCheck = ' ';

    char check;
    //go through queue and add to expVect, string to vector
    do
    {
        check = line.front();
        if(isdigit(check) || check == '.' || check == ' ')
        {
            if(check == ' ')
            {
                send += check;
                line.pop();
                check = line.front();
                do
                {
                    if(check != ' ')
                        send += check;
                    line.pop();
                    check = line.front();
                }while(check != '/');
            }
            send += check;
            line.pop();
        }
        else
        {
            if(!send.empty())
            {
                expVect.push_back(send);
                send.clear();
            }
            send += check;
            expVect.push_back(send);
            send.clear();
            line.pop();
            char c;
            c = line.front();
            if(c == '-' || c == ' ')
                do
                {
                    if(c == '-')
                    {
                        send += c;
                        line.pop();
                    }
                    else
                    {
                        line.pop();
                        c = line.front();
                    }
                }while(c == ' ');
        }
    }while(!line.empty());

    if(!send.empty())
        expVect.push_back(send);

    return expVect;
}

std::vector<std::string> parser::toRPN(std::vector<std::string> exp)
{
    std::vector<std::string> RPNVect;

    std::stack<std::string> LIFO;
    std::queue<std::string> FIFO;

    char last;

    for(int i = 0; i < exp.size(); i++)
    {
        std::string check = exp[i];
        char next = check[0];

        if(isdigit(next) || (next == '-' && check.size() > 1))
        {
            FIFO.push(check);
        }
        else if(LIFO.empty() && !isdigit(next))
        {
            LIFO.push(check);
        }
        else if(check =="+" || check =="-" || check =="*" || check =="/")
        {
            int inStack, nextValue;
            inStack = getPrecedence(LIFO.top());
            nextValue = getPrecedence(check);
            if(inStack < nextValue)
                LIFO.push(check);
            else
            {
                do
                {
                    FIFO.push(LIFO.top());
                    LIFO.pop();
                    if(!LIFO.empty())
                        inStack = getPrecedence(LIFO.top());
                }while(inStack >= nextValue && !LIFO.empty());
                LIFO.push(check);
            }
        }
        else if(check == "(" || check == ")")
        {
            switch(next)
            {
            case '(':
                if(isdigit(last))
                    LIFO.push("*");
                LIFO.push(check);
                break;
            case ')':
                do
                {
                    FIFO.push(LIFO.top());
                    LIFO.pop();

                }while(LIFO.top() != "(");
                if(LIFO.top() == "(")
                {
                    LIFO.pop();
                }
                break;
            }
        }
        else
        {
            throw TRANSLATE_ERROR;
            std::cout<<check<<std::endl;
        }
        last = next;
    }
    if(!LIFO.empty())
    {
        do
        {
            FIFO.push(LIFO.top());
            LIFO.pop();
        }while(!LIFO.empty());
    }
    do{
        RPNVect.push_back(FIFO.front());
        FIFO.pop();

    }while(!FIFO.empty());

    return RPNVect;
}

int parser::getPrecedence(std::string str)
{
    char s = str[0];
    switch(s)
    {
    case '+':
        return 0;
        break;
    case '-':
        return 0;
        break;
    case '*':
        return 1;
        break;
    case '/':
        return 1;
        break;
    default:
        return -1;
    }
}

std::vector<std::string> parser::parseToRPN(const std::string  &input)
{
    std::vector<std::string> send;
    send = toRPN(strToVector(input));
    return send;
}

void parser::ensureInputValid(const std::string &input)
{

}
