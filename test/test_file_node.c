#include "display_tree.h"

#include "stdio.h"
#include "assert.h"


void test_file_node_add_match_node() {
    MatchNode* mn1 = match_node_new("oferqjfw", 123, false);
    MatchNode* mn2 = match_node_new("oferqjfw", 124, true);
    MatchNode* mn3 = match_node_new("oferqjfw", 125, false);
    FileNode* fn1 = file_node_new("filenote1.txt");

    file_node_add_match_node(fn1, mn1);
    file_node_add_match_node(fn1, mn2);
    file_node_add_match_node(fn1, mn3);

    assert(fn1->match_nodes[0]->line_number == 123);
    assert(fn1->match_nodes[1]->line_number == 124);
    assert(fn1->match_nodes[2]->line_number == 125);
}

int main() {
    test_file_node_add_match_node();
    return 0;
}