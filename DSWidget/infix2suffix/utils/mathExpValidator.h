#ifndef MATHEXPVALIDATOR_H
#define MATHEXPVALIDATOR_H

#include <vector>
#include <string>
#include <utility>

class mathExpValidator
{
private:
    std::vector< std::pair< std::string, int> > word;
    int sym;
    int err;
    int idx;
    void clear();
    void Next();
    void E();   // E → T { +T | -T } 
    void T();   // T → F { *F | /F } 
    void F();   // F → (E) | d


public:
    mathExpValidator(/* args */);
    ~mathExpValidator();
    
    bool word_analysis(const std::string expr);
    bool isValid(const std::string expr);
    std::vector<std::string> getWordList();
};

#endif // MATHEXPVALIDATOR_H
