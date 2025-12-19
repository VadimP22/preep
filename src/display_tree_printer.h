#pragma once

#include "display_tree.h"

typedef struct DisplayTreePrinter {
    int current_indent;

    DirectoryNode* root_node;
} DisplayTreePrinter;

DisplayTreePrinter* new_display_tree_printer();

void display_tree_printer_set_root(DisplayTreePrinter*, DirectoryNode*);
void display_tree_printer_print(DisplayTreePrinter*);

void match_node_print(MatchNode*);
void file_node_print(FileNode*);