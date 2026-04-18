// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priorityCheck(char ps) {
  if (ps == '+' || ps == '-') return 1;
  if (ps == '*' || ps == '/') return 2;
  return 0;
}

bool isOperator(char s) {
  return s == '+' || s == '-' || s == '*' || s == '/';
}

bool isDigit(char s) {
  return (s >= '0' && s <= '9');
}

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> stack;
  std::string result;
  for (size_t i = 0; i < inf.size(); i++) {
    char c = inf[i];
    if (c == ' ') continue;
    if (isDigit(c)) {
      while (i < inf.size() && isDigit(inf[i])) {
        result += inf[i];
        i++;
      }
      result += ' ';
      i--;
    } else if (c == '(') {
      stack.push(c);
    } else if (c == ')') {
      while (!stack.isEmpty() && stack.top() != '(') {
        result += stack.pop();
        result += ' ';
      }
      if (!stack.isEmpty()) {
        stack.pop();
      }
    } else if (isOperator(c)) {
      while (!stack.isEmpty() &&
       priorityCheck(stack.top()) >= priorityCheck(c)) {
        result += stack.pop();
        result += ' ';
      }
      stack.push(c);
    }
  }
  while (!stack.isEmpty()) {
    char oper = stack.pop();
    if (oper != '(' && oper != ')') {
      result += oper;
      result += ' ';
    }
  }
  if (!result.empty()) {
    result.pop_back();
  }
  return result;
}

int eval(const std::string& pref) {
  TStack<int, 100> stack;
  for (size_t i = 0; i < pref.size(); i++) {
    char c = pref[i];
    if (c == ' ') continue;
    if (isDigit(c)) {
      int number = 0;
      while ((i < pref.size()) && isDigit(pref[i])) {
        number = number * 10 + (pref[i] - '0');
        i++;
      }
      stack.push(number);
      i--;
    } else {
      int last = stack.pop();
      int preLast = stack.pop();
      if (c == '+') stack.push(preLast + last);
      else if (c == '-') stack.push(preLast - last);
      else if (c == '*') stack.push(preLast * last);
      else if (c == '/') stack.push(preLast / last);
    }
  }
  return stack.pop();
}
