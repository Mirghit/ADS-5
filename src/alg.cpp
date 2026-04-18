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

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> stack;
  std::string result;

  for (size_t i = 0; i < inf.size(); i++) {
    char c = inf[i];

    if (c == ' ') continue;

    if (c >= '0' && c <= '9') {
      while ((i < inf.size()) && (inf[i] >= '0' && inf[i] <= '9')) {
        result += inf[i++];
      }
      result += " ";
      i--;
    }
    else if (c == '(') {
      stack.push(c);
    }
    else if (c == ')') {
      while (!stack.isEmpty() && stack.top() != '(') {
        result += stack.pop();
        result += " ";
      }
      stack.pop();
    }
    else if (isOperator(c)) {
      while (!stack.isEmpty() && priorityCheck(stack.top()) >= priorityCheck(c)) {
        result += stack.pop();
        result += " ";
      }
      stack.push(c);
    }
  }
  while (!stack.isEmpty()) {
    result += stack.pop();
    result += " ";
  }
  return result;
}

int eval(const std::string& pref) {
  TStack<int, 100> stack;

  for (size_t i = 0; i < pref.size(); i++) {
    char c = pref[i];

    if (c == ' ') continue;

    if (c >= '0' && c <= '9') {
      int number = 0;
      while ((i < pref.size()) && (pref[i] >= '0' && pref[i] <= '9')) {
        number = number * 10 + (pref[i] - '0');
        i++;
      }
      stack.push(number);
      i--;
    }
    else {
      int last = stack.pop();
      int preLast = stack.pop();
      if (c == '+') stack.push(preLast + last);
      else if (c == '-') stack.push(preLast - last);
      else if (c == '*') stack.push(preLast * last);
      else if (c == '/') stack.push(preLast / last);
    }
  }
  return stack.top();
}
