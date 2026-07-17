#include "RPN.hpp"
#include <stack>
#include <list>
#include <sstream>
#include <iostream>
#include <cstdlib>

RPN::RPN() {}
RPN::RPN(RPN const &) {}
RPN &RPN::operator=(RPN const &) { return *this; }
RPN::~RPN() {}

int RPN::evaluate(std::string const &expr)
{
	std::stack<int, std::list<int> > s;
	std::stringstream ss(expr);
	std::string tok;

	while (ss >> tok)
	{
		if (tok.size() == 1 && (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/'))
		{
			if (s.size() < 2)
				throw std::runtime_error("Error");

			int b = s.top(); s.pop();
			int a = s.top(); s.pop();

			switch (tok[0])
			{
				case '+': s.push(a + b); break;
				case '-': s.push(a - b); break;
				case '*': s.push(a * b); break;
				case '/':
					if (b == 0) throw std::runtime_error("division by zero");
					s.push(a / b);
					break;
			}
		}
		else
		{
			std::stringstream ts(tok);
			int num;
			ts >> num;
			if (ts.fail() || !ts.eof() || num >= 10 || num < 0)
				throw std::runtime_error("Error");
			s.push(num);
		}
	}

	if (s.size() != 1)
		throw std::runtime_error("Error");

	return s.top();
}
