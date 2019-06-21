#include "mathExpValidator.h"

mathExpValidator::mathExpValidator() {
    clear();
}

mathExpValidator::~mathExpValidator() {
}

void mathExpValidator::clear() {
    word.clear();
    err = 0;
    idx = 0;
    sym = 0;
}

bool mathExpValidator::word_analysis(const std::string expr) {
    clear();
    for(std::size_t i = 0; i < expr.length(); ++i)
	{
		// 如果是 + - * / ( )
		if(expr[i] == '(' || expr[i] == ')' || expr[i] == '+' 
			|| expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
		{
			std::string tmp;
			tmp.push_back(expr[i]);
			switch (expr[i])
			{
			case '+':
				word.push_back(std::make_pair(tmp, 1));
				break;
			case '-':
				word.push_back(std::make_pair(tmp, 2));
				break;
			case '*':
				word.push_back(std::make_pair(tmp, 3));
				break;
			case '/':
				word.push_back(std::make_pair(tmp, 4));
				break;
			case '(':
				word.push_back(std::make_pair(tmp, 6));
				break;
			case ')':
				word.push_back(std::make_pair(tmp, 7));
				break;
			}
		}
		// 如果是数字开头
		else if(expr[i]>='0' && expr[i]<='9')
		{
			std::string tmp;
			while(expr[i]>='0' && expr[i]<='9')
			{
				tmp.push_back(expr[i]);
				++i;
			}
			if(expr[i] == '.')
			{
				++i;
				if(expr[i]>='0' && expr[i]<='9')
				{
					tmp.push_back('.');
					while(expr[i]>='0' && expr[i]<='9')
					{
						tmp.push_back(expr[i]);
						++i;
					}
				}
				else  
				{
					return false;  // .后面不是数字，词法错误
				}
			}
			word.push_back(std::make_pair(tmp, 5));
			--i;
		}
		// 如果以.开头
		else  
		{
			return false;  // 以.开头，词法错误
		}
	}
	return true;
}

void mathExpValidator::Next()
{
    if(idx < static_cast<int>(word.size()))
		sym = word[idx++].second;
	else
		sym = 0;
}
 
// E → T { +T | -T } 
void mathExpValidator::E()
{
	T();
	while(sym == 1 || sym == 2)
	{
		Next();
		T();
	}
}
 
// T → F { *F | /F } 
void mathExpValidator::T()
{
	F();
	while(sym == 3 || sym == 4)
	{
		Next();
		F();
	}
}
 
// F → (E) | d
void mathExpValidator::F()
{
	if (sym == 5)
	{
		Next();
	}
	else if(sym == 6)
	{
		Next();
		E();
		if (sym == 7)
		{
			Next();
		}
		else
		{
			err = -1;
		}
	}
	else
	{
		err = -1;
	}
}

bool mathExpValidator::isValid(const std::string expr) {
    bool word_anly = word_analysis(expr);
    if (!word_anly) {
        return false;
    }
    else {
        Next();
	    E();
    
        // 注意要判断两个条件
        if (sym == 0 && err == 0) {
            return true;
        } 
        else {
            return false;
        }
    }
}

std::vector<std::string> mathExpValidator::getWordList() {
    std::vector<std::string> word_list;
    std::vector<std::pair<std::string, int>>::iterator beg = word.begin();
    for (; beg != word.end(); ++beg) {
        word_list.push_back(beg->first);
    }
    return word_list;
}
