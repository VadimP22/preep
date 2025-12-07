#include "display_tree.h"
#include "display_tree_printer.h"

#include "stdio.h"

int main() {
    MatchNode* mn1 = match_node_new("oferqjfw", 123, false);
    MatchNode* mn2 = match_node_new("oferqjfw", 124, true);
    MatchNode* mn3 = match_node_new("oferqjfw", 125, false);
    FileNode* fn1 = file_node_new("filenote1.txt");

    printf("before\n");

    file_node_add_match_node(fn1, mn1);
    file_node_add_match_node(fn1, mn2);
    file_node_add_match_node(fn1, mn3);

    printf("after\n");

    file_node_print(fn1);
    printf("\n");
    match_node_print(fn1->match_nodes[0]);
    printf("\n");
    match_node_print(fn1->match_nodes[1]);
    printf("\n");
    match_node_print(fn1->match_nodes[2]);
    printf("\n");
    return 0;
}
