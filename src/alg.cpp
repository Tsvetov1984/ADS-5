// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int GetPrioriti(char operand) {
    if (operand == '+' || operand == '-') return 1;
    if (operand == '*' || operand == '/') return 2;
    return 0;
}

bool ProverkaNaOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

std::string infx2pstfx(std::string inf) {
    std::string postfix;
    TStack<char, 100> stack;
    for (char c: inf) {
        if (isdigit(c)) {
            postfix += c;
            postfix += ' ';
        } else if (c == '(') {
            stack.push(c);
        } else if (ProverkaNaOperator(c)) {
            while (!stack.isEmpty() && GetPrioriti(stack.get()) >= GetPrioriti(c)) {
                postfix += stack.get();
                postfix += ' ';
                stack.pop(c);
            }
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.get() != '(') {
                postfix += stack.get();
                postfix += ' ';
                stack.pop();
            }
            stack.pop();
        }
    }
    while (!stack.isEmpty()) {
        postfix += stack.get();
        postfix += ' ';
        stack.pop();
    }
    return postfix;
}

int eval(std::string post) {
    TStack<int, 100> stack;
    std::string Number;
    for (char c: post) {
        if (isdigit(c)) {
            Number += c;
        } else if (Number != "") {
            stack.push(std::stoi(Number));
            Number = "";
        }
        if (ProverkaNaOperator(c)) {
            int op2 = stack.get();
            stack.pop();
            int op1 = stack.get();
            stack.pop();
            switch (c) {
                case '+':
                    stack.push(op1 + op2);
                    break;
                case '-':
                    stack.push(op1 - op2);
                    break;
                case '*':
                    stack.push(op1 * op2);
                    break;
                case '/':
                    stack.push(op1 / op2);
                    break;
            }
        }
    }
    if (Number != "") {
        stack.push(std::stoi(Number));
    }
    return stack.get();
}
