#include "display_tree.h"
#include "display_tree_printer.h"

#include "stdio.h"

int main() {
    MatchNode* mn1 = match_node_new("oferqjfw", 123, false);
    MatchNode* mn2 = match_node_new("oferqjfw", 124, true);
    MatchNode* mn3 = match_node_new("oferqjfw", 125, false);
    FileNode* fn1 = file_node_new("filenote1.txt");

    file_node_print(fn1);
    printf("\n");
    match_node_print(mn1);
    printf("\n");
    match_node_print(mn2);
    printf("\n");
    match_node_print(mn3);
    printf("\n");
    return 0;
}
