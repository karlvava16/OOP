#pragma once
#include <string>

struct Node
{
    std::string m_english;
    std::string m_russian;

	Node* m_parent;

    Node* m_left;  
    Node* m_right;
	

    const char* GetEnglish();
    const char* GetRussian();
};