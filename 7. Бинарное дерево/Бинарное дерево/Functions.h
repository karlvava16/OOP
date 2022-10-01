#pragma once
#include <fstream>
#include "Tree.h"

void Insert(Tree& tree);
void Print(const Tree& tree);
void PrintMenu();
void Remove(Tree& tree);
void Search(const Tree& tree);
void Edit(Tree& tree);
void STF(std::ofstream& of, const Node* node);
void SaveToFile(const Tree& tree);